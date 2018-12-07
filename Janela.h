#include <SFML/Graphics.hpp>
#include "Config.h"
#pragma once
class Janela : public sf::RenderWindow
{
private:
	Config* config;
public:
	Janela(sf::VideoMode mode, std::string title, int style);
	~Janela();
	Config* getConfig() const;
};