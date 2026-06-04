#ifndef TILE_H
#define TILE_H

#include "GameObject.h"

using namespace sf;
using namespace std;

class Tile : GameObject {
    public:
        Tile(string tex, int tileNum);
        void update(RenderWindow &window);

    protected:
        int spriteHeight; // kinda obsolete
        int spriteWidth; // 16x16 tile
        int spriteWidthTotal; // total spritesheet size
};

#endif