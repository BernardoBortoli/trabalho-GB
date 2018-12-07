#include "Obstaculo.h"

Obstaculo::Obstaculo()
{
}

Obstaculo::~Obstaculo()
{
}

void Obstaculo::move(float speed)
{
	sprite.move(-speed, 0);
}

int Obstaculo::getType() const
{
	return _type;
}

void Obstaculo::setSprite() 
{
	sprite.setTexture(texture);
}

sf::Sprite Obstaculo::getSprite() const
{
	return sf::Sprite(sprite);
}