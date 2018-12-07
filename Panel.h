#include <SFML/Graphics.hpp>
#include <iostream>
#include "Janela.h"
#pragma once

class Panel
{
private:
	sf::Texture background;
	sf::Sprite _background;
	Janela* mainWindow;
public:
	Panel(Janela* window);
	enum {
		PANEL_MENU,
		PANEL_GAME,
		PANEL_SETTINGS,
		PANEL_SHOP,
		PANEL_SCORE,
		PANEL_ACCOUNT,
		PANEL_CREDITS
	};
	void moveBackground();
	virtual void blink() { return; };
	virtual void init() = 0;
	virtual int keyPressed(int key) { return -1; };
	virtual int keyPressedOnce(sf::Keyboard::Key key) { return -1; };
	virtual int mouseClicked(int x, int y, sf::Mouse::Button) { return -1; };
	virtual int mouseMove(int x, int y) { return -1; };
	virtual int getType() const = 0;
	Janela* getWindow() const;
	sf::Sprite getBackground() const;
};