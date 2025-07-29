#ifdef ISLE_SDL2
#include "sdl_compat_log.h"

void SDL_LogTrace(int category, SDL_PRINTF_FORMAT_STRING const char* fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	SDL_LogMessageV(category, SDL_LOG_PRIORITY_TRACE, fmt, ap);
	va_end(ap);
}

#endif
