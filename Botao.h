#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#pragma once
class Botao
{
private:
	bool _isSelected = false;
	int _toDo;
	sf::Texture texture, selectedTexture;
	sf::Sprite sprite;
	sf::SoundBuffer buffer;
	sf::Sound sound;
public:
	Botao() {};
	Botao(std::string path);
	Botao(std::string path, std::string pathSelected);
	~Botao();
	void changeTexture(bool selected);
	void changeTexture();
	bool isSelected(int x, int y);
	void setPosition(int x, int y);
	void setToDo(int todo);
	void setVolume(int volume);
	sf::Sprite getSprite() const;
	int getX() const;
	int getY() const;
	int toDo() const;
};
