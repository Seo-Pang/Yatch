#pragma once
#include <iostream>
#include "Chart.h"
#include "Dice.h"
#include "Player.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <windows.h>

class YatchGame
{
private:
	int player_number;
public:
	Chart* cht[12];

	void preview_point(Dice dice_list[], Player* player);
	int single_game();
	void multigame();
	YatchGame();
};
