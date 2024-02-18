#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "common.hpp"
#include "constants.hpp"
#include "vec2.hpp"

class Particle {
   public:
    Particle(f32 x, f32 y, f32 r);

    f32 get_x();
    f32 get_y();
    f32 get_r();

    void apply_gravity(f32 dt);
    void update_position(f32 dt);

   private:
    Vec2 position;
    Vec2 velocity;
    f32 r;
};
#endif