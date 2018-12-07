#include "Panel.h"
#include "Meteoro.h"
#include "Estrela.h"
#include "Bonus.h"
#include "Inimigo.h"
#include "Botao.h"
#include "Nave.h"
#pragma once

class Jogo : public Panel
{
private:
	bool _pause;
	int _ticks, _typeBonus;
	float _pts;
	Botao btnMenu, btnQuit, _restart;
	Nave* spaceship;
	sf::Font font;
	sf::Text pts;
	sf::Texture pauseMenu, health, score, game_over, game_over_off;
	sf::Sprite _pauseMenu, _health, _score, _game_over;
	sf::RectangleShape rectHealth, rectBonus;
	std::vector<Obstaculo*> obstacles;
	sf::SoundBuffer buffer;
	sf::Sound sound;
public:
	Jogo(Janela* window);
	~Jogo();
	void init();
	void pause();
	void restart();
	void manageObstacles();
	int keyPressed(int key);
	int keyPressedOnce(sf::Keyboard::Key key);
	void moveBackground();
	int mouseClicked(int x, int y, sf::Mouse::Button button);
	int mouseMove(int x, int y);
	int getType() const;
};