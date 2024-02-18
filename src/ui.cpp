#include "ui.hpp"

UI::UI(u32 width, u32 height, u32 fps, std::string title)
    : window(sf::VideoMode(width, height), title) {
    window.setFramerateLimit(fps);
}

void UI::handle_events() {
    sf::Event event;

    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                cout << "Key pressed: " << event.key.code << endl;

                if (event.key.code == sf::Keyboard::Q) {
                    window.close();
                }

                break;

            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    cout << "mouse x: " << event.mouseButton.x << endl;
                    cout << "mouse y: " << event.mouseButton.y << endl;
                }

                break;

            default:
                break;
        }
    }
}

void UI::render(std::vector<Particle>& particles) {
    static u32 x = 100;

    handle_events();
    window.clear(BACKGROUND_COLOR);

    // Create a render texture
    sf::RenderTexture fluid_texture;
    if (!fluid_texture.create(window.getSize().x, window.getSize().y)) {
        ERROR_CREATING_RENDER_TEXTURE();
    }
    fluid_texture.clear(BACKGROUND_COLOR);

    // Draw particles
    for (auto& p : particles) {
        sf::CircleShape circle(p.get_r());
        circle.setFillColor(sf::Color::Cyan);
        circle.setPosition(p.get_x(), p.get_y());

        fluid_texture.draw(circle);
    }
    fluid_texture.display();

    sf::Sprite sprite(fluid_texture.getTexture());
    window.draw(sprite);

    window.display();
}

bool UI::is_open() { return window.isOpen(); }
