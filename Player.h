#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

using namespace sf;
using namespace std;

class Player : GameObject {
    public:
        Player();
        void update(RenderWindow &window);
        void move(int direction);
        void jump();
    protected:
        int spriteHeight; // kinda obsolete
        int spriteWidth; // 16x16 tile
        int spriteWidthTotal; // total spritesheet size
        //already has a position vector2f
        float speed = 0.2;
        float Dx = 0; // x velocity
        float Dy = 0; // y vel
        bool canJump = true;
        bool falling = false;
        int jumpHeight = 1;
        int gravity = 0;
        
};

#endif