#pragma once

#include "sdl_compat.h"

#include <stdint.h>

typedef float Matrix3x3[3][3];

struct FColor {
	float r, g, b, a;
};

struct Appearance {
	SDL_Color color;
	float shininess;
	uint32_t textureId;
	uint32_t flat;
};

struct ViewportTransform {
	float scale;
	float offsetX;
	float offsetY;
};
