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

// g++ -c main.cpp GameObject.cpp Tile.cpp Room.cpp Player.cpp && g++ main.o GameObject.o Tile.o Room.o Player.o -lsfml-graphics -lsfml-window -lsfml-system && ./a.out

int main() {
    RenderWindow window(VideoMode(WINWIDTH, WINHEIGHT), "gugga");

    Clock rClock;

    Player* rock = new Player();
    // Tile* til = new Tile("tiles.png", 3, 16, 0);

    Room* rm = new Room("rooms/one.rm", "tilescut.png");

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed/*  || Keyboard::isKeyPressed(Keyboard::Z) */) {
                window.close();
            }
        }
        window.clear();


        if(rClock.getElapsedTime().asMicroseconds() >= 1.0) {
            rClock.restart();
        }

        // til->update(window);
        rm->update(window);

        rock->update(window, rClock);

        window.display();
    }

    return 0;
}
