#include "Checkbox.h"
#include <iostream>

Checkbox::Checkbox()
{
	if (!texture.loadFromFile("images/settings/checkbox.png")) {};
	if (!checkTexture.loadFromFile("images/settings/checkbox_s.png")) {};
	sprite = sf::Sprite(texture);
}

Checkbox::~Checkbox()
{
}

void Checkbox::setPosition(int x, int y)
{
	sprite.setPosition(x, y);
}

bool Checkbox::setChecked(int x, int y)
{
	if (sprite.getGlobalBounds().contains(x, y)) {
		return true;
	}
	return false;
}

void Checkbox::setChecked(bool checked) {
	if (checked) {
		sprite.setTexture(checkTexture);
	}
	else {
		sprite.setTexture(texture);
	}
	_checked = checked;
}

sf::Sprite Checkbox::getSprite() const
{
	return sf::Sprite(sprite);
}


bool Checkbox::isChecked() const
{
	return _checked;
}

int Checkbox::getX() const
{
	return sprite.getPosition().x;
}

int Checkbox::getY() const
{
	return sprite.getPosition().y;
}