#include "Bot.hpp"

Bot::Bot() {
	this->bot.setSize(sf::Vector2f(this->width, this->height));
	this->bot.setFillColor(sf::Color::Blue);

	this->posX = 0.f;
	this->posY = 720.f / 2.f - this->height / 2.f;
}

void Bot::update_pos() {
	this->bot.setPosition(this->posX, this->posY);
}

void Bot::check_wall_collision() {
	if (this->posY <= 0.f) {
		this->posY = 0.f;
	}
	else if (this->posY >= 720.f - this->height) {
		this->posY = 720.f - this->height;
	}
}

void Bot::play(Ball ball) {
	this->posY = ball.get_posY() - this->offset;
}

