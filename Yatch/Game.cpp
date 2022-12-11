#pragma once
#include "Game.h"


YatchGame::YatchGame()
{
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

void YatchGame::preview_point(Dice dice_list[])
{
	for (int i = 0; i < 12; i++)
	{
		this->cht[i]->charting(dice_list);
		cout << this->cht[i]->get_info() << " Chart Point : " << this->cht[i]->get_point() << endl;
	}
}

//Single Game
int YatchGame::single_game()
{
	srand(time(NULL));
	Dice dc[5];
	int input;
	Player* player = new Player();

	for (int i = 0; i < 12; i++)
	{

		cout << "�ֻ����� ������" << endl;

		cout << "DICE: ";
		for (int i = 0; i < 5; i++)
		{
			dc[i].roll();
			cout << i + 1 << ":[" << dc[i].get_eyes() << "] ";
		}
		cout << endl;

		//������ ���� �ֻ����� ����, ������ 0�� ����
		do
		{
			cout << "�ֻ����� �����ðڽ��ϱ�?" << endl;
			cin >> input;
			if ((0 > input) || (input > 5))
				break;
			dc[input - 1].roll();

			system("cls");
			cout << input << "��° �ֻ����� ������ " << dc[input - 1].get_eyes() << "�� ���Խ��ϴ�\n";
			cout << "DICE: ";
			for (int i = 0; i < 5; i++)
			{
				cout << i + 1 << ":[" << dc[i].get_eyes() << "] ";
			}
			cout << endl;

			preview_point(dc);

		} while (input);

		input = 0;

		while (true)
		{
			cout << "�ش� ���� ���� ������ �ε����� �Է��� �ֽʽÿ�" << endl;
			cin >> input;
			if (!(input <= 12 && input > 0))
			{
				cout << "1 ~ 12�� ���� �Է��� �ּ���" << endl;
				continue;
			}

			//����� ������ Ȯ��
			if (player->cht[input - 1]->get_used() == true)
			{
				cout << "�̹� ���� ���Դϴ�" << endl;
				continue;
			}
			break;
		}

		//�����͸� �־�д�
		player->cht[input - 1]->charting(dc);
		cout << player->cht[input - 1]->get_info() << " Chart Point : " << player->cht[input - 1]->get_point() << endl;
		//����� ������ �ٲ�
		player->cht[input - 1]->set_used();

	}

	
	
	return 0;
}