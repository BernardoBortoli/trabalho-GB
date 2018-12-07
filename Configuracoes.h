#include "Panel.h"
#include "BarraDeProgresso.h"
#include "Checkbox.h"
#include "Botao.h"
#pragma once
class Configuracoes : public Panel
{
private:
	sf::Texture volume, music, vsync;
	sf::Sprite _volume, _music, _vsync;
	BarraDeProgresso *pbVolume;
	Checkbox *cbMusic, *cbVsync;
	Botao *back;
public:
	Configuracoes(Janela* window);
	~Configuracoes();
	void init();
	int keyPressedOnce(sf::Keyboard::Key key);
	int keyPressed(int key);
	int mouseMove(int x, int y);
	int mouseClicked(int x, int y, sf::Mouse::Button button);
	int getType() const;
};