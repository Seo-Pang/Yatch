#pragma once
#include <iostream>
#include "Dice.h"

using namespace std;

class Chart
{
private:
	//�� ������ ����Ʈ
	int point = 0;

	//������ ���� ���� �� ����
	bool is_used = false;

protected:
	//1������ 12������ �� ������ �ε����� ���
	int index;

	// Chart�� DICE�� �ְ� �̸� ���� ����ϴ� �Լ�, ���� �Լ�
	virtual int calculate(Dice dice_list[]) = 0; 

	//Chart�� ����Ʈ�� ���� �Է��ϴ� �Լ�
	void set_point(int n);

public:
	//�ֻ����� ���� ���� ���� cnt�� return�ؼ� �޾ƿ��� �Լ�
	//��ǻ� ChanceChart�� ������ ������ Ŭ�������� ����ϱ� ������ ����
	int* counting(Dice dice_list[]);

	//����Ʈ�� ���(calculate)�� �ִ� �Լ�
	void charting(Dice dice_list[]);

	//������ ��ȯ�ϴ� �Լ�
	int get_point();

	//UI.h ���� ��� (ǥ��Ǵ� ������ ����)
	void set_UIpoint(int n);

	void set_used();
	bool get_used();

	//� �Լ��� �������� �����ϴ� �Լ�
	virtual std::string get_info() = 0; 

	Chart();
};

class NumberChart : public Chart
{
	int setting_number; //1���� 6����, �� ���� ��Ʈ(Aces, Deuces... )�� � ���ڸ� ����ϰ� �ִ����� ���� ����

protected:
	//����Ʈ�� ���(calculate)�� �ִ� �Լ�
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
��� �׸�
-1. Aces : 1�� ���� �ֻ����� ��
-2. Twos : 2�� ���� �ֻ����� ��
-3. Threes : 3�� ���� �ֻ����� ��
-4. Fours : 4�� ���� �ֻ����� ��
-5. Fives : 5�� ���� �ֻ����� ��
-6. Sixes : 6�� ���� �ֻ����� ��
�غ��ʽ� : ����׸� ���� 63���� ���� ��� +35��

�ϴ� �׸�
-7.Chance : �ֻ��� 5���� ���� �� ��
-8. Four of a kind : �ֻ��� 4���� ���� ������ ��, �ֻ��� 5���� ��
-9. Full house : ���� ������ �ֻ����� ���� 3���� 2���� ���� ��, +25��
-10. Small straight : �ֻ��� 4���� ���� �̾����� ���� ��, +30��
-11. Large straight : �ֻ��� 5���� ���� �̾����� ���� ��, +40��
-12. Yatch : �ֻ��� 5���� ���� ��� ���� ��, +50��
*/