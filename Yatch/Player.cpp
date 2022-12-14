#include "Player.h"

Player::Player()
{
	string name = "";
	this->point = 0;


	//업캐스팅을 통해 cht에 모든 족보를 몰아 넣음
	for (int i = 0; i < 6; i++)
	{
		this->cht[i] = new NumberChart(i + 1);
	}
	this->cht[6] = new ChanceChart();
	this->cht[7] = new FourOfKindChart();
	this->cht[8] = new FullhouseChart();
	this->cht[9] = new	SmallStraightChart();
	this->cht[10] = new LargeStraightChart();
	this->cht[11] = new YatchChart();

}

//이름만 따로 설정
Player::Player(string name) : Player()
{
	this->name = name;
}

void Player::set_name(string name) {
	this->name = name;
}

string Player::get_name()
{
	return this->name;
}

void Player::reset_point() {
	this->point = 0;
	this->bonus = 0;
}

void Player::add_point(int n) {
	this->point += n;
}

int Player::get_point() {
	return this->point;
}

void Player::check_bonus() {
	int pts = 0;
	for (int i = 0; i < 6; i++) {
		pts += this->cht[i]->get_point();
	}
	if (pts >= 63) {
		this->bonus = 35;
	}
	else {
		this->bonus = 0;
	}
}

int Player::get_result() {
	return this->point;
}

int Player::get_bonus() {
	return this->bonus;
}

void Player::add_bonus() {
	this->point += this->bonus;
}

string Player::get_chartused(int n) {
	if (this->cht[n - 1]->get_used()) {
		return "●";
	}
	else {
		return "○";
	}
}

int Player::get_leftturn() {
	return this->turn_left;
}

void Player::use_leftturn() {
	this->turn_left--;
}

void Player::reset_leftturn() {
	this->turn_left = 12;
}

void Player::set_playturn() {
	if (this->play_turn) {
		this->play_turn = true;
	}
	else {
		this->play_turn = false;
	}
}

bool Player::get_playturn() {
	return this->play_turn;
}