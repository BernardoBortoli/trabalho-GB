#include "Inimigo.h"
#include <sstream>
#include <iostream>

Inimigo::Inimigo(int minX, int minY, int y)
{
	_health = 2;
	_direction = y % 2;
	int skinType = y % 5;
	std::stringstream ss;
	ss << "images/obstacles/ennemy" << skinType << ".png";
	if (!texture.loadFromFile(ss.str())) {};
	sprite = sf::Sprite(texture);
	int posX = minX + texture.getSize().x;
	int posY = y % (minY - texture.getSize().y);
	sprite.setPosition(posX, posY);
	_type = Obstaculo::TYPE_ENNEMY;
}

Inimigo::~Inimigo()
{
}

void Inimigo::move(float speed)
{
	sprite.move(-speed, 0);
	if (_direction && (sprite.getPosition().y - speed / 2) > 0) {
		sprite.move(0, -5);
	}
	else {
		_direction = false;
	}
	if (!_direction && (sprite.getPosition().y + texture.getSize().y + speed / 2) < 810) {
		sprite.move(0, +5);
	}
	else {
		_direction = true;
	}
}

bool Inimigo::takeDamage()
{
	_health -= 1;
	if (_health <= 0) {
		return false;
	}
	return true;
}