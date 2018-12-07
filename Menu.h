#include "Panel.h"
#include "Botao.h"
#include <SFML/Audio.hpp>
#pragma once
class Menu : public Panel
{
private:
	Botao *btnPlay, *btnSettings, *btnScore, *btnShop, *btnAccount, *btnCredits;
public:
	Menu(Janela* window);
	~Menu();
	void init();
	int mouseClicked(int x, int y, sf::Mouse::Button button);
	int mouseMove(int x, int y);
	int getType()  const;
};