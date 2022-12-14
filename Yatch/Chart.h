#pragma once
#include <iostream>
#include "Dice.h"

using namespace std;

class Chart
{
private:
	//각 족보별 포인트
	int point = 0;

	//족보는 각각 사용될 수 없음
	bool is_used = false;

protected:
	//1번부터 12번까지 각 족보의 인덱스를 기록
	int index;

	// Chart에 DICE를 넣고 이를 직접 계산하는 함수, 가상 함수
	virtual int calculate(Dice dice_list[]) = 0; 

	//Chart에 포인트를 직접 입력하는 함수
	void set_point(int n);

public:
	//주사위의 눈에 따른 값을 cnt로 return해서 받아오는 함수
	//사실상 ChanceChart를 제외한 나머지 클래스에서 사용하기 때문에 생성
	int* counting(Dice dice_list[]);

	//포인트를 계산(calculate)해 넣는 함수
	void charting(Dice dice_list[]);

	//점수를 반환하는 함수
	int get_point();

	//UI.h 한정 사용 (표기되는 점수를 설정)
	void set_UIpoint(int n);

	void set_used();
	bool get_used();

	//어떤 함수의 정보인지 전달하는 함수
	virtual std::string get_info() = 0; 

	Chart();
};

class NumberChart : public Chart
{
	int setting_number; //1부터 6까지, 각 숫자 차트(Aces, Deuces... )가 어떤 숫자를 담당하고 있는지에 대한 정보

protected:
	//포인트를 계산(calculate)해 넣는 함수
	virtual int calculate(Dice dice_list[]);

public:
	NumberChart(int set_num);
	virtual std::string get_info();

};

class SpecialChart : public Chart
{
public:
	virtual std::string get_info() = 0;
};

class ChanceChart : public SpecialChart
{
protected:
	virtual int calculate(Dice dice_list[]);
public:
	ChanceChart();
	string get_info();
};

class FourOfKindChart : public SpecialChart
{
protected:
	int calculate(Dice dice_list[]);
public:
	FourOfKindChart();
	string get_info();
};

class FullhouseChart : public SpecialChart
{
protected:
	int calculate(Dice dice_list[]);
public:
	FullhouseChart();
	string get_info();
};

class SmallStraightChart : public SpecialChart
{
protected:
	int calculate(Dice dice_list[]);
public:
	SmallStraightChart();
	string get_info();
};

class LargeStraightChart : public SpecialChart
{
protected:
	int calculate(Dice dice_list[]);
public:
	LargeStraightChart();
	string get_info();
};

class YatchChart : public SpecialChart
{
protected:
	int calculate(Dice dice_list[]);
public:
	YatchChart();
	string get_info();
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