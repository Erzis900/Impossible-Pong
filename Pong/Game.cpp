#include "Game.hpp"

void Game::loop() {
	while (this->window.isOpen()) {
		this->update();
		this->handle_events();
		this->draw();
	}
}

void Game::update() {
	this->player.update_pos();
	this->player.movement();
	this->player.check_wall_collision();

	this->bot.update_pos();
	this->bot.play(this->ball);
	this->bot.check_wall_collision();

	this->ball.update_pos();
	this->ball.movement();
	this->ball.check_collision(this->player, this->bot);
}

void Game::handle_events() {
	while (this->window.pollEvent(this->event)) {
		switch (this->event.type) {
			case sf::Event::Closed:
				this->window.close();
				break;
			default:
				break;
		}
	}
}

void Game::draw() {
	this->window.clear();
	this->window.draw(this->player.get_shape());
	this->window.draw(this->bot.get_shape());
	this->window.draw(this->ball.get_shape());
	this->window.display();
}