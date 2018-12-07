#include "Creditos.h"

Creditos::Creditos(Janela* window) : Panel(window)
{
	if (!font.loadFromFile("fonts/masterbreaker.ttf")) {}
	back = Botao("images/settings/back.png", "images/settings/back_s.png");
	back.changeTexture(false);

	ln1 = sf::Text("Bernardo de Bortoli da Silva,", font, 50);
	ln2 = sf::Text("Universidade do Vale do Rio dos Sinos(Unisinos),", font, 50);
	ln3 = sf::Text("professor Raphael Campos.", font, 50);

	ln1.setFillColor(sf::Color(249, 148, 7));
	ln2.setFillColor(sf::Color(249, 148, 7));
	ln3.setFillColor(sf::Color(249, 148, 7));

	back.setPosition(23, 28);
	ln1.setPosition(710 - ln1.getLocalBounds().width / 2, 300);
	ln2.setPosition(710 - ln2.getLocalBounds().width / 2, 400);
	ln3.setPosition(710 - ln3.getLocalBounds().width / 2, 500);
}

void Creditos::init()
{
	back.setVolume(getWindow()->getConfig()->getVolume());

	getWindow()->clear();
	getWindow()->draw(getBackground());
	getWindow()->draw(back.getSprite());
	getWindow()->draw(ln1);
	getWindow()->draw(ln2);
	getWindow()->draw(ln3);
}

int Creditos::keyPressedOnce(sf::Keyboard::Key key)
{
	switch (key) {
	case(sf::Keyboard::Key::Escape): return Panel::PANEL_MENU; break;
	}
	return -1;
}

int Creditos::keyPressed(int key)
{
	return -1;
}

int Creditos::mouseMove(int x, int y) {
	if (back.isSelected(x, y)) {
		back.changeTexture();
	}
	return -1;
}

int Creditos::mouseClicked(int x, int y, sf::Mouse::Button button)
{
	if (button == sf::Mouse::Button::Left) {
		if (back.isSelected(x, y)) {
			back.changeTexture();
			return Panel::PANEL_MENU;
		}
	}
	return -1;
}

int Creditos::getType() const
{
	return Panel::PANEL_ACCOUNT;
}