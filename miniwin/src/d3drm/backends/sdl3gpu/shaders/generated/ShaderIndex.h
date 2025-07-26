#pragma once

// clang-format off

// +==============================================+
// | This file is auto-generated, do not edit it. |
// +==============================================+

#ifdef ISLE_SDL2
#include "sdl_compat.h"
#else
#include <SDL3/SDL.h>
#endif

enum VertexShaderId {
  PositionColor,
};

enum FragmentShaderId {
  SolidColor,
};

const SDL_GPUShaderCreateInfo* GetVertexShaderCode(VertexShaderId id, SDL_GPUShaderFormat formats);

const SDL_GPUShaderCreateInfo* GetFragmentShaderCode(FragmentShaderId id, SDL_GPUShaderFormat formats);

