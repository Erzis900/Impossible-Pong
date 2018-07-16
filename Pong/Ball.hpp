#pragma once
#include <SFML\Graphics.hpp>
#include <random>
#include "Player.hpp"
#include "Bot.hpp"

class Bot;
class Ball {
private:
	sf::CircleShape ball;

	const float radius = 30.f;

	float posX, posY;
	float velX = 6.f;
	float velY = 6.f;

	int dir;

	std::mt19937 random;
	std::uniform_int_distribution<std::mt19937::result_type> dist;
public:
	Ball();
	void update_pos();
	void movement();
	void check_collision(Player player, Bot bot);

	sf::CircleShape get_shape() const {
		return ball;
	}

	float get_posY() {
		return this->posY;
	}
};

