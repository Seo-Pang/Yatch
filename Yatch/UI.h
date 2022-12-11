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
		if (key == 49) //���� ������ ���� �ݺ��� Ż��
		{
			break;
		}
		else if (key == 50) //���� ����ȭ������ �̵�
		{
			Help_menu();
		}
		else if (key == 27) //ESC(���� ����)
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