#include "Player.hpp"

Player::Player() {
	this->player.setSize(sf::Vector2f(this->width, this->height));
	this->player.setFillColor(sf::Color::White);

	this->posX = 1280.f - this->width;
	this->posY = 720.f / 2 - this->height / 2;
}

void Player::update_pos() {
	this->player.setPosition(this->posX, this->posY);
}

void Player::movement() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		this->posY -= 5.f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		this->posY += 5.f;
	}
}

void Player::check_wall_collision() {
	if (this->posY <= 0.f) {
		this->posY = 0.f;
	}
	else if (this->posY >= 720.f - this->height) {
		this->posY = 720.f - this->height;
	}
}