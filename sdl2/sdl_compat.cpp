#include "sdl_compat.h"

bool SDL2_SDL_SetWindowBordered(SDL_Window *window, bool bordered) {
	return SDL_SetWindowBordered(window, SDL_Bool(bordered ? SDL_TRUE : SDL_FALSE));
}

bool SDL2_SDL_SetWindowResizable(SDL_Window *window, bool resizable) {
	return SDL_SetWindowResizable(window, SDL_Bool(resizable ? SDL_TRUE : SDL_FALSE));
}

bool SDL2_SDL_GetWindowSize(SDL_Window *window, int *w, int *h)
{
	CHECK_WINDOW_MAGIC(window, false);
    SDL_GetWindowSize(window, w, h);
    return true;
}

const SDL_DisplayMode * SDL2_SDL_GetCurrentDisplayMode(SDL_DisplayID displayID) {
	SDL_DisplayMode mode;
	if (SDL_GetCurrentDisplayMode(displayID, mode)) {
		return mode;
	}
	else {
		return NULL;
	}
}

void SDL_LogTrace(int category, SDL_PRINTF_FORMAT_STRING const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    SDL_LogMessageV(category, SDL_LOG_PRIORITY_TRACE, fmt, ap);
    va_end(ap);
}

SDL_Palette * SDL_CreatePalette(int ncolors) {
	SDL_Palette *palette;

	// Input validation
	if (ncolors < 1) {
		SDL_InvalidParamError("ncolors");
		return NULL;
	}

	palette = (SDL_Palette *)SDL_malloc(sizeof(*palette));
	if (!palette) {
		return NULL;
	}
	palette->colors = (SDL_Color *)SDL_malloc(ncolors * sizeof(*palette->colors));
	if (!palette->colors) {
		SDL_free(palette);
		return NULL;
	}
	palette->ncolors = ncolors;
	palette->version = 1;
	palette->refcount = 1;

	SDL_memset(palette->colors, 0xFF, ncolors * sizeof(*palette->colors));

	return palette;
}

void SDL_DestroyPalette(SDL_Palette *palette) {
	if (!palette) {
		return;
	}
	if (--palette->refcount > 0) {
		return;
	}
	SDL_free(palette->colors);
	SDL_free(palette);
}

SDL_Surface *SDL_CreateSurface(int width, int height, SDL_PixelFormat format) {
    size_t pitch, size;
    SDL_Surface *surface;

    if (width < 0) {
        SDL_InvalidParamError("width");
        return NULL;
    }

    if (height < 0) {
        SDL_InvalidParamError("height");
        return NULL;
    }

    if (format == SDL_PIXELFORMAT_UNKNOWN) {
        SDL_InvalidParamError("format");
        return NULL;
    }

    if (!SDL_CalculateSurfaceSize(format, width, height, &size, &pitch, false /* not minimal pitch */)) {
        // Overflow...
        return NULL;
    }

    // Allocate and initialize the surface
    surface = (SDL_Surface *)SDL_malloc(sizeof(*surface));
    if (!surface) {
        return NULL;
    }

    if (!SDL_InitializeSurface(surface, width, height, format, SDL_COLORSPACE_UNKNOWN, 0, NULL, (int)pitch, false)) {
        return NULL;
    }

    if (surface->w && surface->h && format != SDL_PIXELFORMAT_MJPG) {
        surface->flags &= ~SDL_SURFACE_PREALLOCATED;
        surface->pixels = SDL_aligned_alloc(SDL_GetSIMDAlignment(), size);
        if (!surface->pixels) {
            SDL_DestroySurface(surface);
            return NULL;
        }
        surface->flags |= SDL_SURFACE_SIMD_ALIGNED;

        // This is important for bitmaps
        SDL_memset(surface->pixels, 0, size);
    }
    return surface;
}

void SDL_DestroySurface(SDL_Surface *surface)
{
    if (!SDL_SurfaceValid(surface)) {
        return;
    }
    if (surface->internal_flags & SDL_INTERNAL_SURFACE_DONTFREE) {
        return;
    }
    if (--surface->refcount > 0) {
        return;
    }

    SDL_RemoveSurfaceAlternateImages(surface);

    SDL_DestroyProperties(surface->props);

    SDL_InvalidateMap(&surface->map);

    while (surface->locked > 0) {
        SDL_UnlockSurface(surface);
    }
#ifdef SDL_HAVE_RLE
    if (surface->internal_flags & SDL_INTERNAL_SURFACE_RLEACCEL) {
        SDL_UnRLESurface(surface, false);
    }
#endif
    SDL_SetSurfacePalette(surface, NULL);

    if (surface->flags & SDL_SURFACE_PREALLOCATED) {
        // Don't free
    } else if (surface->flags & SDL_SURFACE_SIMD_ALIGNED) {
        // Free aligned
        SDL_aligned_free(surface->pixels);
    } else {
        // Normal
        SDL_free(surface->pixels);
    }

    surface->reserved = NULL;

    if (!(surface->internal_flags & SDL_INTERNAL_SURFACE_STACK)) {
        SDL_free(surface);
    }
}

SDL_DisplayID SDL_GetPrimaryDisplay(void)
{
    if (!_this || _this->num_displays == 0) {
        SDL_UninitializedVideo();
        return 0;
    }
    return _this->displays[0]->id;
}

SDL_DisplayMode **SDL_GetFullscreenDisplayModes(SDL_DisplayID displayID, int *count)
{
    int i;
    int num_modes;
    SDL_DisplayMode **result;
    SDL_VideoDisplay *display = SDL_GetVideoDisplay(displayID);

    if (count) {
        *count = 0;
    }

    CHECK_DISPLAY_MAGIC(display, NULL);

    SDL_UpdateFullscreenDisplayModes(display);

    num_modes = display->num_fullscreen_modes;
    result = (SDL_DisplayMode **)SDL_malloc((num_modes + 1) * sizeof(*result) + num_modes * sizeof(**result));
    if (result) {
        SDL_DisplayMode *modes = (SDL_DisplayMode *)((Uint8 *)result + ((num_modes + 1) * sizeof(*result)));
        SDL_memcpy(modes, display->fullscreen_modes, num_modes * sizeof(*modes));
        for (i = 0; i < num_modes; ++i) {
            result[i] = modes++;
        }
        result[i] = NULL;

        if (count) {
            *count = num_modes;
        }
    } else {
        if (count) {
            *count = 0;
        }
    }
    return result;
}

