#pragma once

#ifdef ISLE_SDL2

#include "sdl_compat_stdinc.h"

#include <SDL2/SDL_log.h>

#ifdef __cplusplus
extern "C"
{
#endif

	void SDL_LogTrace(int category, SDL_PRINTF_FORMAT_STRING const char* fmt, ...) SDL_PRINTF_VARARG_FUNC(2);

#ifdef __cplusplus
}
#endif

#else
#include <SDL3/SDL_log.h>
#endif
