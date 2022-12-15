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
	int keys;
	while(true)
	{
		system("cls");
		cout << "\n\n\n";
		cout << "                ��������������������������������������������\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��     Yatch ������ �ֻ����� �̿��Ͽ� �÷��̾���� ������ �ϼ��ϴ� �����Դϴ�.      ��\n";
		cout << "                ��     �ֻ��� 5���� ���� �� �ֻ����� ���� ������ ���ǿ� �´� ������ ä��ϴ�.       ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��     NumberChart�� 1���� 6���� �ش�Ǵ� ���� �ֻ����� ���� ��ȯ�մϴ�.            ��\n";
		cout << "                ��     ChanceChart�� 5�� �ֻ����� ���� ��ȯ�մϴ�                                   ��\n";
		cout << "                ��     Four of a Kind Chart�� 4���� �ֻ����� ���� ��� ������ ��ȯ�մϴ�.           ��\n";
		cout << "                ��     Fullhouse Chart�� 3���� �ֻ����� ����, ������ 2���� �ֻ����� ���� ���       ��\n";
		cout << "                ��     ������ ��ȯ�մϴ�.                                                           ��\n";
		cout << "                ��     Small Straight Chart�� ���ӵ� 4���� �ֻ����� ���� ��� ������ ��ȯ�մϴ�.    ��\n";
		cout << "                ��     Large Straight Chart�� ���ӵ� 5���� �ֻ����� ���� ��� ������ ��ȯ�մϴ�.    ��\n";
		cout << "                ��     Yatch Chart�� ���ӵ� 5���� �ֻ����� ���� ��� ������ ��ȯ�մϴ�.             ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                      [ESC]                    ���θ޴� ���ư���                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��                                                                                  ��\n";
		cout << "                ��������������������������������������������\n";
		keys = _getch();
		if (keys ==27) //���� ������ ���� �ݺ��� Ż��
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