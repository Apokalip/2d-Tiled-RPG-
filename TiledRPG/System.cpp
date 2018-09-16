#include "System.h"


System::System() {
	timer = new sf::Clock();
}
void System::Update() {
	deltaTime = timer->restart().asSeconds();
}
float System::getLastFrameTime() {

	return deltaTime;

}
System * sys = new System();