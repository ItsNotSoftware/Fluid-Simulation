#include <SFML/Graphics.hpp>
#include <chrono>

#include "common.hpp"
#include "constants.hpp"
#include "particle.hpp"
#include "ui.hpp"

void generate_particles(std::vector<Particle>& particles) {
    u32 gap = PARTICLE_R * 2.5;
    for (u32 x = gap; x < SCREEN_WIDTH - gap; x += gap) {
        for (u32 y = gap; y < SCREEN_HEIGHT - gap; y += gap) {
            if (rand() % 10 == 0) {
                particles.push_back(Particle(x, y, PARTICLE_R));
            }
        }
    }
}

int main() {
    UI ui(SCREEN_WIDTH, SCREEN_HEIGHT, FPS, "flsim");

    std::vector<Particle> particles;
    generate_particles(particles);

    while (ui.is_open()) {
        for (auto& p : particles) {
            p.apply_gravity(DT);
            p.update_position(DT);
        }

        ui.render(particles);
    }

    return 0;
}
