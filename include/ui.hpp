#ifndef UI_HPP
#define UI_HPP

#include <SFML/Graphics.hpp>

#include "common.hpp"
#include "particle.hpp"

#define BACKGROUND_COLOR sf::Color::Black

#define ERROR_CREATING_RENDER_TEXTURE()                     \
    std::cerr << "Failed to create render texture" << endl; \
    exit(1)

class UI {
   public:
    UI(u32 width, u32 height, u32 fps, std::string title);

    bool is_open();
    void render(std::vector<Particle>& particles);

   private:
    sf::RenderWindow window;

    void handle_events();
};

#endif