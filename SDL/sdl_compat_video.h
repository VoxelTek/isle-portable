#pragma once

#ifdef ISLE_SDL2

#include "sdl_compat_stdinc.h"
#include "sdl_compat_surface.h"

#include <SDL2/SDL_video.h>

#ifdef __cplusplus
extern "C"
{
#endif

	// Types that don't exist in SDL2
	typedef Uint32 SDL_DisplayID;

	// Functions that exist, but not in the same way
	bool SDL2_SDL_SetWindowBordered(SDL_Window* window, bool bordered);
	bool SDL2_SDL_SetWindowResizable(SDL_Window* window, bool resizable);
	bool SDL2_SDL_GetWindowSize(SDL_Window* window, int* w, int* h);
	const SDL_DisplayMode* SDL2_SDL_GetCurrentDisplayMode(SDL_DisplayID displayID);

	// Functions that didn't exist in SDL2
	SDL_DisplayID SDL_GetPrimaryDisplay(void);
	SDL_DisplayMode** SDL_GetFullscreenDisplayModes(SDL_DisplayID displayID, int* count);

#define SDL_SetWindowBordered SDL2_SDL_SetWindowBordered
#define SDL_SetWindowResizable SDL2_SDL_SetWindowResizable
#define SDL_GetWindowSize SDL2_SDL_GetWindowSize
#define SDL_GetCurrentDisplayMode SDL2_SDL_GetCurrentDisplayMode

#ifdef __cplusplus
}
#endif

#else
#include <SDL3/SDL_video.h>
#endif
