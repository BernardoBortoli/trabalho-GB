#include "Panel.h"
#include "Botao.h"
#pragma once
class Creditos : public Panel
{
private:
	sf::Text ln1, ln2, ln3;
	sf::Font font;
	Botao back;
public:
	Creditos(Janela* window);
	void init();
	int keyPressedOnce(sf::Keyboard::Key key);
	int keyPressed(int key);
	int mouseMove(int x, int y);
	int mouseClicked(int x, int y, sf::Mouse::Button button);
	int getType() const;
};
