#include "GameObject.h"

GameObject::GameObject() {
}

void GameObject::spriteAnimate(int totalWidth, int width) {
    if(rectSourceSprite.left == totalWidth - width) {
        rectSourceSprite.left = 0;
    } else {
        rectSourceSprite.left += width;
    }
    sprite.setTextureRect(rectSourceSprite);
}

void GameObject::update(RenderWindow &window) {
    if(clock.getElapsedTime().asSeconds() > 0.15f) {
        // spriteAnimate(spriteWidthTotal, spriteWidthBox);
        clock.restart();
    }

    window.draw(sprite);
}

Vector2f GameObject::getPosition() {
    return position;
}

Texture GameObject::getTexture() {
    return texture;
}

Sprite GameObject::getSprite() {
    return sprite;
}

IntRect GameObject::getSpriteRect() {
    return rectSourceSprite;
}

void GameObject::setPosition(Vector2f newPosition) {
    sprite.setPosition(newPosition);
}

// ~GameObject() definition is in the .h file
