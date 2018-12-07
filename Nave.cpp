#include "Nave.h"
#include <sstream>
#include <iostream>

std::string Nave::getColor(int color) const
{
	switch (color)
	{
	case Nave::SPACESHIP_COLOR_RED: return "red";
	case Nave::SPACESHIP_COLOR_YELLOW: return "yellow";
	case Nave::SPACESHIP_COLOR_GREEN: return "green";
	case Nave::SPACESHIP_COLOR_BLUE: return "blue";
	case Nave::SPACESHIP_COLOR_PURPLE: return "purple";
	case Nave::SPACESHIP_COLOR_PINK: return "pink";
	case Nave::SPACESHIP_COLOR_GREY: return "grey";
	case Nave::SPACESHIP_COLOR_ORANGE: return "orange";
	default:
		return "red";
	}
}

void Nave::initNave(int type)
{
	switch (type)
	{
	case Nave::SPACESHIP_SKIN_0: _speed = 9; _health = _maxHealth = 120;
		guns = sf::Vector3i(68, 44, 0);
		break;
	case Nave::SPACESHIP_SKIN_1: _speed = 6; _health = _maxHealth = 180;
		guns = sf::Vector3i(84, 30, 86); _doubleGun = true;
		break;
	case Nave::SPACESHIP_SKIN_2: _speed = 6; _health = _maxHealth = 180;
		guns = sf::Vector3i(54, 64, 0);
		break;
	case Nave::SPACESHIP_SKIN_3: _speed = 9; _health = _maxHealth = 120;
		guns = sf::Vector3i(95, 42, 0);
		break;
	case Nave::SPACESHIP_SKIN_4: _speed = 6; _health = _maxHealth = 180;
		guns = sf::Vector3i(80, 42, 85); _doubleGun = true;
		break;
	case Nave::SPACESHIP_SKIN_5: _speed = 9; _health = _maxHealth = 120;
		guns = sf::Vector3i(46, 17, 74); _doubleGun = true;
		break;
	case Nave::SPACESHIP_SKIN_6: _speed = 12; _health = _maxHealth = 90;
		guns = sf::Vector3i(55, 15, 89); _doubleGun = true;
		break;
	case Nave::SPACESHIP_SKIN_7: _speed = 12; _health = _maxHealth = 90;
		guns = sf::Vector3i(42, 21, 75); _doubleGun = true;
		break;
	case Nave::SPACESHIP_SKIN_8: _speed = 12; _health = _maxHealth = 90;
		guns = sf::Vector3i(37, 45, 0);
		break;
	}
}

Nave::Nave()
{
}

Nave::Nave(int skinType) : Nave(skinType, Nave::SPACESHIP_COLOR_RED)
{
}

Nave::Nave(int skinType, int colorType) {
	std::stringstream path;
	_skin = skinType;
	_color = colorType;
	initNave(skinType);
	path << "images/spaceships/spaceship" << skinType << "/" << getColor(colorType) << ".png";
	if (!texture.loadFromFile(path.str())) {};
	sprite = sf::Sprite(texture);
}

Nave::~Nave()
{
}

void Nave::setPosition(int x, int y)
{
	sprite.setPosition(x, y);
}

void Nave::move(int keyX, int keyY)
{
	if (keyX >= -1 && keyX <= 1 && keyY >= -1 && keyY <= 1)
		sprite.move(keyX*_speed, keyY*_speed);
}

void Nave::takeDamages()
{
	_health -= 30;
	if (_health <= 0) {
		_health = 0;
	}
}

void Nave::setSkin(int skinType, int colorType)
{
	std::stringstream path;
	_skin = skinType;
	_color = colorType;
	initNave(skinType);
	path << "images/spaceships/spaceship" << skinType << "/" << getColor(colorType) << ".png";
	if (!texture.loadFromFile(path.str())) {};
	sprite = sf::Sprite(texture);
}

void Nave::addHealth()
{
	_health += 30;
	if (_health > _maxHealth) {
		_health = _maxHealth;
	}
}

int Nave::getWidth()  const
{
	return texture.getSize().x;
}

int Nave::getHeight()  const
{
	return texture.getSize().y;
}

int Nave::getSkin()  const
{
	return _skin;
}

int Nave::getColor()  const
{
	return _color;
}

int Nave::getX()  const
{
	return sprite.getPosition().x;
}

int Nave::getY()  const
{
	return sprite.getPosition().y;
}

int Nave::getHealth() const
{
	return _health;
}

float Nave::getMaxHealth() const
{
	return _maxHealth;
}

bool Nave::hasDoubleGun() const
{
	return _doubleGun;
}

sf::Vector3i Nave::getGuns() const
{
	return sf::Vector3i(guns);
}

sf::Sprite Nave::getSprite()  const
{
	return sf::Sprite(sprite);
}