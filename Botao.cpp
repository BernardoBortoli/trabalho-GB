#include "Botao.h"
#include <iostream>


Botao::Botao(std::string path)
{
	if (!buffer.loadFromFile("sounds/button.wav")) {}
	sound.setBuffer(buffer);
	sound.setVolume(70);
	texture = sf::Texture();
	if (!texture.loadFromFile(path)) {};
	sprite = sf::Sprite(texture);
}

Botao::Botao(std::string path, std::string pathSelected)
{
	if (!buffer.loadFromFile("sounds/button.wav")) {}
	sound.setBuffer(buffer);
	if (!texture.loadFromFile(path)) {};
	if (!selectedTexture.loadFromFile(pathSelected)) {};
	sprite = sf::Sprite(texture);
}

Botao::~Botao()
{
}

void Botao::changeTexture(bool selected) {
	if (selected) {
		sprite.setTexture(selectedTexture);
		_isSelected = true;
	}
	else {
		sprite.setTexture(texture);
		_isSelected = false;
	}
}

void Botao::changeTexture() {
	sprite.setTexture(selectedTexture);
	if (!_isSelected) {
		sound.play();
	}
	_isSelected = true;
}

void Botao::setPosition(int x, int y)
{
	sprite.setPosition(x, y);
}

void Botao::setToDo(int todo)
{
	_toDo = todo;
}

void Botao::setVolume(int volume)
{
	if (volume >= 0 && volume <= 100) {
		sound.setVolume(volume);
	}
}

bool Botao::isSelected(int x, int y)
{
	if (sprite.getGlobalBounds().contains(x, y)) {
		return true;
	}
	else if (_isSelected) {
		sprite.setTexture(texture);
		_isSelected = false;
		return false;
	}
	else {
		return false;
	}
}

sf::Sprite Botao::getSprite() const
{
	return sf::Sprite(sprite);
}

int Botao::getX() const
{
	return sprite.getPosition().x;
}

int Botao::getY() const
{
	return sprite.getPosition().y;
}

int Botao::toDo() const
{
	return _toDo;
}