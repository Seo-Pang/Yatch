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

string Player::get_name()
{
	return this->name;
}