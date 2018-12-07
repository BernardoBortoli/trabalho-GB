#include "Obstaculo.h"
#include <SFML/Graphics.hpp>
#pragma once
class Inimigo : public Obstaculo
{
private:
	bool _direction;
public:
	Inimigo(int minX, int minY, int y);
	~Inimigo();
	void move(float speed);
	bool takeDamage();
};

