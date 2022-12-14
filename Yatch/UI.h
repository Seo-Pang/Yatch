#pragma once

#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Chart.h"
#include "Dice.h"
#include "Player.h"
#include "Game.h"

using namespace std;

class UI {
public:
	static int Main_menu();
	static int check_playerNumber();
	static void Help_menu(int a);
	static void Endgame_menu();
};

int UI::Main_menu() {
	int key;
	while (true)
	{
		system("cls"); // 메인화면
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
		cout << "                ■                      [ 1 ]                    게임 시작하기                      ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                      [ 2 ]                    게임 설명보기                      ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                      [ESC]                    게임 종료하기                      ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■ ※ made by Mandarin_Farm                                                         ■\n";
		cout << "                ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
		key = _getch();
		if (key == 49) //플레이어 인원수 확인
		{
			int playerNum = check_playerNumber();
			if (playerNum >= 1) {
				return playerNum;
			}
			else {
				continue;
			}
		}
		else if (key == 50) //게임 설명화면으로 이동
		{
			Help_menu(1);
		}
		else if (key == 27) //ESC(게임 종료)
		{
			Endgame_menu();
		}
	}
}

int UI::check_playerNumber() {
	int key;
	while (true) {
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
		cout << "                ■                         플레이하는 인원 수를 적어주세요.                         ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                      플레이 가능 인원 :         [1] ~ [4]인                      ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                      [ESC]                이전으로 돌아가기                      ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■ ※ made by Mandarin_Farm                                                         ■\n";
		cout << "                ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
		key = _getch();
		if (key == 49) //플레이어 인원수 확인
		{
			return 1;
		}
		else if (key == 50) //게임 설명화면으로 이동
		{
			return 2;
		}
		else if (key == 50) //게임 설명화면으로 이동
		{
			return 3;
		}
		else if (key == 50) //게임 설명화면으로 이동
		{
			return 4;
		}
		else if (key == 27) //ESC(게임 종료)
		{
			return 0;
		}
	}
}

void UI::Help_menu(int a)
{
	int key;
	switch (a) {
	case 1:
		system("cls");
		cout << "\n\n\n";
		cout << "                ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                  | ESC 나가기 | 다음 페이지로 >>                 ■\n";
		cout << "                ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
		break;
	case 2:
		system("cls");
		cout << "\n\n\n";
		cout << "                ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                 << 이전 페이지로 | ESC 나가기 | 다음 페이지로 >>                 ■\n";
		cout << "                ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
		break;
	case 3:
		system("cls");
		cout << "\n\n\n";
		cout << "                ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                 << 이전 페이지로 | ESC 나가기 |                                  ■\n";
		cout << "                ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
		break;
	}

	while (1) {
		key = _getch();
		if (key == 75) //이전 페이지로 이동
		{
			if (a - 1 <= 0) {
				return;
			}
			return Help_menu(a-1);
		}
		else if (key == 77) //다음 페이지로 이동
		{
			if (a + 1 >= 4) {
				return;
			}
			return Help_menu(a + 1);
		}
		else if (key == 27) //도움말 종료
		{
			return;
		}
	}
}

void UI::Endgame_menu() {
	system("cls");
	cout << "\n\n\n";
	cout << "                ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■      □□      □□      □□    □□□          □□□    □    □  □□□□    ■\n";
	cout << "                ■    □        □    □  □    □  □    □        □    □  □    □  □          ■\n";
	cout << "                ■    □        □    □  □    □  □    □        □    □  □    □  □          ■\n";
	cout << "                ■    □  □□  □    □  □    □  □    □        □□□    □□□□  □□□      ■\n";
	cout << "                ■    □    □  □    □  □    □  □    □        □    □      □    □          ■\n";
	cout << "                ■    □    □  □    □  □    □  □    □        □    □      □    □          ■\n";
	cout << "                ■      □□      □□      □□    □□□          □□□        □    □□□□    ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                            made by. Team MandarinFarm                            ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                      202010950                     박 준 규                      ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                      202010969                     진 예 준                      ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                      202111063                     구 현 진                      ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■                                                                                  ■\n";
	cout << "                ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
	Sleep(3000);
	exit(0);
}