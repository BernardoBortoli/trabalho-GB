#include "Jogo.h"
#include <stdlib.h>
#include <time.h> 
#include <sstream>

Jogo::Jogo(Janela* window) : Panel(window)
{
	srand(time(NULL));

	if (!pauseMenu.loadFromFile("images/game/menu_pause.png")) {};
	if (!font.loadFromFile("fonts/masterbreaker.ttf")) {}
	if (!health.loadFromFile("images/game/health.png")) {};
	if (!score.loadFromFile("images/game/score.png")) {};
	if (!game_over.loadFromFile("images/game/gameover.png")) {};
	if (!game_over_off.create(game_over.getSize().x, game_over.getSize().y)) {};

	_restart = Botao("images/game/restart.png", "images/game/restart_s.png");
	_restart.changeTexture(false);
	btnMenu = Botao("images/game/btn_menu.png", "images/game/btn_menu_s.png");
	btnQuit = Botao("images/game/btn_quit.png", "images/game/btn_quit_s.png");

	_pauseMenu = sf::Sprite(pauseMenu);
	int skinType = getWindow()->getConfig()->getSelectedSpaceship();
	int colorType = getWindow()->getConfig()->getSelectedColor();
	spaceship = new Nave(skinType, colorType);

	if (!buffer.loadFromFile("sounds/laser.wav")) {}
	sound.setBuffer(buffer);

	restart();
}

Jogo::~Jogo()
{
	for (size_t i = 0; i < obstacles.size(); i++) {
		delete obstacles[i];
	}
	delete spaceship;
}

void::Jogo::restart() 
{
	_ticks = _laserTicks = _pts = 0;
	_typeBonus = -1;
	_timeBonus = 0;
	_speed = 12;
	_pause = false;
	lasers.clear();
	obstacles.clear();
	pts = sf::Text("        0", font, 72);
	pts.setFillColor(sf::Color(249, 148, 7));

	rectHealth = sf::RectangleShape(sf::Vector2f(275, 51));
	rectHealth.setFillColor(sf::Color(195, 2, 2));
	rectHealth.setPosition(15, 60);

	_health = sf::Sprite(health);
	_game_over = sf::Sprite(game_over);
	_score = sf::Sprite(score);

	int skinType = getWindow()->getConfig()->getSelectedSpaceship();
	int colorType = getWindow()->getConfig()->getSelectedColor();
	*spaceship = Nave(skinType, colorType);
	spaceship->setSkin(skinType, colorType);

	_pauseMenu.setPosition(590, 337);
	_health.setPosition(5, 11);
	_score.setPosition(1270, 694);
	_game_over.setPosition(405, 190);
	pts.setPosition(1230, 710);
	_restart.setPosition(1343, 13);
	btnMenu.setPosition(629, 363);
	btnQuit.setPosition(647, 430);
	btnMenu.changeTexture(false);
	btnQuit.changeTexture(false);
	spaceship->setPosition(27, ((getWindow()->getSize().y - spaceship->getHeight()) / 2.));

	btnMenu.setToDo(Panel::PANEL_MENU);
}

void Jogo::init()
{
	if (!_pause) {
		_pts += 0.1;
		_speed += 0.00032;
		std::stringstream ss;
		ss.width(8);
		ss << (int)_pts;
		pts.setString(ss.str());
	}
	if (_speed >= _timeBonus) {
		_typeBonus = -1;
	}
	if (spaceship->getSkin() != getWindow()->getConfig()->getSelectedSpaceship() || spaceship->getColor() != getWindow()->getConfig()->getSelectedColor()) {
		restart();
	}
	if (!tbonus.loadFromFile(Bonus::getBonusSprite(_typeBonus))) {};
	_tbonus = sf::Sprite(tbonus);
	_tbonus.setPosition(17, 672);
	if (_typeBonus != -1) {
		rectBonus.setSize(sf::Vector2f(((_timeBonus - _speed) / 0.24 * 120), 120));
	}
	else {
		rectBonus.setSize(sf::Vector2f(0, 120));
	}
	_restart.setVolume(getWindow()->getConfig()->getVolume());
	btnMenu.setVolume(getWindow()->getConfig()->getVolume());
	btnQuit.setVolume(getWindow()->getConfig()->getVolume());
	sound.setVolume(getWindow()->getConfig()->getVolume());

	getWindow()->clear();
	rectHealth.setSize(sf::Vector2f((275 * (spaceship->getHealth() / spaceship->getMaxHealth())), 51));
	getWindow()->draw(getBackground());
	manageShoots();
	manageObstacles();
	getWindow()->draw(spaceship->getSprite());
	getWindow()->draw(pts);
	getWindow()->draw(rectHealth);
	getWindow()->draw(_health);
	getWindow()->draw(_score);
	getWindow()->draw(_restart.getSprite());

	if (_pause) {
		_ticks++;
		getWindow()->draw(_pauseMenu);
		getWindow()->draw(btnMenu.getSprite());
		getWindow()->draw(btnQuit.getSprite());
		if (spaceship->getHealth() <= 0) {
			getWindow()->draw(_game_over);
		}
		if (_ticks >= 30) {
			_game_over.setTexture(game_over);
		}
		if (_ticks >= 60) {
			_game_over.setTexture(game_over_off);
			_ticks = 0;
		}
	}
}

void Jogo::pause()
{
	_pause = !_pause;
}

void Jogo::manageObstacles() 
{
	int chance;
	if (!_pause) {
		_ticks++;
		if (_ticks > 40) {
			chance = rand() % 100;
			if (chance < 40) {
				obstacles.push_back(new Meteoro(getWindow()->getSize().x + 300, getWindow()->getSize().y, rand()));
			}
			else if (chance < 82) {
				obstacles.push_back(new Inimigo(getWindow()->getSize().x + 300, getWindow()->getSize().y, rand()));
			}
			else if (chance < 94) {
				obstacles.push_back(new Estrela(getWindow()->getSize().x + 300, getWindow()->getSize().y, rand()));
			}
			else {
				obstacles.push_back(new Bonus(getWindow()->getSize().x + 300, getWindow()->getSize().y, rand()));
			}
			_ticks = 0;
		}
		for (size_t i = 0; i < obstacles.size(); i++)
		{
			if (obstacles[i]->getSprite().getPosition().x < -obstacles[i]->getSprite().getGlobalBounds().width || obstacles[i]->getSprite().getPosition().y < -obstacles[i]->getSprite().getGlobalBounds().height)
			{
				obstacles.erase(obstacles.begin() + i);
			}
			else if (obstacles[i]->getSprite().getGlobalBounds().intersects(spaceship->getSprite().getGlobalBounds()))
			{
				if ((obstacles[i]->getType() == Obstaculo::TYPE_METEOR) || (obstacles[i]->getType() == Obstaculo::TYPE_ENNEMY))
				{
					if (_typeBonus != Bonus::BONUS_TYPE_GOD) spaceship->takeDamages();
					if (spaceship->getHealth() <= 0) {
						getWindow()->getConfig()->addScore(_pts);
						getWindow()->getConfig()->addXp(_pts);
						pause();
					}
				}
				else if (obstacles[i]->getType() == Obstaculo::TYPE_STAR) 
				{
					getWindow()->getConfig()->addNbrStar();
				}
				else if (obstacles[i]->getBonus() == Bonus::BONUS_TYPE_HEAL) 
				{
						spaceship->addHealth();
					}
					else if (_typeBonus == -1 && _speed >= _timeBonus) 
					{
						_typeBonus = obstacles[i]->getBonus();
						_timeBonus = _speed + 0.24;
					}
				obstacles.erase(obstacles.begin() + i);
				break;
			}
		}
	}
	for (size_t i = 0; i < obstacles.size(); i++)
	{
		if (!_pause) obstacles[i]->move(_speed);
		getWindow()->draw(obstacles[i]->getSprite());
	}
}

int Jogo::keyPressed(int key)
{
	switch (key) 
	{
	case(sf::Keyboard::Key::Space): if (!_pause) shoot(); break;
	case(sf::Keyboard::Key::W):
		if (!_pause && spaceship->getY() - 10 > 0)
			spaceship->move(0, -1);
		break;
	case(sf::Keyboard::Key::S):
		if (!_pause && (spaceship->getY() + spaceship->getHeight() + 10) < getWindow()->getSize().y)
			spaceship->move(0, 1);
		break;
	case(sf::Keyboard::Key::A):
		if (!_pause &&spaceship->getX() - 10 > 0)
			spaceship->move(-1, 0);
		break;
	case(sf::Keyboard::Key::D):
		if (!_pause && (spaceship->getX() + spaceship->getWidth() + 10) < (getWindow()->getSize().x))
			spaceship->move(1, 0);
		break;
	case(sf::Keyboard::Key::R):
		restart();
		break;
	}
	return -1;
}

void Jogo::moveBackground()
{
	if (!_pause) {
		Panel::moveBackground();
	}
}

int Jogo::keyPressedOnce(sf::Keyboard::Key key)
{
	switch (key) {
	case(sf::Keyboard::Key::Escape): if (spaceship->getHealth() > 0) pause(); break;
	}
	return -1;
}

int Jogo::mouseClicked(int x, int y, sf::Mouse::Button button)
{
	if (button == sf::Mouse::Button::Left) 
	{
		if (btnMenu.isSelected(x, y)) 
		{
			pause();
			restart();
			return btnMenu.toDo();
		}
		else if (_restart.isSelected(x, y)) 
		{
			restart();
		}
		else if (btnQuit.isSelected(x, y)) 
		{
			getWindow()->getConfig()->save();
			getWindow()->close();
		}
	}
	return -1;
}

int Jogo::mouseMove(int x, int y) 
{
	if (btnMenu.isSelected(x, y) && _pause) 
	{
		btnMenu.changeTexture();
	}
	else if (btnQuit.isSelected(x, y) && _pause) 
	{
		btnQuit.changeTexture();
	}
	else if (_restart.isSelected(x, y)) 
	{
		_restart.changeTexture();
	}
	return -1;
}

int Jogo::getType() const
{
	return Panel::PANEL_GAME;
}