#pragma once
#include "Game.h"


YatchGame::YatchGame()
{
	srand(time(NULL));
	player_number = 0;

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
		cout << "[" << i+1 << "]" << this->cht[i]->get_info() << " Chart Point : " << this->cht[i]->get_point() << endl;
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

void  YatchGame::multigame()
{
	Dice dice[5];
	string input = "";
	system("cls");
	cout << "플레이어 수를 입력해주세요" << endl;
	cin >> this->player_number;

	Player* player = new Player[this->player_number];

	for (int i = 0; i < player_number; i++)
	{
		cout << i+1 << "번째 플레이어의 이름을 입력해주세요" << endl;
		cin >> input;
		player[i].set_name(input);
	}

	for (int i = 1; i <= 12; i++)
	{
		for (int j = 0; j < player_number; j++)
		{
			system("cls");
			cout << "플레이어::" << player[j].get_name() 
				<< "의 " << i<< "번째 차례입니다." << endl;

			cout << "주사위를 돌립니다. " << endl
				<< "DICE: ";
			for (int i = 0; i < 5; i++)
			{
				dice[i].roll();
				cout << i + 1 << ":[" << dice[i].get_eyes() << "] ";
			}
			cout << endl;

			preview_point(dice);
			
			int dice_count = 3;
			do //주사위 선택 차례
			{
				vector <int> dice_vector;
				vector<int>::iterator it;

				cout << "주사위를 돌리시겠습니까? (Y/N)" << endl;
				cin >> input;
				if (input == "Y")
					;
				else if (input == "N")
					break;
				else
				{
					cout << "올바른 값을 입력해주세요." << endl;
					continue;
				}

				
				do //주사위 선택 반복문
				{
					cout << "돌릴 주사위를 입력해주세요(1~5)." << endl;
					cin >> input;
					if (input == "1")
					{
						dice_vector.push_back(1);
					}
					else if (input == "2")
					{
						dice_vector.push_back(2);
					}
					else if (input == "3")
					{
						dice_vector.push_back(3);
					}
					else if (input == "4")
					{
						dice_vector.push_back(4);
					}
					else if (input == "5")
					{
						dice_vector.push_back(5);
					}
					else
					{
						cout << "잘못된 값입니다" << endl;
						continue;
					}

					sort(dice_vector.begin(), dice_vector.end());
					dice_vector.erase(unique(dice_vector.begin(), dice_vector.end()), dice_vector.end());

					cout << "선택한 주사위 목록: ";
					for (int k = 0; k < dice_vector.size(); k++)
					{
						cout << dice_vector.at(k) << "번째 ";
					}
					cout << endl;

					cout << "더 선택하시겠습니까?(Y/N)" << endl;
					cin >> input;
					if (input == "Y")
						continue;
					else if (input == "N")
						break;
					else
					{
						cout << "지정된 값이 아니기에 더 선택하지 않습니다" << endl;
						break;
					}
				} while (1);
				
				system("cls");
				
				for (int k = 0; k < dice_vector.size(); k++)
				{
					cout << dice_vector[k] << "번째 주사위를 굴립니다." << endl;
					dice[dice_vector[k]-1].roll();
				}
				

				for (int i = 0; i < 5; i++)
				{
					cout << i + 1 << ":[" << dice[i].get_eyes() << "] ";
				}
				cout << endl;
				dice_count--;
				

				if (dice_count <= 0)
				{
					cout << "주사위를 굴릴 수 있는 횟수가 없습니다." << endl;
					break;
				}
				preview_point(dice);
				cout << "주사위를 더 굴리시겠습니까?(Y/N)" << endl;
				cin >> input;
				if (input == "Y")
					;
				else if (input == "N")
					break;
				else
				{
					cout << "올바른 값을 입력해주세요." << endl;
					continue;
				}
			} while (dice_count > 0);

			system("cls");
			preview_point(dice);

			int input_int = 0;
			while (true)
			{
				cout << "해당 값을 넣을 족보의 인덱스를 입력해 주십시요" << endl;
				cin >> input_int;
				if (!(input_int <= 12 && input_int > 0))
				{
					cout << "1 ~ 12의 값을 입력해 주세요" << endl;
					continue;
				}

				//사용한 값인지 확인
				if (player[j].cht[input_int - 1]->get_used() == true)
				{
					cout << "이미 사용된 값입니다" << endl;
					continue;
				}
				break;
			}

			//데이터를 넣어둔다
			player[j].cht[input_int - 1]->charting(dice);
			cout << player[j].cht[input_int - 1]->get_info() << " Chart Point : " << player[j].cht[input_int - 1]->get_point() << endl;
			//사용한 값으로 바꿈
			player[j].cht[input_int - 1]->set_used();

		}
	}

	vector<int> v;
	for (int i = 0; i < player_number; i++)
	{
		v.push_back(player[i].calculate_total_point());
		
	}

	int max_index = max_element(v.begin(), v.end()) - v.begin();

	system("cls");
	cout << "\n\n\n" << player[max_index].get_name() << "가 승리했습니다.";
	
	ofstream fout;
	fout.open("YatchLog.txt");
	if (!fout)
	{
		cout << "YatchLog.txt 파일을 찾지 못하였습니다." << endl;
	}

	for (int i = 0; i < player_number; i++)
	{	
		fout << player[i].get_name() << "의 점수: " << player[i].get_point() << endl;
		fout << player[i].get_name() << "의 차트: " << endl;

		for (int j = 0; j < 12; j++)
		{
			fout << player[i].cht[j]->get_info() << "Chart Point: " << player[i].cht[j]->get_point() << endl;
		}
		fout << endl;
		
	}
	fout.close();
}