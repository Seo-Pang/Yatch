#include "Player.h"

Player::Player()
{
	string name = "";
	this->point = 0;


	//��ĳ������ ���� cht�� ��� ������ ���� ����
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

//�̸��� ���� ����
Player::Player(string name) : Player()
{
	this->name = name;
}

string Player::get_name()
{
	return this->name;
}

void Player::set_name(string name)
{
	this->name = name;
	return;
}

int Player::calculate_total_point()
{
	int total = 0;
	int check_bonus = 0;
	for (int i = 0; i < 12; i++)
	{
		if (i <= 5) {
			check_bonus += cht[i]->get_point();
		}
		total += cht[i]->get_point();
	}
	if (check_bonus >= 63) {
		total += 35;
	}
	this->point = total;
	return total;
}

int Player::get_point()
{
	return this->point;
}