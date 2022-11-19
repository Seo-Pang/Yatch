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
	//�ֻ����� ���� ���� ���� cnt�� return�ؼ� �޾ƿ��� �Լ�
	//��ǻ� ChanceChart�� ������ ������ Ŭ�������� ����ϱ� ������ ����
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
	int setting_number; // 8������ 12������ (�� ���� ��Ʈ�� � ���ڸ� ����ϰ� �ִ����� ���� ����
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
	int FourOfAKind(int cnt[]) // Four of a Kind ���� üũ�� �Լ�
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

	int FullHouse(int cnt[]) // Full House ���� üũ�� �Լ�
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

	int SmallStraight(int cnt[]) // Small Straight ���� üũ�� �Լ�
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

	int LargeStraight(int cnt[]) // Large Straight ���� üũ�� �Լ�
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

	int Yacht(int cnt[]) // Yacht ���� üũ�� �Լ�
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