#include "Obstaculo.h"
#pragma once
class Bonus : public Obstaculo
{
private:
	int _bonus;
public:
	static std::string getBonusSprite(int typeBonus);
	enum {
		BONUS_TYPE_GOD,
		BONUS_TYPE_HEAL,
	};
	Bonus(int minX, int minY, int y);
	~Bonus();
	int getBonus() const;
};