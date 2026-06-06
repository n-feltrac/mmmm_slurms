#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "GameObject.h"
#include "Room.h"
#include "Tile.h"
#include "Player.h"

using namespace sf;
using namespace std;

#define WINWIDTH  256
#define WINHEIGHT 224

// g++ -c main.cpp GameObject.cpp Tile.cpp Room.cpp && g++ main.o GameObject.o Tile.o Room.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system && ./sfml-app

int main() {
    RenderWindow window(VideoMode(WINWIDTH, WINHEIGHT), "gugga");

    Player* rock = new Player();
    // Tile* til = new Tile("tiles.png", 3, 16, 0);

    // Room* rm = new Room("rooms/one.rm", "tilescut.png");

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed/*  || Keyboard::isKeyPressed(Keyboard::Z) */) {
                window.close();
            }
        }
        window.clear();

        // til->update(window);

        // rm->update(window);

        rock->update(window);

        window.display();
    }

    return 0;
}
