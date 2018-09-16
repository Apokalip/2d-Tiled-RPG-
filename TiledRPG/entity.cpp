#include "entity.h"
#include "System.h"
Entity::Entity(Map * m)
{
	this->texture = new sf::Texture();
	this->active = 1;
	this->groupId = 0;
	map = m;
	
}

void Entity::Load(std::string filename)
{
	this->texture->loadFromFile("Graphics/sprites/" + filename);
	this->setTexture(*this->texture);
}
void Entity::Update(sf::RenderWindow* window)
{
	sf::Vector2f corners[4];
	sf::Vector2f spritePos(getPosition());
	int width = getGlobalBounds().width;
	int height = getGlobalBounds().height;
	corners[0] = spritePos;
	corners[1] = getPosition() + sf::Vector2f(0,height);
	corners[2] = getPosition() + sf::Vector2f(width, height);
	corners[3] = getPosition() + sf::Vector2f(width, 0);

	sf::Vector2f v(velocity);
	for (int i = 0;i < 4;i++) {
	
		if (map->CheckCollision(corners[i], sf::Vector2f(v.x*sys->getLastFrameTime(), 0)) == 1) {
			v.x = 0;
			

		}
		if (map->CheckCollision(corners[i], sf::Vector2f(0, v.y*sys->getLastFrameTime())) == 1) {
		v.y = 0;

		}
	}
	int x = v.x*sys->getLastFrameTime();
	int y = v.y*sys->getLastFrameTime();
		move(x,y);
}
void Entity::OnCollision(Entity* entity)
{
}

bool Entity::CheckCollision(Entity* entity)
{
	return this->getGlobalBounds().intersects(entity->getGlobalBounds());
}

int Entity::GroupID()
{
	return this->groupId;
}

int Entity::Active()
{
	return this->active;
}

void Entity::Destroy()
{
	this->active = 0;
}
sf::Vector2f Entity::getVel() {
	return velocity;
}
void Entity::setVisibleTexture(sf::Texture * vis) {

}
void Entity::setTransperantTexture(sf::Texture * tran) {

}
void Entity::setTransperant() {

}

Entity::~Entity()
{
	delete this->texture;
}