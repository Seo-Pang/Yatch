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
	//주사위의 눈에 따른 값을 cnt로 return해서 받아오는 함수
	//사실상 ChanceChart를 제외한 나머지 클래스에서 사용하기 때문에 생성
	int* counting(Dice dice_list[]) {
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
		int* cnt = counting(dice_list);

		return cnt[setting_number - 1] * setting_number;
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

class SpecialChart : public Chart
{
	int setting_number; // 8번부터 12번까지 (각 숫자 차트가 어떤 숫자를 담당하고 있는지에 대한 정보
protected:
	virtual int calculate(Dice dice_list[])
	{
		int* cnt = counting(dice_list);

		switch (this->setting_number) {
		case 8:
			return FourOfAKind(cnt);
		case 9:
			return FullHouse(cnt);
		case 10:
			return SmallStraight(cnt);
		case 11:
			return LargeStraight(cnt);
		case 12:
			return Yacht(cnt);
		}
	}

public:
	int FourOfAKind(int cnt[]) // Four of a Kind 족보 체크용 함수
	{
		int sum = 0;
		int check_foak = 0;
		for (int i = 0; i < 6; i++) {
			sum += cnt[i] * (i + 1);
			if (cnt[i] >= 4) {
				check_foak = 1;
			}
		}
		if (check_foak == 1) {
			return sum;
		}
		else {
			return 0;
		}
	}

	int FullHouse(int cnt[]) // Full House 족보 체크용 함수
	{
		int check_pair = 0, check_triple = 0;
		for (int i = 0; i < 6; i++) {
			if (cnt[i] == 2) {
				check_pair = 1;
			}
			if (cnt[i] == 3) {
				check_triple = 1;
			}
		}
		if (check_pair + check_triple == 2) {
			return 25;
		}
		return 0;
	}

	int SmallStraight(int cnt[]) // Small Straight 족보 체크용 함수
	{
		int check_straight = 0;
		for (int i = 0; i < 6; i++) {
			if (cnt[i] >= 1) {
				check_straight++;
				if (check_straight >= 4) {
					return 30;
				}
			}
			else {
				check_straight = 0;
			}
		}
		return 0;
	}

	int LargeStraight(int cnt[]) // Large Straight 족보 체크용 함수
	{
		int check_straight = 0;
		for (int i = 0; i < 6; i++) {
			if (cnt[i] >= 1) {
				check_straight++;
				if (check_straight >= 5) {
					return 40;
				}
			}
			else {
				check_straight = 0;
			}
		}
		return 0;
	}

	int Yacht(int cnt[]) // Yacht 족보 체크용 함수
	{
		for (int i = 0; i < 6; i++) {
			if (cnt[i] == 5) {
				return 50;
			}
		}
		return 0;
	}

	SpecialChart(int set_num) {
		this->setting_number = set_num + 7;
	}

	virtual int get_info()
	{
		return setting_number;
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