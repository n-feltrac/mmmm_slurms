#include "Player.h"

Player::Player() {

}

void Player::update(RenderWindow &window) {
    window.draw(sprite);
}
