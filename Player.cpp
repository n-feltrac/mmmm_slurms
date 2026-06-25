#include "Player.h"

Player::Player() {
    spriteWidth = 24;
    spriteHeight = 24;
    // spriteWidthTotal = totalWidth; //ehhhh should be fine i wont use a tile out of bounds
    texture.loadFromFile("mm.png");
    rectSourceSprite = IntRect(1, 21, spriteHeight, spriteWidth);
    sprite.setTexture(texture);
    sprite.setTextureRect(rectSourceSprite);
    sprite.setOrigin(0, 0);
    position = Vector2f(50, 50); // need to call constructor when setting vector2f coords for x AND y
    sprite.setPosition(position); // also set position in constructor and include as parameters
    // sprite.scale(1, 1); // this and position should be parameters in constructor
    hitbox = sprite.getGlobalBounds();

}

void Player::update(RenderWindow &window, Clock clk, Room* rm) {
    position = sprite.getPosition();

    // movement
    if(Keyboard::isKeyPressed(Keyboard::Left)) {
        move(-1);
    } else if(Keyboard::isKeyPressed(Keyboard::Right)) {
        move(1);
    } else {
        Dx = 0;
    }
    // jump
    if(Keyboard::isKeyPressed(Keyboard::Up)) {
        jump();
    } else { // if button not pressed,
        if(falling) { // but still jumping,
            if(Dy < 0) { // and y velocity is going up,
                Dy = 0; // limit height of jump
            }
        } else {
            canJump = true;
        }
    }
    // setting position
    Dy += gravity;
    
    position.x += Dx;
    for(Tile* t : rm->tiles) {
        if(hitbox.intersects(t->getHitBox()) && t->spriteNum >= 1) {
            cout << "touching a thing" << endl;
        }
    }
    if(position.y + Dy >= 100) { // arbitrary floor for now
        position.y = 100;
        Dy = 0;
        if(!Keyboard::isKeyPressed(Keyboard::Up)) {
            canJump = true;
        }
    } else {
        position.y += Dy;
    }

    // if(clk.getElapsedTime().asMicroseconds() >= 0.2) {
        sprite.setPosition(position.x, position.y);
    // }

    window.draw(sprite);
}
/////////////////I NEED EVERYTHING TO BE 60FPS because the speed keeps varying and its annoying me
void Player::move(int direction) { // direction is 1 for right or -1 for left
    Dx = speed * direction; // ?
    // cout << Dx << endl;
    // sprite.setPosition(position.x + Dx, position.y);
}

void Player::jump() {
    if(canJump) {
        // cout << "can jump" << endl;
        Dy = -jumpHeight;
        canJump = false;
        falling = true;
    }
}
