#pragma once
#include <SFML\Graphics.hpp>
#include "Player.hpp"
#include "Bot.hpp"
#include "Ball.hpp"

class Game {
private:
	sf::RenderWindow window;
	sf::Event event;

	Player player;
	Bot bot;
	Ball ball;
public:
	Game() : window({ 1280, 720 }, "Pong", sf::Style::Titlebar | sf::Style::Close) {
		this->window.setFramerateLimit(60);
	}

	void loop();
	void update();
	void handle_events();
	void draw();
};

