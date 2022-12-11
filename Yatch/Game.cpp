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

		cout << "주사위를 굴린다" << endl;

		cout << "DICE: ";
		for (int i = 0; i < 5; i++)
		{
			dc[i].roll();
			cout << i + 1 << ":[" << dc[i].get_eyes() << "] ";
		}
		cout << endl;

		//돌리고 싶은 주사위를 선택, 없으면 0을 선택
		do
		{
			cout << "주사위를 돌리시겠습니까?" << endl;
			cin >> input;
			if ((0 > input) || (input > 5))
				break;
			dc[input - 1].roll();

			system("cls");
			cout << input << "번째 주사위를 돌려서 " << dc[input - 1].get_eyes() << "가 나왔습니다\n";
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
			cout << "해당 값을 넣을 족보의 인덱스를 입력해 주십시요" << endl;
			cin >> input;
			if (!(input <= 12 && input > 0))
			{
				cout << "1 ~ 12의 값을 입력해 주세요" << endl;
				continue;
			}

			//사용한 값인지 확인
			if (player->cht[input - 1]->get_used() == true)
			{
				cout << "이미 사용된 값입니다" << endl;
				continue;
			}
			break;
		}

		//데이터를 넣어둔다
		player->cht[input - 1]->charting(dc);
		cout << player->cht[input - 1]->get_info() << " Chart Point : " << player->cht[input - 1]->get_point() << endl;
		//사용한 값으로 바꿈
		player->cht[input - 1]->set_used();

	}

	
	
	return 0;
}