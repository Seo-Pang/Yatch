#include "Chart.h"
#include <string>
using namespace std;

//Chart

Chart::Chart()
{
	this->is_used = false;
	this->point = 0;
	this->index = 0;
}

int* Chart::counting(Dice dice_list[]) {
	int cnt[6] = { 0, };
	for (int i = 0; i < 5; i++)
	{
		switch (dice_list[i].get_eyes()) {
		case 1:
			cnt[0]++; break;
		case 2:
			cnt[1]++; break;
		case 3:
			cnt[2]++; break;
		case 4:
			cnt[3]++; break;
		case 5:
			cnt[4]++; break;
		case 6:
			cnt[5]++; break;
		}
	}
	return cnt;
}

void Chart::charting(Dice dice_list[])
{
	set_point(this->calculate(dice_list));
}

void Chart::set_point(int n)
{
	this->point = n;

}

int Chart::get_point()
{
	return this->point;
}

void Chart::set_used()
{
	this->is_used = true;
}

bool Chart::get_used()
{
	return is_used;
}


//NumberChart

NumberChart::NumberChart(int set_num)
{
	this->setting_number = set_num;
}

int NumberChart::calculate(Dice dice_list[])
{
	int* cnt = counting(dice_list);
	return cnt[setting_number - 1] * setting_number;
}

std::string NumberChart::get_info()
{
	return to_string(setting_number)  + " Number";
}



//ChaceChart

ChanceChart::ChanceChart()
{
	this->index = 7;
}

int ChanceChart::calculate(Dice dice_list[])
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += dice_list[i].get_eyes();
	}
	return sum;
}

string ChanceChart::get_info()
{
	return "Chance";
}


//FourOfKindChart

FourOfKindChart::FourOfKindChart()
{
	this->index = 8;
}

int FourOfKindChart::calculate(Dice dice_list[])
{
	int* cnt = counting(dice_list);
	int sum = 0;
	int check_foak = 0;
	for (int i = 0; i < 6; i++) 
	{
		sum += cnt[i] * (i + 1);
		if (cnt[i] >= 4)
		{
			check_foak = 1;
		}
	}

	if (check_foak == 1) 
	{
		return sum;
	}
	else 
	{
		return 0;
	}

}

string FourOfKindChart::get_info()
{
	return "Four of a Kind";
}


//FullhouseChart

FullhouseChart::FullhouseChart()
{
	this->index = 9;
}

int FullhouseChart::calculate(Dice dice_list[])
{
	int* cnt = counting(dice_list);

	int check_pair = 0, check_triple = 0;
	for (int i = 0; i < 6; i++) 
	{
		if (cnt[i] == 2) 
		{
			check_pair = 1;
		}
		if (cnt[i] == 3) 
		{
			check_triple = 1;
		}
	}

	if (check_pair + check_triple == 2) 
	{
		return 25;
	}
	else 
		return 0;
}

string FullhouseChart::get_info()
{
	return "Fullhouse";
}


//SmallStraightChart

SmallStraightChart::SmallStraightChart()
{
	this->index = 10;
}

int SmallStraightChart::calculate(Dice dice_list[])
{
	int* cnt = counting(dice_list);
	int check_straight = 0;
	for (int i = 0; i < 6; i++) 
	{
		if (cnt[i] >= 1) 
		{
			check_straight++;
			if (check_straight >= 4) 
			{
				return 25;
			}
		}
		else 
		{
			check_straight = 0;
		}
	}
	return 0;
}

string SmallStraightChart::get_info()
{
	return "Small Straight";
}


//LargeStraightChart

LargeStraightChart::LargeStraightChart()
{
	this->index = 11;
}

int LargeStraightChart::calculate(Dice dice_list[])
{
	int* cnt = counting(dice_list);
	int check_straight = 0;
	for (int i = 0; i < 6; i++) 
	{
		if (cnt[i] >= 1) 
		{
			check_straight++;
			if (check_straight >= 5) 
			{
				return 30;
			}
		}
		else 
		{
			check_straight = 0;
		}
	}
	return 0;
}

string LargeStraightChart::get_info()
{
	return "Large Straight";
}



//YatchChart

YatchChart::YatchChart()
{
	this->index = 12;
}

int YatchChart::calculate(Dice dice_list[])
{
	int* cnt = counting(dice_list);
	for (int i = 0; i < 6; i++)
	{
		if (cnt[i] == 5) 
		{
			return 50;
		}
	}
	return 0;
}

string YatchChart::get_info()
{
	return "Yatch";
}
