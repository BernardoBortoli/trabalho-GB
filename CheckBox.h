#include <SFML/Graphics.hpp>
#pragma once
class Checkbox
{
private:
	bool _checked;
	sf::Texture texture, checkTexture;
	sf::Sprite sprite;
public:
	Checkbox();
	~Checkbox();
	void setPosition(int x, int y);
	bool setChecked(int x, int y);
	void setChecked(bool checked);
	sf::Sprite getSprite() const;
	bool isChecked() const;
	int getX() const;
	int getY() const;
};