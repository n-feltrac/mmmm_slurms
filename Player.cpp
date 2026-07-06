#include "Player.h"

Player::Player() {
    spriteWidth = 24;
    spriteHeight = 24;
    // spriteWidthTotal = totalWidth; //ehhhh should be fine i wont use a tile out of bounds
    texture.loadFromFile("mm.png");
    rectSourceSprite = IntRect(324, 21, spriteHeight, spriteWidth);
    sprite.setTexture(texture);
    sprite.setTextureRect(rectSourceSprite);
    sprite.setOrigin(spriteWidth/2, spriteHeight/2); // so scaling the sprite for directions doesnt screw up
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
    for(int i = 0; i < rm->tiles.size(); i++) {
        if(hitbox.intersects(rm->tiles[i]->getHitBox()) && rm->tiles[i]->spriteNum >= 1) {
            
            rm->tiles[i]->updateSprite("placeholder.png");
            // DO COLLISION DETECTION here WITH HITBOX
            // left and right (x)
            // only check one side is inside, since mm sprite is bigger than 16px
            // if rightside greater than lefttile, and less than righttile, push back to left
            // if leftside greater than lefttile, and less than righttile, push back to right

 
            if(hitbox.left > rm->tiles[i]->returnBound("left") && hitbox.left < rm->tiles[i]->returnBound("right")) {
                position.x = rm->tiles[i]->returnBound("right") + spriteWidth/2;
            } else if(hitbox.left + spriteWidth > rm->tiles[i]->returnBound("left") && hitbox.left + spriteWidth < rm->tiles[i]->returnBound("right")) {
                position.x = rm->tiles[i]->returnBound("left") - spriteWidth/2;
            }

            // if less than right and more than left, CHECK DIRECTION and push back that way, set x to right() or left()
            // up and down (y)
            // check if JUMPING, no, jumping is true until touching floor, how will we know if floor is touched?
            // if jumping and canjump is no
            // check if falling or not, if falling then player is above, if jumping then player is below
            // if(position.y > rm->tiles[i]->returnBound("top") && position.y < rm->tiles[i]->returnBound("bottom")) {
            //     if(falling == true) { // falling and hit ground, need to be on top of tile
            //         position.y = rm->tiles[i]->returnBound("top");
            //         falling = false;
            //         if(!Keyboard::isKeyPressed(Keyboard::Up)) {
            //             canJump = true;
            //         }
            //     } else if(falling == false) { // jumping, falling is false, need to stay on bottom
            //         position.y = rm->tiles[i]->returnBound("bottom");
            //         canJump = false;
            //         falling = true;
            //         Dy = 0;
            //     }
            // } else {
            //     position.y += Dy; // keep falling
            // }
        }
    }
    // if(position.y + Dy >= 100) { // arbitrary floor for now
    //     position.y = 100;
    //     Dy = 0;
    //     falling = false; // ?? is this where i need to do this? i think so
    //     if(!Keyboard::isKeyPressed(Keyboard::Up)) {
    //         canJump = true;
    //     }
    // } 



    // if(clk.getElapsedTime().asMicroseconds() >= 0.2) {
        sprite.setPosition(position.x, position.y);
        hitbox = sprite.getGlobalBounds(); // PLEASE ALWAYS REMEMBER TO UPDATE THIS!!!!!!!!
    // }

    window.draw(sprite);
}

void Player::move(int direction) { // direction is 1 for right or -1 for left
    Dx = speed * direction; // ?
    if(dir != direction) {
        sprite.scale(-1, 1);
        dir = direction;
    }
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
