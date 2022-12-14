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
		system("cls"); // ����ȭ��
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
		cout << "                ��                      [ 1 ]                    ���� �����ϱ�                      ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                      [ 2 ]                    ���� ������                      ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                      [ESC]                    ���� �����ϱ�                      ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                �� �� made by Mandarin_Farm                                                         ��\n";
		cout << "                ��������������������������������������������\n";
		key = _getch();
		if (key == 49) //�÷��̾� �ο��� Ȯ��
		{
			int playerNum = check_playerNumber();
			if (playerNum >= 1) {
				return playerNum;
			}
			else {
				continue;
			}
		}
		else if (key == 50) //���� ����ȭ������ �̵�
		{
			Help_menu(1);
		}
		else if (key == 27) //ESC(���� ����)
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
		cout << "                ��                         �÷����ϴ� �ο� ���� �����ּ���.                         ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                      �÷��� ���� �ο� :         [1] ~ [4]��                      ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                      [ESC]                �������� ���ư���                      ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                �� �� made by Mandarin_Farm                                                         ��\n";
		cout << "                ��������������������������������������������\n";
		key = _getch();
		if (key == 49) //�÷��̾� �ο��� Ȯ��
		{
			return 1;
		}
		else if (key == 50) //���� ����ȭ������ �̵�
		{
			return 2;
		}
		else if (key == 50) //���� ����ȭ������ �̵�
		{
			return 3;
		}
		else if (key == 50) //���� ����ȭ������ �̵�
		{
			return 4;
		}
		else if (key == 27) //ESC(���� ����)
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
		cout << "                ��������������������������������������������\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                  | ESC ������ | ���� �������� >>                 ��\n";
		cout << "                ��������������������������������������������\n";
		break;
	case 2:
		system("cls");
		cout << "\n\n\n";
		cout << "                ��������������������������������������������\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                 << ���� �������� | ESC ������ | ���� �������� >>                 ��\n";
		cout << "                ��������������������������������������������\n";
		break;
	case 3:
		system("cls");
		cout << "\n\n\n";
		cout << "                ��������������������������������������������\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                 << ���� �������� | ESC ������ |                                  ��\n";
		cout << "                ��������������������������������������������\n";
		break;
	}

	while (1) {
		key = _getch();
		if (key == 75) //���� �������� �̵�
		{
			if (a - 1 <= 0) {
				return;
			}
			return Help_menu(a-1);
		}
		else if (key == 77) //���� �������� �̵�
		{
			if (a + 1 >= 4) {
				return;
			}
			return Help_menu(a + 1);
		}
		else if (key == 27) //���� ����
		{
			return;
		}
	}
}

void UI::Endgame_menu() {
	system("cls");
	cout << "\n\n\n";
	cout << "                ��������������������������������������������\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��      ���      ���      ���    ����          ����    ��    ��  �����    ��\n";
	cout << "                ��    ��        ��    ��  ��    ��  ��    ��        ��    ��  ��    ��  ��          ��\n";
	cout << "                ��    ��        ��    ��  ��    ��  ��    ��        ��    ��  ��    ��  ��          ��\n";
	cout << "                ��    ��  ���  ��    ��  ��    ��  ��    ��        ����    �����  ����      ��\n";
	cout << "                ��    ��    ��  ��    ��  ��    ��  ��    ��        ��    ��      ��    ��          ��\n";
	cout << "                ��    ��    ��  ��    ��  ��    ��  ��    ��        ��    ��      ��    ��          ��\n";
	cout << "                ��      ���      ���      ���    ����          ����        ��    �����    ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                            made by. Team MandarinFarm                            ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                      202010950                     �� �� ��                      ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                      202010969                     �� �� ��                      ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                      202111063                     �� �� ��                      ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��                                                                                  ��\n";
	cout << "                ��������������������������������������������\n";
	Sleep(3000);
	exit(0);
}