#pragma once

#ifdef ISLE_SDL2

#include "sdl_compat_stdinc.h"

#include <SDL2/SDL_timer.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

#else
#include <SDL3/SDL_timer.h>
#endif
