#ifndef TILE_H
#define TILE_H

#include "GameObject.h"

using namespace sf;
using namespace std;

class Tile : GameObject {
    public:
        Tile(string tex, int tileNum, int posX, int posY);
        void update(RenderWindow &window);
        int spriteHeight; // kinda obsolete
        int spriteWidth; // 16x16 tile
        int spriteWidthTotal; // total spritesheet size
        FloatRect getHitBox();
        int spriteNum;
        void updateSprite(string path);
        float returnBound(string dir);
    protected:
        
};

#endif