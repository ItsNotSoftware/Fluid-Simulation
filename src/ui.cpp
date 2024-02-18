#include <ui.hpp>

UI::UI(u32 width, u32 height, u32 fps, std::string title)
    : window(sf::VideoMode(width, height), title) {
    window.setFramerateLimit(fps);

    // Add particles
    for (u32 i = 1; i < window.getSize().x / (PARTICLE_SIZE * 2) - 1; i++) {
        for (u32 j = 1; j < window.getSize().y / (PARTICLE_SIZE * 4) - 2; j++) {
            add_particle(PARTICLE_TEXTURE_SIZE, i * PARTICLE_SIZE * 2,
                         window.getSize().y - j * PARTICLE_SIZE * 2);
        }
    }
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

void UI::render() {
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
        fluid_texture.draw(p);
    }
    fluid_texture.display();

    sf::Sprite sprite(fluid_texture.getTexture());
    window.draw(sprite);

    window.display();
}

bool UI::is_open() { return window.isOpen(); }

void UI::add_particle(u32 size, u32 x, u32 y, sf::Color color) {
    sf::CircleShape particle(size);
    particle.setFillColor(color);
    particle.setPosition(x, y);

    particles.push_back(particle);
}

void UI::change_particle_position(u32 index, u32 x, u32 y) { particles[index].setPosition(x, y); }