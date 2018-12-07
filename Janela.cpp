#include "Janela.h"

Janela::Janela(sf::VideoMode mode, std::string title, int style) : sf::RenderWindow(mode, title, style)
{
	config = new Config();
}

Janela::~Janela()
{
	delete config;
}

Config * Janela::getConfig() const
{
	return config;
}
