#include "Camera.h"
#include <string>
#include "System.h"
#include <iostream>

Camera::Camera(int x, int y) : View(sf::FloatRect(0, 0, x, y)) {
	
	
	speed = 2.00f;



}
Camera::Camera(int x, int y, Entity * target) : View(sf::FloatRect(0, 0, x, y)) {

	this->target = target;
	fpsTime=new sf::Clock();
	fpsFont= new sf::Font();
	fpsFont->loadFromFile("Graphics/menuFont.ttf");
	fpsText=new sf::Text();
	fpsText->setFont(*fpsFont);
	int PosX = target->getPosition().x;
	int PosY = target->getPosition().y;
	setCenter(PosX,PosY);
	speed = 25.00f;



}
void Camera::Update(sf::RenderWindow * window) {

	float fps = 1.0f / (fpsTime->restart()).asSeconds();
	int x = (target->getPosition().x - getCenter().x)*sys->getLastFrameTime()*3.00f;
	int y = (target->getPosition().y - getCenter().y)*sys->getLastFrameTime()*3.00f;
	move(x,y);
	//move(( target->getPosition()- getCenter())*sys->getLastFrameTime() *3.00f);
	window->setView(*this);
	fpsText->setString(std::to_string(fps));
	fpsText->setPosition(this->getCenter().x,this->getCenter().y-getSize().y/2);


}
void Camera::Render(sf::RenderWindow * window) {
	window->draw(*fpsText);

}