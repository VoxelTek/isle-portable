#pragma once

#ifdef ISLE_SDL2

#include "sdl_compat_audio.h"
#include "sdl_compat_cpuinfo.h"
#include "sdl_compat_events.h"
#include "sdl_compat_filesystem.h"
#include "sdl_compat_haptic.h"
#include "sdl_compat_iostream.h"
#include "sdl_compat_joystick.h"
#include "sdl_compat_keyboard.h"
#include "sdl_compat_keycode.h"
#include "sdl_compat_log.h"
#include "sdl_compat_main.h"
#include "sdl_compat_mutex.h"
#include "sdl_compat_platform_defines.h"
#include "sdl_compat_process.h"
#include "sdl_compat_stdinc.h"
#include "sdl_compat_surface.h"
#include "sdl_compat_system.h"
#include "sdl_compat_thread.h"
#include "sdl_compat_timer.h"
#include "sdl_compat_video.h"

#include <SDL2/SDL.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define SDL_PixelFormatDetails SDL_PixelFormat

	// Functions that don't exist in SDL2
	SDL_Palette* SDL_CreatePalette(int ncolors);
	void SDL_DestroyPalette(SDL_Palette* palette);
	SDL_Surface* SDL_CreateSurface(int width, int height, SDL_PixelFormat format);
	void SDL_DestroySurface(SDL_Surface* surface);

	// #define SDL_PixelFormat SDL_PixelFormatEnum
	SDL_PixelFormat SDL_GetPixelFormatForMasks(int bpp, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask);

	// Remapping functions
	Uint32 SDL2_SDL_MapRGBA(
		const SDL_PixelFormatDetails* format,
		const SDL_Palette* palette,
		Uint8 r,
		Uint8 g,
		Uint8 b,
		Uint8 a
	);

// #define SDL_GetPixelFormatDetails SDL_AllocFormat
#define SDL_GetPixelFormatForMasks SDL_MasksToPixelFormatEnum
#define SDL_GetPixelFormatDetails(x) x
#define SDL_SCALEMODE_NEAREST SDL_ScaleModeNearest
#define bits_per_pixel BitsPerPixel
#define SDL_MapRGBA SDL2_SDL_MapRGBA

#ifdef __cplusplus
}
#endif

#else
#include <SDL3/SDL.h>
#endif
