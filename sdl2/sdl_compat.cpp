#include "sdl_compat.h"

bool SDL2_SDL_SetWindowBordered(SDL_Window *window, bool bordered) {
	return SDL_SetWindowBordered(window, SDL_Bool(bordered ? SDL_TRUE : SDL_FALSE));
}

bool SDL2_SDL_SetWindowResizable(SDL_Window *window, bool resizable) {
	return SDL_SetWindowResizable(window, SDL_Bool(resizable ? SDL_TRUE : SDL_FALSE));
}
