#include <SFML/Graphics.hpp>
#include <common.hpp>
#include <ui.hpp>

int main() {
    UI ui(900, 600, 60, "flsim");

    while (ui.is_open()) {
        ui.render();
    }

    return 0;
}
