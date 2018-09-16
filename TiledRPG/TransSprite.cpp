#pragma once
#include "TransSprite.h"

	TransSprite::TransSprite() {
		visible = new sf::Texture();
		transperant = new sf::Texture();
	}
	TransSprite::TransSprite(sf::Texture * vis,sf::Texture * trans) {
		visible = vis;
		transperant = trans;

	}
	void TransSprite::setVisibleTexture(sf::Texture * vis) {
		visible = vis;
		setTexture(*visible);
	}
	void TransSprite::setTransperantTexture(sf::Texture * tran) {
		transperant = tran;
	}
	void TransSprite::setTransperant() {
		
			setTexture(*transperant);
	}
		
	void TransSprite::setVisible() {

		setTexture(*visible);
	}
			
		
	
	
	bool TransSprite::CheckCollision(sf::Sprite * entity) {

		return getGlobalBounds().intersects(entity->getGlobalBounds());

	}

