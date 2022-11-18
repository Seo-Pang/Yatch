#include <iostream>
#include "Dice.h"

class Chart
{
	int point = 0;
protected:
	// Chart�� DICE�� �ְ� �̸� ���� ����ϴ� �Լ�, ���� �Լ�
	virtual int calculate(Dice dice_list[]) = 0; 

	//Chart�� ����Ʈ�� ���� �Է��ϴ� �Լ�
	void set_point(int n) { this->point = n; } 

public:
	//����Ʈ�� ���(calculate)�� �ִ� �Լ�
	void charting(Dice dice_list[])
	{
		set_point( this->calculate(dice_list));
	}

	//����ڿ��� ������ �����ϴ� �Լ�
	int get_point()
	{
		return this->point;
	}

	//� �Լ��� �������� �����ϴ� �Լ�
	virtual int get_info() = 0;
	
	Chart() { ; }
};

class NumberChart : public Chart
{
	int setting_number; //1���� 6����, �� ���� ��Ʈ(Aces, Deuces... )�� � ���ڸ� ����ϰ� �ִ����� ���� ����
protected:
	//����Ʈ�� ���(calculate)�� �ִ� �Լ�
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