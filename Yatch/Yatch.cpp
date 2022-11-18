// Yatch.cpp : 애플리케이션에 대한 진입점을 정의합니다.

#include <iostream>
#include "Yatch.h"

using namespace std;

int main()
{
	srand(time(NULL));
	NumberChart nuc(6);
	ChanceChart chc;
	Dice dc[5];

	cout << "DICE: ";
	for (int i = 0; i < 5; i++)
	{
		dc[i].roll();
		cout << dc[i].get_eyes() << " ";
	}
	cout << endl;

	nuc.charting(dc);
	chc.charting(dc);
	cout << nuc.get_info()  << " Chart Point : " << nuc.get_point() << endl;
	cout << chc.get_info() << " Chart Point : " << chc.get_point() << endl;

}