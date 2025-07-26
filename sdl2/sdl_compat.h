#pragma once

#include <SDL2/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif


//Functions that don't exist in SDL2
void SDL_LogTrace(int category, SDL_PRINTF_FORMAT_STRING const char *fmt, ...) SDL_PRINTF_VARARG_FUNC(2);
SDL_Palette * SDL_CreatePalette(int ncolors);
void SDL_DestroyPalette(SDL_Palette *palette);
SDL_Surface * SDL_CreateSurface(int width, int height, SDL_PixelFormat format);
void SDL_DestroySurface(SDL_Surface *surface);


#define SDL_SetWindowBordered SDL2_SDL_SetWindowBordered
#define SDL_SetWindowResizable SDL2_SDL_SetWindowResizable
#define SDL_GetWindowSize SDL2_SDL_GetWindowSize
#define SDL_GetCurrentDisplayMode SDL2_SDL_GetCurrentDisplayMode


#ifdef __cplusplus
}
#endif
