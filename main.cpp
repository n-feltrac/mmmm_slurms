#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "GameObject.h"
#include "Room.h"
#include "Tile.h"

using namespace sf;
using namespace std;

#define WINWIDTH  256
#define WINHEIGHT 224

// g++ -c main.cpp GameObject.cpp Tile.cpp Room.cpp && g++ main.o GameObject.o Tile.o Room.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system && ./sfml-app

int main() {
    RenderWindow window(VideoMode(WINWIDTH, WINHEIGHT), "gugga");

    // Player* zero = new Player(0.3, "zero_idle.png", 34, 41, 204);
    // Tile* til = new Tile("tiles.png", 3, 16, 0);

    Room* rm = new Room("rooms/one.rm", "tiles.png");

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed/*  || Keyboard::isKeyPressed(Keyboard::Z) */) {
                window.close();
            }
        }
        window.clear();

        // til->update(window);

        rm->update(window);

        // zero->update(window);

        window.display();
    }

    return 0;
}
