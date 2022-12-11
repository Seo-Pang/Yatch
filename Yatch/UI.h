#pragma once

#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

class UI {
	static void Main_menu();
	static void Help_menu();
	static int Ingame_menu();
	static void Endgame_menu();
};

void UI::Main_menu() {
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