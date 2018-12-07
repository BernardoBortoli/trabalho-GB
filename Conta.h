#include "Panel.h"
#include "Botao.h"
#include <sstream>
#pragma once
class Conta : public Panel
{
private:
	sf::Font font;
	sf::Text level, nbrStar;
	sf::Texture xp, star, selectedColor;
	sf::Sprite _xp, _star, _selectedColor;
	sf::RectangleShape rectXp;
	Botao back;
	std::vector<Botao> spaceships;
	std::vector<Botao> colors;
public:
	Conta(Janela* window);
	void init();
	int keyPressedOnce(sf::Keyboard::Key key);
	int mouseMove(int x, int y);
	int mouseClicked(int x, int y, sf::Mouse::Button button);
	int getType() const;
};