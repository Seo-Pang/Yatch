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

void  YatchGame::multigame()
{
	Dice dice[5];
	string input = "";
	system("cls");
	cout << "�÷��̾� ���� �Է����ּ���" << endl;
	cin >> this->player_number;

	Player* player = new Player[this->player_number];

	for (int i = 0; i < player_number; i++)
	{
		cout << i+1 << "��° �÷��̾��� �̸��� �Է����ּ���" << endl;
		cin >> input;
		player[i].set_name(input);
	}

	for (int i = 1; i <= 12; i++)
	{
		for (int j = 0; j < player_number; j++)
		{
			system("cls");
			cout << "�÷��̾�::" << player[j].get_name() 
				<< "�� " << i<< "��° �����Դϴ�." << endl;

			cout << "�ֻ����� �����ϴ�. " << endl
				<< "DICE: ";
			for (int i = 0; i < 5; i++)
			{
				dice[i].roll();
				cout << i + 1 << ":[" << dice[i].get_eyes() << "] ";
			}
			cout << endl;

			preview_point(dice);
			
			int dice_count = 3;
			do //�ֻ��� ���� ����
			{
				vector <int> dice_vector;
				vector<int>::iterator it;

				cout << "�ֻ����� �����ðڽ��ϱ�? (Y/N)" << endl;
				cin >> input;
				if (input == "Y")
					;
				else if (input == "N")
					break;
				else
				{
					cout << "�ùٸ� ���� �Է����ּ���." << endl;
					continue;
				}

				
				do //�ֻ��� ���� �ݺ���
				{
					cout << "���� �ֻ����� �Է����ּ���(1~5)." << endl;
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
						cout << "�߸��� ���Դϴ�" << endl;
						continue;
					}

					sort(dice_vector.begin(), dice_vector.end());
					dice_vector.erase(unique(dice_vector.begin(), dice_vector.end()), dice_vector.end());

					cout << "������ �ֻ��� ���: ";
					for (int k = 0; k < dice_vector.size(); k++)
					{
						cout << dice_vector.at(k) << "��° ";
					}
					cout << endl;

					cout << "�� �����Ͻðڽ��ϱ�?(Y/N)" << endl;
					cin >> input;
					if (input == "Y")
						continue;
					else if (input == "N")
						break;
					else
					{
						cout << "������ ���� �ƴϱ⿡ �� �������� �ʽ��ϴ�" << endl;
						break;
					}
				} while (1);
				
				system("cls");
				
				for (int k = 0; k < dice_vector.size(); k++)
				{
					cout << dice_vector[k] << "��° �ֻ����� �����ϴ�." << endl;
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
					cout << "�ֻ����� ���� �� �ִ� Ƚ���� �����ϴ�." << endl;
					break;
				}
				preview_point(dice);
				cout << "�ֻ����� �� �����ðڽ��ϱ�?(Y/N)" << endl;
				cin >> input;
				if (input == "Y")
					;
				else if (input == "N")
					break;
				else
				{
					cout << "�ùٸ� ���� �Է����ּ���." << endl;
					continue;
				}
			} while (dice_count > 0);

			system("cls");
			preview_point(dice);

			int input_int = 0;
			while (true)
			{
				cout << "�ش� ���� ���� ������ �ε����� �Է��� �ֽʽÿ�" << endl;
				cin >> input_int;
				if (!(input_int <= 12 && input_int > 0))
				{
					cout << "1 ~ 12�� ���� �Է��� �ּ���" << endl;
					continue;
				}

				//����� ������ Ȯ��
				if (player[j].cht[input_int - 1]->get_used() == true)
				{
					cout << "�̹� ���� ���Դϴ�" << endl;
					continue;
				}
				break;
			}

			//�����͸� �־�д�
			player[j].cht[input_int - 1]->charting(dice);
			cout << player[j].cht[input_int - 1]->get_info() << " Chart Point : " << player[j].cht[input_int - 1]->get_point() << endl;
			//����� ������ �ٲ�
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
	cout << "\n\n\n" << player[max_index].get_name() << "�� �¸��߽��ϴ�.";
	
	ofstream fout;
	fout.open("YatchLog.txt");
	if (!fout)
	{
		cout << "YatchLog.txt ������ ã�� ���Ͽ����ϴ�." << endl;
	}

	for (int i = 0; i < player_number; i++)
	{	
		fout << player[i].get_name() << "�� ����: " << player[i].get_point() << endl;
		fout << player[i].get_name() << "�� ��Ʈ: " << endl;

		for (int j = 0; j < 12; j++)
		{
			fout << player[i].cht[j]->get_info() << "Chart Point: " << player[i].cht[j]->get_point() << endl;
		}
		fout << endl;
		
	}
	fout.close();
}