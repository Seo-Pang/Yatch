#pragma once

#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

class UI {
public:
	static void Main_menu();
	static void Help_menu();
	static int Ingame_menu();
	static void Endgame_menu();
};

void UI::Main_menu() {
	int key;
	while (true)
	{
		key = 0;
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
		if (key == 49) //게임 시작을 위해 반복문 탈출
		{
			break;
		}
		else if (key == 50) //게임 설명화면으로 이동
		{
			Help_menu();
		}
		else if (key == 27) //ESC(게임 종료)
		{
			Endgame_menu();
		}
	}
}

void UI::Help_menu() 
{
	int keys;
	while(true)
	{
		system("cls");
		cout << "\n\n\n";
		cout << "                ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■     Yatch 게임은 주사위를 이용하여 플레이어들의 족보를 완성하는 게임입니다.      ■\n";
		cout << "                ■     주사위 5개를 굴려 각 주사위의 눈을 값으로 조건에 맞는 족보를 채웁니다.       ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■     NumberChart는 1부터 6까지 해당되는 각각 주사위의 합을 반환합니다.            ■\n";
		cout << "                ■     ChanceChart는 5개 주사위의 합을 반환합니다                                   ■\n";
		cout << "                ■     Four of a Kind Chart는 4개의 주사위가 같을 경우 점수를 반환합니다.           ■\n";
		cout << "                ■     Fullhouse Chart는 3개의 주사위가 같고, 나머지 2개의 주사위가 같을 경우       ■\n";
		cout << "                ■     점수를 반환합니다.                                                           ■\n";
		cout << "                ■     Small Straight Chart는 연속된 4개의 주사위가 나올 경우 점수를 반환합니다.    ■\n";
		cout << "                ■     Large Straight Chart는 연속된 5개의 주사위가 나올 경우 점수를 반환합니다.    ■\n";
		cout << "                ■     Yatch Chart는 연속된 5개의 주사위가 나올 경우 점수를 반환합니다.             ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                      [ESC]                    메인메뉴 돌아가기                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■                                                                                  ■\n";
		cout << "                ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
		keys = _getch();
		if (keys ==27) //게임 시작을 위해 반복문 탈출
		{
			break;
		}
	}

}

int UI::Ingame_menu() 
{
	return 0;
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