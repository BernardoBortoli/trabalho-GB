#include "Estrela.h"

Estrela::Estrela(int minX, int minY, int y)
{
	if (!texture.loadFromFile("images/obstacles/star.png")) {};
	sprite = sf::Sprite(texture);
	int posX = minX + texture.getSize().x;
	int posY = y % (minY - texture.getSize().y);
	sprite.setPosition(posX, posY);
	_type = Obstaculo::TYPE_STAR;
}

Estrela::~Estrela()
{
}
