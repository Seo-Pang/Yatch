#pragma once
#include "Chart.h"
#include <string>

using namespace std;

class Player
{
private:
	int point;
	int bonus;
	int turn_left;
	bool play_turn = false;
	string name;
	
public:
	Chart* cht[12];
	Player();
	Player(string name);
	void set_name(string name);
	string get_name();

	//�÷��̾��� ���� üũ �Լ���
	void reset_point();
	void add_point(int n);
	int get_point();
	void check_bonus();
	int get_result();
	int get_bonus();
	void add_bonus();

	//�÷��̾ ������ ����ߴ��� Ȯ���ϴ� �Լ�
	string get_chartused(int n);

	//�÷��̾��� ���� �� Ȯ�� �� ����
	int get_leftturn();
	void use_leftturn();
	void reset_leftturn();
	void set_playturn();
	bool get_playturn();
};