#include "Menu.h"
#include <iostream>

Menu::Menu(Janela* window) : Panel(window)
{
	btnPlay = new Botao("images/menu/btn_play.png", "images/menu/btn_play_s.png");
	btnSettings = new Botao("images/menu/btn_settings.png", "images/menu/btn_settings_s.png");
	btnShop = new Botao("images/menu/btn_shop.png", "images/menu/btn_shop_s.png");
	btnScore = new Botao("images/menu/btn_score.png", "images/menu/btn_score_s.png");
	btnAccount = new Botao("images/menu/btn_account.png", "images/menu/btn_account_s.png");
	btnCredits = new Botao("images/menu/btn_credits.png", "images/menu/btn_credits_s.png");

	btnPlay->setPosition(439, 112);
	btnSettings->setPosition(439, 220);
	btnShop->setPosition(439, 323);
	btnScore->setPosition(439, 431);
	btnAccount->setPosition(432, 540);
	btnCredits->setPosition(433, 647);

	btnPlay->setToDo(Panel::PANEL_GAME);
	btnSettings->setToDo(Panel::PANEL_SETTINGS);
	btnShop->setToDo(Panel::PANEL_SHOP);
	btnScore->setToDo(Panel::PANEL_SCORE);
	btnAccount->setToDo(Panel::PANEL_ACCOUNT);
	btnCredits->setToDo(Panel::PANEL_CREDITS);

}

Menu::~Menu()
{
	delete btnPlay;
	delete btnSettings;
	delete btnScore;
	delete btnShop;
	delete btnAccount;
	delete btnCredits;
}

void Menu::init()
{
	btnPlay->setVolume(getWindow()->getConfig()->getVolume());
	btnSettings->setVolume(getWindow()->getConfig()->getVolume());
	btnShop->setVolume(getWindow()->getConfig()->getVolume());
	btnScore->setVolume(getWindow()->getConfig()->getVolume());
	btnAccount->setVolume(getWindow()->getConfig()->getVolume());
	btnCredits->setVolume(getWindow()->getConfig()->getVolume());
	getWindow()->clear();

	getWindow()->draw(getBackground());
	getWindow()->draw(btnPlay->getSprite());
	getWindow()->draw(btnSettings->getSprite());
	getWindow()->draw(btnShop->getSprite());
	getWindow()->draw(btnScore->getSprite());
	getWindow()->draw(btnAccount->getSprite());
	getWindow()->draw(btnCredits->getSprite());
}

int Menu::mouseClicked(int x, int y, sf::Mouse::Button button)
{
	if (button == sf::Mouse::Button::Left) 
	{
		if (btnPlay->isSelected(x, y)) 
		{
			btnPlay->changeTexture(false);
			return btnPlay->toDo();
		}
		else if (btnSettings->isSelected(x, y)) 
		{
			btnSettings->changeTexture(false);
			return btnSettings->toDo();
		}
		else if (btnShop->isSelected(x, y)) 
		{
			btnShop->changeTexture(false);
			return btnShop->toDo();
		}
		else if (btnScore->isSelected(x, y)) 
		{
			btnScore->changeTexture(false);
			return btnScore->toDo();
		}
		else if (btnAccount->isSelected(x, y)) 
		{
			btnAccount->changeTexture(false);
			return btnAccount->toDo();
		}
		else if (btnCredits->isSelected(x, y)) 
		{
			btnCredits->changeTexture(false);
			return btnCredits->toDo();
		}
	}
	return -1;
}

int Menu::mouseMove(int x, int y) 
{
	if (btnPlay->isSelected(x, y)) 
	{
		btnPlay->changeTexture();
	}
	else if (btnSettings->isSelected(x, y)) 
	{
		btnSettings->changeTexture();
	}
	else if (btnShop->isSelected(x, y)) 
	{
		btnShop->changeTexture();
	}
	else if (btnScore->isSelected(x, y)) 
	{
		btnScore->changeTexture();
	}
	else if (btnAccount->isSelected(x, y)) 
	{
		btnAccount->changeTexture();
	}
	else if (btnCredits->isSelected(x, y)) 
	{
		btnCredits->changeTexture();
	}
	return -1;
}

int Menu::getType() const 
{
	return Panel::PANEL_MENU;
}