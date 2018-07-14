#pragma once
#include <SFML\Graphics.hpp>

class Player {
private:
	sf::RectangleShape player;

	float width = 25;
	float height = 200;

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

