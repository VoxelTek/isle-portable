#pragma once

#include <SDL2/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

bool SDL2_SDL_SetWindowBordered(SDL_Window *window, bool bordered);
bool SDL2_SDL_SetWindowResizable(SDL_Window *window, bool resizable);

#define SDL_SetWindowBordered SDL2_SDL_SetWindowBordered
#define SDL_SetWindowResizable SDL2_SDL_SetWindowResizable

#ifdef __cplusplus
}
#endif
