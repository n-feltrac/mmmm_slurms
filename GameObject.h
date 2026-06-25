#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace sf;
using namespace std;

class GameObject {
    public:
        GameObject();
        void spriteAnimate(int totalWidth, int width);
        virtual void update(RenderWindow &window);
        Vector2f getPosition();
        Texture getTexture();
        Sprite getSprite();
        IntRect getSpriteRect();
        void setPosition(Vector2f newPosition);
        virtual ~GameObject() { cout << "destroyed" << endl; };
        FloatRect hitbox;
        Texture texture;
        IntRect rectSourceSprite;
        Sprite sprite;
        Clock clock;
        Vector2f position;
    protected:
        
};

#endif