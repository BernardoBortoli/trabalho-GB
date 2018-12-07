#include "BarraDeProgresso.h"

BarraDeProgresso::BarraDeProgresso(std::string path)
{
	if (!texture.loadFromFile(path)) {};
	sprite = sf::Sprite(texture);
	if (!rectTexture.loadFromFile("images/settings/rect_bar.png")) {};
	rectSprite = sf::Sprite(rectTexture);
	_percentage = 50;
	_start = 0;
	_end = 100;
}

BarraDeProgresso::BarraDeProgresso(int start, int end, std::string path) : BarraDeProgresso(path)
{
	_start = start;
	_end = end;
}

BarraDeProgresso::~BarraDeProgresso()
{
}

void BarraDeProgresso::setPosition(int x, int y)
{
	rectSprite.setPosition(x, y);
}

void BarraDeProgresso::setPositionBar(int x, int y)
{
	sprite.setPosition(x, y);
}

bool BarraDeProgresso::setPercentage(int x, int y)
{
	if (sprite.getGlobalBounds().contains(x, y)) {
		rectSprite.setPosition(x, rectSprite.getPosition().y);
		_percentage = ((float)x - sprite.getPosition().x) / texture.getSize().x;
		return true;
	}
	return false;
}

bool BarraDeProgresso::setPercentage(int percentage) 
{
	if (percentage >= 0 && percentage <= 100) {
		_percentage = percentage / 100.;
		rectSprite.setPosition((sprite.getPosition().x + texture.getSize().x*_percentage), rectSprite.getPosition().y);
		return true;
	}
	return false;
}

sf::Sprite BarraDeProgresso::getSprite() const
{
	return sf::Sprite(rectSprite);
}

sf::Sprite BarraDeProgresso::getSpriteBar() const
{
	return sf::Sprite(sprite);
}

int BarraDeProgresso::getPercentage() const
{
	return _start + ((_end - _start)*_percentage);
}

int BarraDeProgresso::getX() const
{
	return sprite.getPosition().x;
}

int BarraDeProgresso::getY() const
{
	return sprite.getPosition().y;
}