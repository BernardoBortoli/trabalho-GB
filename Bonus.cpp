#include "Bonus.h"
#include <iostream>
#include <sstream>

Bonus::Bonus(int minX, int minY, int y)
{
	_bonus = y % 5;
	if (_bonus == Bonus::BONUS_TYPE_HEAL) 
	{
		if (!texture.loadFromFile("images/obstacles/heal.png")) {};
	}
	sprite = sf::Sprite(texture);
	int posX = minX + texture.getSize().x;
	int posY = y % (minY - texture.getSize().y);
	sprite.setPosition(posX, posY);
	_type = Obstaculo::TYPE_BONUS;
}

Bonus::~Bonus()
{
}

std::string Bonus::getBonusSprite(int typeBonus)
{
	if (typeBonus == -1) return "images/bonus/bonus.png";
	std::stringstream ss;
	ss << "images/bonus/bonus" << typeBonus << ".png";
	return ss.str();
}

int Bonus::getBonus() const
{
	return _bonus;
}