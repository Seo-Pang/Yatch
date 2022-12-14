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

	//플레이어의 점수 체크 함수들
	void reset_point();
	void add_point(int n);
	int get_point();
	void check_bonus();
	int get_result();
	int get_bonus();
	void add_bonus();

	//플레이어가 족보를 사용했는지 확인하는 함수
	string get_chartused(int n);

	//플레이어의 남은 턴 확인 및 설정
	int get_leftturn();
	void use_leftturn();
	void reset_leftturn();
	void set_playturn();
	bool get_playturn();
};