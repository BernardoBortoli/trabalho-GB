#include "Meteoro.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>   

Meteoro::Meteoro(int minX, int minY, int y)
{
	int skinType = y % 3;
	_health = 2;
	std::stringstream ss;
	ss << "images/obstacles/meteor" << skinType << ".png";
	if (!texture.loadFromFile(ss.str())) {};
	sprite = sf::Sprite(texture);
	int posX = minX + texture.getSize().x;
	int posY = y % (minY - texture.getSize().y);
	sprite.setPosition(posX, posY);
	_type = Obstaculo::TYPE_METEOR;
}

Meteoro::~Meteoro()
{
}

bool Meteoro::takeDamage()
{
	_health -= 1;
	if (_health <= 0) {
		return false;
	}
	return true;
}