#pragma once

#ifdef ISLE_SDL2

#include <SDL2/SDL_events.h>
#include "sdl_compat_stdinc.h"
#include "sdl_compat_video.h"
#include "sdl_compat_keyboard.h"
#include "sdl_compat_joystick.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#else
#include <SDL3/SDL_events.h>
#endif
