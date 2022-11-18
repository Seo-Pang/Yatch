#include <iostream>
#include "Dice.h"

class Chart
{
	int point = 0;
protected:
	// Chart에 DICE를 넣고 이를 직접 계산하는 함수, 가상 함수
	virtual int calculate(Dice dice_list[]) = 0; 

	//Chart에 포인트를 직접 입력하는 함수
	void set_point(int n) { this->point = n; } 

public:
	//포인트를 계산(calculate)해 넣는 함수
	void charting(Dice dice_list[])
	{
		set_point( this->calculate(dice_list));
	}

	//사용자에게 점수를 전달하는 함수
	int get_point()
	{
		return this->point;
	}

	//어떤 함수의 정보인지 전달하는 함수
	virtual int get_info() = 0;
	
	Chart() { ; }
};

class NumberChart : public Chart
{
	int setting_number; //1부터 6까지, 각 숫자 차트(Aces, Deuces... )가 어떤 숫자를 담당하고 있는지에 대한 정보
protected:
	//포인트를 계산(calculate)해 넣는 함수
	virtual int calculate(Dice dice_list[])
	{
		int sum = 0;
		for (int i = 0; i < 5; i++)
		{
			
			if (dice_list[i].get_eyes() == setting_number)
			{
				sum += dice_list[i].get_eyes();
			}
		}
		return sum;
	}
public:
	NumberChart(int set_num)
	{
		this->setting_number = set_num;
	}

	virtual int get_info()
	{
		return setting_number;
	}

};

class ChanceChart : public Chart
{
protected:
	virtual int calculate(Dice dice_list[])
	{	
		int sum = 0;
		for (int i = 0; i < 5; i++)
		{
				sum += dice_list[i].get_eyes();
		}
		return sum;
	}
public:
	ChanceChart() { ; }
	int get_info()
	{
		return 7;
	}
};


/*
상단 항목
-1. Aces : 1이 나온 주사위의 합
-2. Twos : 2이 나온 주사위의 합
-3. Threes : 3이 나온 주사위의 합
-4. Fours : 4이 나온 주사위의 합
-5. Fives : 5이 나온 주사위의 합
-6. Sixes : 6이 나온 주사위의 합
※보너스 : 상단항목 합이 63점을 넘을 경우 +35점

하단 항목
-7.Chance : 주사위 5개의 눈의 총 합
-8. Four of a kind : 주사위 4개의 눈이 동일할 때, 주사위 5개의 합
-9. Full house : 눈이 동일한 주사위가 각각 3개와 2개가 있을 때, +25점
-10. Small straight : 주사위 4개의 눈이 이어지는 수일 때, +30점
-11. Large straight : 주사위 5개의 눈이 이어지는 수일 때, +40점
-12. Yatch : 주사위 5개의 눈이 모두 같을 때, +50점
*/