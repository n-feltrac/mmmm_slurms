#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

using namespace sf;
using namespace std;

class Player : GameObject {
    public:
        Player();
        void update(RenderWindow &window);

    protected:
        int spriteHeight; // kinda obsolete
        int spriteWidth; // 16x16 tile
        int spriteWidthTotal; // total spritesheet size
};

#endif