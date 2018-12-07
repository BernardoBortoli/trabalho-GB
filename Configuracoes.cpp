#include "Configuracoes.h"

Configuracoes::Configuracoes(Janela * window) : Panel(window)
{
	if (!volume.loadFromFile("images/settings/volume.png")) {};
	if (!music.loadFromFile("images/settings/music.png")) {};
	if (!vsync.loadFromFile("images/settings/vsync.png")) {};
	pbVolume = new BarraDeProgresso("T/images/settings/vol_bar.png");
	back = new Botao("images/settings/back.png", "images/settings/back_s.png");

	_volume = sf::Sprite(volume);
	_music = sf::Sprite(music);
	_vsync = sf::Sprite(vsync);
	cbMusic = new Checkbox();
	cbVsync = new Checkbox();

	_volume.setPosition(255, 255);
	_music.setPosition(255, 367);
	_vsync.setPosition(255, 479);
	pbVolume->setPositionBar(820, 273);
	pbVolume->setPosition(986, 259);
	cbMusic->setPosition(960, 371);
	cbVsync->setPosition(960, 481);
	back->setPosition(23, 28);

	pbVolume->setPercentage(getWindow()->getConfig()->getVolume());
	cbMusic->setChecked(getWindow()->getConfig()->isMusicOn());
	cbVsync->setChecked(getWindow()->getConfig()->isVsyncOn());
}

Configuracoes::~Configuracoes()
{
	delete pbVolume;
	delete cbMusic;
	delete cbVsync;
	delete back;
}

void Configuracoes::init()
{
	back->setVolume(getWindow()->getConfig()->getVolume());
	getWindow()->clear();
	getWindow()->draw(getBackground());
	getWindow()->draw(_volume);
	getWindow()->draw(_music);
	getWindow()->draw(_vsync);
	getWindow()->draw(pbVolume->getSpriteBar());
	getWindow()->draw(pbVolume->getSprite());
	getWindow()->draw(cbMusic->getSprite());
	getWindow()->draw(cbVsync->getSprite());
	getWindow()->draw(back->getSprite());
}

int Configuracoes::keyPressedOnce(sf::Keyboard::Key key)
{
	switch (key) {
	case(sf::Keyboard::Key::Escape): return Panel::PANEL_MENU; break;
	}
	return -1;
}

int Configuracoes::keyPressed(int key)
{
	return -1;
}

int Configuracoes::mouseMove(int x, int y) 
{
	if (back->isSelected(x, y)) {
		back->changeTexture();
	}
	return -1;
}

int Configuracoes::mouseClicked(int x, int y, sf::Mouse::Button button)
{
	if (button == sf::Mouse::Button::Left) {
		if (pbVolume->setPercentage(x, y)) {
			getWindow()->getConfig()->setVolume(pbVolume->getPercentage());
		}
		else if (cbMusic->setChecked(x, y)) {
			cbMusic->setChecked(!cbMusic->isChecked());
			getWindow()->getConfig()->setMusic(cbMusic->isChecked());
		}
		else if (cbVsync->setChecked(x, y)) {
			cbVsync->setChecked(!cbVsync->isChecked());
			getWindow()->getConfig()->setVsync(cbVsync->isChecked());
		}
		else if (back->isSelected(x, y)) {
			return Panel::PANEL_MENU;
		}
	}
	return -1;
}

int Configuracoes::getType() const
{
	return Panel::PANEL_SETTINGS;
}