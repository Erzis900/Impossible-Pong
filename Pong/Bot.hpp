#pragma once
#include <SFML\Graphics.hpp>
#include "Ball.hpp"

class Ball;
class Bot {
private:
	sf::RectangleShape bot;

	const float width = 25.f;
	const float height = 200.f;
	const float offset = 70.f;

	float posX, posY;
public:
	Bot();
	void update_pos();
	void check_wall_collision();
	void play(Ball ball);

	sf::RectangleShape get_shape() const {
		return this->bot;
	}

	float get_posY() {
		return this->posY;
	}
};

