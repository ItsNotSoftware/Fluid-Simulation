#ifndef UI_HPP
#define UI_HPP

#include <SFML/Graphics.hpp>
#include <common.hpp>

#define BACKGROUND_COLOR sf::Color::Black

constexpr f32 PARTICLE_SIZE = 5;
constexpr f32 PARTICLE_TEXTURE_SIZE = PARTICLE_SIZE - 0.1;

#define ERROR_CREATING_RENDER_TEXTURE()                     \
    std::cerr << "Failed to create render texture" << endl; \
    exit(1)

class UI {
   public:
    UI(u32 width, u32 height, u32 fps, std::string title);

    bool is_open();
    void render();
    void add_particle(u32 size, u32 x, u32 y, sf::Color color = sf::Color::Cyan);
    void change_particle_position(u32 index, u32 x, u32 y);

   private:
    sf::RenderWindow window;
    std::vector<sf::CircleShape> particles;

    void handle_events();
};

#endif