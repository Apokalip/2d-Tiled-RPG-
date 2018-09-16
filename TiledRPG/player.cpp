#include "player.h"

Player::Player(Map * map, float x, float y): Entity(map){
	
	Load("playerTest.png");

	//setScale(0.8f, 0.8f);

	setPosition(x, y);
	this->map = map;
	speed =300.00f;

}
void Player::Update(sf::RenderWindow * window) {
	velocity.x = (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) * speed;
	velocity.y = (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) * speed;
	
	Entity::Update(window);

}
void Player::Collision(Entity * entity) {

}