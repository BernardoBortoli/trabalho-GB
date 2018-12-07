#include <SFML/Graphics.hpp>
#pragma once
class BarraDeProgresso
{
private:
	float _percentage;
	int _start, _end;
	sf::Texture texture, rectTexture;
	sf::Sprite sprite, rectSprite;
public:
	BarraDeProgresso() {};
	BarraDeProgresso(std::string path);
	BarraDeProgresso(int start, int end, std::string path);
	~BarraDeProgresso();
	void setPosition(int x, int y);
	void setPositionBar(int x, int y);
	bool setPercentage(int x, int y);
	bool setPercentage(int percentage);
	int getPercentage() const;
	int getX() const;
	int getY() const;
	sf::Sprite getSprite() const;
	sf::Sprite getSpriteBar() const;
};