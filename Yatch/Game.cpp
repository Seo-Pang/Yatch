#pragma once
#include "Game.h"

//게임 UI 출력 코드
string GameUI::get_playerName(int n) {
	string playerName;
	system("cls");
	cout << "\n\n\n";
	cout << "                ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■        □      □    □□□□□    □□□□□    □      □    □□□□□        ■\n";
	cout << "                ■        □      □    □      □    □            □      □        □            ■\n";
	cout << "                ■        □□□□□    □      □    □            □      □        □            ■\n";
	cout << "                ■            □        □□□□□    □            □□□□□        □            ■\n";
	cout << "                ■            □        □      □    □            □      □        □            ■\n";
	cout << "                ■            □        □      □    □            □      □        □            ■\n";
	cout << "                ■            □        □      □    □□□□□    □      □        □            ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                  플레이어 " << n << "님의 이름을 아래 입력창에 적어주세요.                 ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                         (이름 조건 -> 영어로 3글자 작성)                         ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
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
	cout << "                ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■          ======       Y   A   C   H   T     G   A   M   E       =======          ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                 플레이어 이름 : " << player->get_name() << "      남아있는 턴 수 : " << player->get_leftturn() << " 회                  ■\n";
	cout << "                ■                남아있는 주사위 굴리기 찬스 :                " << rollChance << " 회                 ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                [ " << dc[0].get_eyes() << " ]      [ " << dc[1].get_eyes() << " ]      [ " << dc[2].get_eyes() << " ]      [ " << dc[3].get_eyes() << " ]      [ " << dc[4].get_eyes() << " ]                 ■\n";
	cout << "                ■                [ " << select_rerollDicestr[0] << " ]      [ " << select_rerollDicestr[1] << " ]      [ " << select_rerollDicestr[2] << " ]      [ " << select_rerollDicestr[3] << " ]      [ " << select_rerollDicestr[4] << " ]                 ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■          ======      C   H   A   R   T   P   O   I   N   T      =======          ■\n";
	cout << "                ■                                                                                  ■\n";
	 printf("                ■        %s[01] Aces               %3d 점  %s[07] Chance             %3d 점        ■\n", player->get_chartused(1), UIcht[0]->get_point(), player->get_chartused(7), UIcht[6]->get_point());
	 printf("                ■        %s[02] Twos               %3d 점  %s[08] Four of a Kind     %3d 점        ■\n", player->get_chartused(2), UIcht[1]->get_point(), player->get_chartused(8), UIcht[7]->get_point());
	 printf("                ■        %s[03] Threes             %3d 점  %s[19] Full House         %3d 점        ■\n", player->get_chartused(3), UIcht[2]->get_point(), player->get_chartused(9), UIcht[8]->get_point());
	 printf("                ■        %s[04] Fours              %3d 점  %s[10] Small Straight     %3d 점        ■\n", player->get_chartused(4), UIcht[3]->get_point(), player->get_chartused(10), UIcht[9]->get_point());
	 printf("                ■        %s[05] Fives              %3d 점  %s[11] Large Straight     %3d 점        ■\n", player->get_chartused(5), UIcht[4]->get_point(), player->get_chartused(11), UIcht[10]->get_point());
	 printf("                ■        %s[06] Sixes              %3d 점  %s[12] Yacht              %3d 점        ■\n", player->get_chartused(6), UIcht[5]->get_point(), player->get_chartused(12), UIcht[11]->get_point());
	cout << "                ■                                                                                  ■\n";
	 printf("                ■          보너스 점수 :           %3d 점  총 점수 :               %3d 점          ■\n", player->get_bonus(), player->get_result());
	cout << "                ■                                                                                  ■\n";
	cout << "                ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n";
}

int GameUI::gameSet_UI(Player* player, int high_score) {
	int select_command = 0;
	system("cls");
	cout << "\n\n\n";
	cout << "                ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■      □□      □□    □□□□  □□□□        □□□□  □□□□  □□□□    ■\n";
	cout << "                ■    □        □    □  □ □ □  □              □        □           □       ■\n";
	cout << "                ■    □        □    □  □ □ □  □              □        □           □       ■\n";
	cout << "                ■    □  □□  □□□□  □ □ □  □□□          □□□□  □□□       □       ■\n";
	cout << "                ■    □    □  □    □  □ □ □  □                    □  □           □       ■\n";
	cout << "                ■    □    □  □    □  □ □ □  □                    □  □           □       ■\n";
	cout << "                ■      □□    □    □  □ □ □  □□□□        □□□□  □□□□     □       ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                              게임이 종료되었습니다.                              ■\n";
	cout << "                ■                                                                                  ■\n";
	 printf("                ■                      %3s  WIN!                       %3d 점                      ■\n", player->get_name(), high_score);
	cout << "                ■                      SMU  WIN!                                                   ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                      202010969                     진 예 준                      ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                      202111063                     구 현 진                      ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
	while (1) {
		select_command = _getch();
		if (select_command == 49) //1번 커맨드 (게임 다시하기)
		{
			return 1;
		}
		else  //2번 커맨드 (게임 종료)
		{
			return 0;
		}
	}
}

int YatchGame::select_command() {
	int select_command = 0;
	cout << "                                    다시 주사위 굴리기 : 1번 / 족보 선택하기 : 2번\n";
	cout << "                                    명령어를 입력해 주세요   (키보드를 눌러주세요)";
	while (1) {
		select_command = _getch();
		if (select_command == 49) //1번 커맨드 (키보드 1)
		{
			return 1;
		}
		else if (select_command == 50) //2번 커맨드 (키보드 2)
		{
			return 2;
		}
	}
}

int YatchGame::select_command_rollDice(bool* select_rerollDice[]) {
	int select_command = 49;
	cout << "                                    키보드를 눌러 다시 굴릴 주사위를 선택해 주세요\n";
	cout << "                                 1부터 5까지의 숫자가 아닌 키보드를 입력 시 종료됩니다";
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
	cout << "                                      사용하지 않은 족보는 ○ / 사용한 족보는 ● \n";
	cout << "                               사용하지 않은 족보 중 사용할 족보의 번호를 적어주세요 >> ";
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

			for (int i = 0; i < 12; i++) {
				preview_point(dc, i);
			}

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

	while (player[player_number].get_leftturn() > 0) { // 마지막 플레이어의 남은 턴이 1이 될 때까지
		for (int i = 0; i < player_number; i++) { // 플레이어 인원 수만큼 돌기
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