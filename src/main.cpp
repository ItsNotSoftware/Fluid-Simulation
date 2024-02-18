#include <SFML/Graphics.hpp>
#include <common.hpp>
#include <ui.hpp>

int main() {
    UI ui(900, 600, 60, "SFML Example");

    while (ui.is_open()) {
        ui.render();
    }

    ui.render();
    return 0;
}
