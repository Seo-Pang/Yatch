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

	// �ֻ��� ���� �� �ִ� Ƚ�� ���� �Լ�
	void reset_rollChance();
	int get_rollChance();
	void count_rollChance();

	// �ֻ����� �ٽ� ���� ������ �����ϴ� �Լ�
	void set_rerollDice(bool* select_rerollDice[]);
	void reset_rerollDice();
	bool* get_rerollDice();
	bool get_rerollDice_once(int n);

	// Ŀ�ǵ� �Լ�
	static int select_command();
	static int select_command_rollDice(bool* select_rerollDice[]);
	static int select_command_setChart(Player* player);
};

class GameUI : public YatchGame {
public:
	static string get_playerName(int n);
	static void play_gameUI(Dice dc[], Player* player, Chart* previewCht[], int use_roll, bool select_rerollDice[]);
	static int gameSet_UI(Player* player, int high_score);

	// �ش� �ֻ����� ���� ������ Ȯ���ϱ� ���� �ڵ�
	string get_rerollDice(int n);
};
