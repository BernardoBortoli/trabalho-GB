#include "Panel.h"
#include "Botao.h"
#include <sstream>
#pragma once
class Shop : public Panel
{
private:
	std::vector<Botao*> cards;
	sf::Texture shop, star;
	sf::Sprite _shop, _star;
	sf::Font font;
	sf::Text _nbrStar;
	Botao *back;
public:
	Shop(Janela* window);
	~Shop();
	void init();
	int keyPressedOnce(sf::Keyboard::Key key);
	int mouseClicked(int x, int y, sf::Mouse::Button button);
	int mouseMove(int x, int y);
	int getType() const;
};