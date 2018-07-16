#pragma once
#include <SFML\Graphics.hpp>

class Player {
private:
	sf::RectangleShape player;

	const float width = 25.f;
	const float height = 200.f;

	float posX, posY;
public:
	Player();
	void update_pos();
	void movement();
	void check_wall_collision();

	sf::RectangleShape get_shape() const {
		return this->player;
	}

	float get_posY() {
		return this->posY;
	}
};