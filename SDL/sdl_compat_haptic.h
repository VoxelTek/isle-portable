#pragma once

#ifdef ISLE_SDL2

#include "sdl_compat_joystick.h"
#include "sdl_compat_stdinc.h"

#include <SDL2/SDL_haptic.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

#else
#include <SDL3/SDL_haptic.h>
#endif
