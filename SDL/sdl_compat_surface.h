#pragma once

#ifdef ISLE_SDL2

#include "sdl_compat_stdinc.h"

#include <SDL2/SDL_surface.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define SDL_BlitSurfaceScaled SDL_BlitScaled
#define SDL_FillSurfaceRect SDL_FillRect
#define SDL_SetSurfaceColorKey SDL_SetColorKey
#define SDL_ConvertSurface SDL_ConvertSurfaceFormat

#ifdef __cplusplus
}
#endif

#else
#include <SDL3/SDL_surface.h>
#endif
