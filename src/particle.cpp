#include "particle.hpp"

Particle::Particle(f32 x, f32 y, f32 r) : position(Vec2(x, y)), r(r), velocity(0.0, 0.0) {}

f32 Particle::get_x() { return position.x; }
f32 Particle::get_y() { return position.y; }
f32 Particle::get_r() { return r; }

void Particle::apply_gravity(f32 dt) { velocity.y += G * dt; }
void Particle::update_position(f32 dt) {
    position += velocity * dt;

    // Handle colision with the botto of the screen
    if (position.y >= SCREEN_HEIGHT - BORDER) {
        position.y = SCREEN_HEIGHT - BORDER;
        velocity.y *= -COLISION_DAMPING;
    }
}
