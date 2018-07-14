#include "Ball.hpp"

Ball::Ball() : dist(1, 2) {
	this->ball.setRadius(this->radius);
	this->ball.setFillColor(sf::Color::Red);

	this->posX = 1280.f / 2.f - this->radius;
	this->posY = 720.f / 2.f - this->radius;

	this->random.seed(std::random_device()( ));
	this->dir = this->dist(random);
}

void Ball::update_pos() {
	this->ball.setPosition(this->posX, this->posY);
}

void Ball::movement() {
	switch (this->dir) {
		case 1:
			this->posX += this->velX;
			this->posY -= this->velY;
			break;
		case 2:
			this->posX += this->velX;
			this->posY += this->velY;
			break;
		default:
			break;
	}
}

void Ball::check_collision(Player player, Bot bot) {
	if (this->posY < 0.f || this->posY > 720.f - this->radius * 2) {
		this->velY *= -1.f;
	}

	else if (( this->posX >= 1195.f && this->posY > player.get_posY() && this->posY < player.get_posY() + 200 ) ||
		( this->posX <= 25.f && this->posY > bot.get_posY() && this->posY < bot.get_posY() + 200 )) {
		this->velX *= -1.f;
	}

	else if (this->posX > 1280.f || this->posX < 0.f) {
		this->posX = 1280.f / 2.f - this->radius;
		this->posY = 720.f / 2.f - this->radius;
		this->dir = this->dist(random);
		this->velX += 2.f;
		this->velY += 2.f;
	}
}