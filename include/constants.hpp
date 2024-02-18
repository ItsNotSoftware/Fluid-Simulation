#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include "common.hpp"

// Particles
constexpr f32 PARTICLE_R = 10;
constexpr f32 COLISION_DAMPING = 0.70;

// UI
constexpr u32 SCREEN_WIDTH = 900;
constexpr u32 SCREEN_HEIGHT = 600;
constexpr f32 FPS = 30.0f;
constexpr f32 DT = 1.0f / FPS;
constexpr f32 BORDER = 4 * PARTICLE_R;

constexpr f32 G = 400.0f;

#endif