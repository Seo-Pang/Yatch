#pragma once
#include "Game.h"

//���� UI ��� �ڵ�
string GameUI::get_playerName(int n) {
	string playerName;
	system("cls");
	cout << "\n\n\n";
	cout << "                ��������������������������������������������\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��        ��      ��    ������    ������    ��      ��    ������        ��\n";
	cout << "                ��        ��      ��    ��      ��    ��            ��      ��        ��            ��\n";
	cout << "                ��        ������    ��      ��    ��            ��      ��        ��            ��\n";
	cout << "                ��            ��        ������    ��            ������        ��            ��\n";
	cout << "                ��            ��        ��      ��    ��            ��      ��        ��            ��\n";
	cout << "                ��            ��        ��      ��    ��            ��      ��        ��            ��\n";
	cout << "                ��            ��        ��      ��    ������    ��      ��        ��            ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                  �÷��̾� " << n << "���� �̸��� �Ʒ� �Է�â�� �����ּ���.                 ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                         (�̸� ���� -> ����� 3���� �ۼ�)                         ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��������������������������������������������\n";
	cout << "                  >> ";
	cin >> playerName;
	return playerName;
}

void GameUI::play_gameUI(Dice dc[], Player* player, Chart* previewCht[], int rollChance, bool select_rerollDice[]) {
	Chart* UIcht[12];
	string select_rerollDicestr[5];

	for (int i = 0; i < 5; i++) {
		if (select_rerollDice[i]) {
			select_rerollDicestr[i] = "Y";
		}
		else {
			select_rerollDicestr[i] = "N";
		}
	}

	for (int i = 0; i < 12; i++) {
		if (player->cht[i]->get_used() == true) {
			UIcht[i]->set_UIpoint(player->cht[i]->get_point());
		}
		else {
			UIcht[i]->set_UIpoint(previewCht[i]->get_point());
		}
	}

	system("cls");
	cout << "\n\n\n";
	cout << "                ��������������������������������������������\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��          ======       Y   A   C   H   T     G   A   M   E       =======          ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                 �÷��̾� �̸� : " << player->get_name() << "      �����ִ� �� �� : " << player->get_leftturn() << " ȸ                  ��\n";
	cout << "                ��                �����ִ� �ֻ��� ������ ���� :                " << rollChance << " ȸ                 ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                [ " << dc[0].get_eyes() << " ]      [ " << dc[1].get_eyes() << " ]      [ " << dc[2].get_eyes() << " ]      [ " << dc[3].get_eyes() << " ]      [ " << dc[4].get_eyes() << " ]                 ��\n";
	cout << "                ��                [ " << select_rerollDicestr[0] << " ]      [ " << select_rerollDicestr[1] << " ]      [ " << select_rerollDicestr[2] << " ]      [ " << select_rerollDicestr[3] << " ]      [ " << select_rerollDicestr[4] << " ]                 ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��          ======      C   H   A   R   T   P   O   I   N   T      =======          ��\n";
	cout << "                ��                                                                                  ��\n";
	 printf("                ��        %s[01] Aces               %3d ��  %s[07] Chance             %3d ��        ��\n", player->get_chartused(1), UIcht[0]->get_point(), player->get_chartused(7), UIcht[6]->get_point());
	 printf("                ��        %s[02] Twos               %3d ��  %s[08] Four of a Kind     %3d ��        ��\n", player->get_chartused(2), UIcht[1]->get_point(), player->get_chartused(8), UIcht[7]->get_point());
	 printf("                ��        %s[03] Threes             %3d ��  %s[19] Full House         %3d ��        ��\n", player->get_chartused(3), UIcht[2]->get_point(), player->get_chartused(9), UIcht[8]->get_point());
	 printf("                ��        %s[04] Fours              %3d ��  %s[10] Small Straight     %3d ��        ��\n", player->get_chartused(4), UIcht[3]->get_point(), player->get_chartused(10), UIcht[9]->get_point());
	 printf("                ��        %s[05] Fives              %3d ��  %s[11] Large Straight     %3d ��        ��\n", player->get_chartused(5), UIcht[4]->get_point(), player->get_chartused(11), UIcht[10]->get_point());
	 printf("                ��        %s[06] Sixes              %3d ��  %s[12] Yacht              %3d ��        ��\n", player->get_chartused(6), UIcht[5]->get_point(), player->get_chartused(12), UIcht[11]->get_point());
	cout << "                ��                                                                                  ��\n";
	 printf("                ��          ���ʽ� ���� :           %3d ��  �� ���� :               %3d ��          ��\n", player->get_bonus(), player->get_result());
	cout << "                ��                                                                                  ��\n";
	cout << "                ��������������������������������������������\n\n";
}

int GameUI::gameSet_UI(Player* player, int high_score) {
	int select_command = 0;
	system("cls");
	cout << "\n\n\n";
	cout << "                ��������������������������������������������\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��      ���      ���    �����  �����        �����  �����  �����    ��\n";
	cout << "                ��    ��        ��    ��  �� �� ��  ��              ��        ��           ��       ��\n";
	cout << "                ��    ��        ��    ��  �� �� ��  ��              ��        ��           ��       ��\n";
	cout << "                ��    ��  ���  �����  �� �� ��  ����          �����  ����       ��       ��\n";
	cout << "                ��    ��    ��  ��    ��  �� �� ��  ��                    ��  ��           ��       ��\n";
	cout << "                ��    ��    ��  ��    ��  �� �� ��  ��                    ��  ��           ��       ��\n";
	cout << "                ��      ���    ��    ��  �� �� ��  �����        �����  �����     ��       ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                              ������ ����Ǿ����ϴ�.                              ��\n";
	cout << "                ��                                                                                  ��\n";
	 printf("                ��                      %3s  WIN!                       %3d ��                      ��\n", player->get_name(), high_score);
	cout << "                ��                      SMU  WIN!                                                   ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                      202010969                     �� �� ��                      ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                      202111063                     �� �� ��                      ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��������������������������������������������\n";
	while (1) {
		select_command = _getch();
		if (select_command == 49) //1�� Ŀ�ǵ� (���� �ٽ��ϱ�)
		{
			return 1;
		}
		else  //2�� Ŀ�ǵ� (���� ����)
		{
			return 0;
		}
	}
}

int YatchGame::select_command() {
	int select_command = 0;
	cout << "                                    �ٽ� �ֻ��� ������ : 1�� / ���� �����ϱ� : 2��\n";
	cout << "                                    ��ɾ �Է��� �ּ���   (Ű���带 �����ּ���)";
	while (1) {
		select_command = _getch();
		if (select_command == 49) //1�� Ŀ�ǵ� (Ű���� 1)
		{
			return 1;
		}
		else if (select_command == 50) //2�� Ŀ�ǵ� (Ű���� 2)
		{
			return 2;
		}
	}
}

int YatchGame::select_command_rollDice(bool* select_rerollDice[]) {
	int select_command = 49;
	cout << "                                    Ű���带 ���� �ٽ� ���� �ֻ����� ������ �ּ���\n";
	cout << "                                 1���� 5������ ���ڰ� �ƴ� Ű���带 �Է� �� ����˴ϴ�";
	while ((select_command >= 49 && select_command <= 53) || select_command == 0) {
		select_command = _getch();
		if (select_command == 49) {
			select_rerollDice[0] != select_rerollDice[0];
		}
		else if (select_command == 50) {
			select_rerollDice[1] != select_rerollDice[1];
		}
		else if (select_command == 51) {
			select_rerollDice[2] != select_rerollDice[2];
		}
		else if (select_command == 52) {
			select_rerollDice[3] != select_rerollDice[3];
		}
		else if (select_command == 53) {
			select_rerollDice[4] != select_rerollDice[4];
		}
	}

	return 0;
}

int YatchGame::select_command_setChart(Player* player) {
	int select_command = 0;
	cout << "                                      ������� ���� ������ �� / ����� ������ �� \n";
	cout << "                               ������� ���� ���� �� ����� ������ ��ȣ�� �����ּ��� >> ";
	cin >> select_command;

	return select_command;
}


YatchGame::YatchGame()
{
	for (int i = 0; i < 6; i++)
	{
		this->cht[i] = new NumberChart(i + 1);
	}
	this->cht[6] = new ChanceChart();
	this->cht[7] = new FourOfKindChart();
	this->cht[8] = new FullhouseChart();
	this->cht[9] = new SmallStraightChart();
	this->cht[10] = new LargeStraightChart();
	this->cht[11] = new YatchChart();
}

void YatchGame::preview_point(Dice dice_list[])
{
	for (int n = 0; n < 12; n++) {
		this->cht[n]->charting(dice_list);
	}
	/*for (int i = 0; i < 12; i++)
	{
		this->cht[i]->charting(dice_list);
		cout << this->cht[i]->get_info() << " Chart Point : " << this->cht[i]->get_point() << endl;
	}*/
}

void YatchGame::reset_rollChance() {
	this->use_roll = 3;
}

int YatchGame::get_rollChance() {
	return this->use_roll;
}

void YatchGame::count_rollChance() {
	this->use_roll--;
}

void YatchGame::set_rerollDice(bool* select_rerollDice[]) {
	for (int i = 0; i < 5; i++) {
		this->select_rerollDice[i] = select_rerollDice[i];
	}
}

bool* YatchGame::get_rerollDice() {
	return this->select_rerollDice;
}

bool YatchGame::get_rerollDice_once(int n) {
	return this->select_rerollDice[n];
}

void YatchGame::reset_rerollDice() {
	for (int i = 0; i < 5; i++) {
		this->select_rerollDice[i] = true;
	}
}

//Single Game
/*int YatchGame::single_game()
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

			for (int i = 0; i < 12; i++) {
				preview_point(dc, i);
			}

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
*/

int YatchGame::play_game(int player_number) {

	srand(time(NULL));
	Dice dc[5];
	GameUI gameui;
	int input;
	int play_turn = 12;
	Player* player = (Player*)malloc(sizeof(Player) * player_number);
	bool saveGameResult;
	int player_cmd = 0;
	int use_roll = 3;
	bool* select_rerollDice[5] = { false, };
	
	for (int i = 0; i < player_number; i++) {
		player[i].set_name(gameui.get_playerName(i));
		player[i].reset_leftturn();
		player[i].reset_point();
	}

	while (player[player_number].get_leftturn() > 0) { // ������ �÷��̾��� ���� ���� 1�� �� ������
		for (int i = 0; i < player_number; i++) { // �÷��̾� �ο� ����ŭ ����
			player[player_number].set_playturn();
			reset_rollChance();
			reset_rerollDice();
			count_rollChance();
			for (int i = 0; i < 5; i++) {
				dc[i].roll();
			}
			preview_point(dc);
			while (player[player_number].get_playturn()) {
				gameui.play_gameUI(dc, &player[player_number], this->cht, get_rollChance(), get_rerollDice());
				player_cmd = gameui.select_command();
				switch (player_cmd) {
				case 1:
					gameui.play_gameUI(dc, &player[player_number], this->cht, get_rollChance(), get_rerollDice());
					if(select_command_rollDice(select_rerollDice) == 0)
						set_rerollDice(select_rerollDice);
						gameui.play_gameUI(dc, &player[player_number], this->cht, get_rollChance(), get_rerollDice());
						Sleep(2000);
						count_rollChance();
						for (int i = 0; i < 5; i++) {
							if (get_rerollDice_once(i) == true) {
								dc[i].roll();
							}
						}
					break;
				case 2:
					while (1) {
						gameui.play_gameUI(dc, &player[player_number], this->cht, get_rollChance(), get_rerollDice());
						int select_cht = select_command_setChart(&player[player_number]) - 1;
						if (!player[player_number].cht[select_cht]->get_used())
							continue;

						player[player_number].cht[select_cht]->charting(dc);
						player[player_number].use_leftturn();
						break;
					}
					break;
				}
				if (play_turn != player[player_number].get_leftturn()) {
					player[player_number].set_playturn();
					Sleep(2000);
				}
			}
		}
	}

	int high_score = 0;
	int high_user = 0;

	for (int i = 0; i < player_number; i++) {
		if (player[i].get_point() > high_score) {
			high_score = player[i].get_point();
			high_user = i;
		}
	}

	return gameui.gameSet_UI(&player[high_user], high_score);

}