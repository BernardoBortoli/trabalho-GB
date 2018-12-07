#include <SFML/Graphics.hpp>
#include "Obstaculo.h"
#include <sstream>
#pragma once
class Meteoro : public Obstaculo
{
public:
	Meteoro(int minX, int minY, int y);
	~Meteoro();
	bool takeDamage();
};

