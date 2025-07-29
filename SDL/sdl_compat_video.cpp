#ifdef ISLE_SDL2
#include "sdl_compat_video.h"

bool SDL2_SDL_SetWindowBordered(SDL_Window* window, bool bordered)
{
	return SDL_SetWindowBordered(window, SDL_Bool(bordered ? SDL_TRUE : SDL_FALSE));
}

bool SDL2_SDL_SetWindowResizable(SDL_Window* window, bool resizable)
{
	return SDL_SetWindowResizable(window, SDL_Bool(resizable ? SDL_TRUE : SDL_FALSE));
}

bool SDL2_SDL_GetWindowSize(SDL_Window* window, int* w, int* h)
{
	CHECK_WINDOW_MAGIC(window, false);
	SDL_GetWindowSize(window, w, h);
	return true;
}

const SDL_DisplayMode* SDL2_SDL_GetCurrentDisplayMode(SDL_DisplayID displayID)
{
	SDL_DisplayMode mode;
	if (SDL_GetCurrentDisplayMode(displayID, mode)) {
		return mode;
	}
	else {
		return NULL;
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

SDL_DisplayMode** SDL_GetFullscreenDisplayModes(SDL_DisplayID displayID, int* count)
{
	int i;
	int num_modes;
	SDL_DisplayMode** result;
	SDL_VideoDisplay* display = SDL_GetVideoDisplay(displayID);

	if (count) {
		*count = 0;
	}

	CHECK_DISPLAY_MAGIC(display, NULL);

	SDL_UpdateFullscreenDisplayModes(display);

	num_modes = display->num_fullscreen_modes;
	result = (SDL_DisplayMode**) SDL_malloc((num_modes + 1) * sizeof(*result) + num_modes * sizeof(**result));
	if (result) {
		SDL_DisplayMode* modes = (SDL_DisplayMode*) ((Uint8*) result + ((num_modes + 1) * sizeof(*result)));
		SDL_memcpy(modes, display->fullscreen_modes, num_modes * sizeof(*modes));
		for (i = 0; i < num_modes; ++i) {
			result[i] = modes++;
		}
		result[i] = NULL;

		if (count) {
			*count = num_modes;
		}
	}
	else {
		if (count) {
			*count = 0;
		}
	}
	return result;
}
#endif
