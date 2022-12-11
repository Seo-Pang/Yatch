#pragma once
#include <iostream>
#include "Chart.h"
#include "Dice.h"
#include "Player.h"

class YatchGame
{
public:
	Chart* cht[12];

	void preview_point(Dice dice_list[]);
	int single_game();
	YatchGame();
	YatchGame(int player_number);
};
