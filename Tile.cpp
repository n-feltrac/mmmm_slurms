#include "Tile.h"

Tile::Tile(string tex, int tileNum, int posX, int posY) {
    spriteWidth = 16;
    spriteHeight = 16;
    // spriteWidthTotal = totalWidth; //ehhhh should be fine i wont use a tile out of bounds
    texture.loadFromFile(tex);
    rectSourceSprite = IntRect(tileNum*16, 0, spriteHeight, spriteWidth);
    sprite.setTexture(texture);
    sprite.setTextureRect(rectSourceSprite);
    sprite.setOrigin(0, 0);
    position = Vector2f(posX, posY); // need to call constructor when setting vector2f coords for x AND y
    sprite.setPosition(position); // also set position in constructor and include as parameters
    // sprite.scale(1, 1); // this and position should be parameters in constructor
    hitbox = sprite.getGlobalBounds();
}

void Tile::update(RenderWindow &window) {
    window.draw(sprite);
}
