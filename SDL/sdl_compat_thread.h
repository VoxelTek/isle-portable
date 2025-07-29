#pragma once

#ifdef ISLE_SDL2

#include "sdl_compat_mutex.h"
#include "sdl_compat_stdinc.h"

#include <SDL2/SDL_thread.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

#else
#include <SDL3/SDL_thread.h>
#endif
