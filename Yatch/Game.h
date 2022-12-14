#pragma once

#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Chart.h"
#include "Dice.h"
#include "Player.h"

class YatchGame
{
public:
	Chart* cht[12];
	int use_roll = 3;
	bool select_rerollDice[5] = { false, };

	void preview_point(Dice dice_list[]);
	int play_game(int player_number);
	//int single_game();
	YatchGame();
	//YatchGame(int player_number);

	// 주사위 굴릴 수 있는 횟수 전용 함수
	void reset_rollChance();
	int get_rollChance();
	void count_rollChance();

	// 주사위를 다시 굴릴 것인지 선택하는 함수
	void set_rerollDice(bool* select_rerollDice[]);
	void reset_rerollDice();
	bool* get_rerollDice();
	bool get_rerollDice_once(int n);

	// 커맨드 함수
	static int select_command();
	static int select_command_rollDice(bool* select_rerollDice[]);
	static int select_command_setChart(Player* player);
};

class GameUI : public YatchGame {
public:
	static string get_playerName(int n);
	static void play_gameUI(Dice dc[], Player* player, Chart* previewCht[], int use_roll, bool select_rerollDice[]);
	static int gameSet_UI(Player* player, int high_score);

	// 해당 주사위를 돌릴 것인지 확인하기 위한 코드
	string get_rerollDice(int n);
};
