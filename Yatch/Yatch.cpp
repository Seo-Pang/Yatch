// Yatch.cpp : 애플리케이션에 대한 진입점을 정의합니다.

#include <iostream>
#include "Yatch.h"

using namespace std;

int main()
{
	srand(time(NULL));
	NumberChart nuc(6);
	Dice dc[5];


	for (int i = 0; i < 5; i++)
	{
		dc[i].roll();
		cout << dc[i].get_eyes() << endl;
	}

	nuc.charting(dc);
	cout << nuc.get_info()  << " Chart Point : " << nuc.get_point();

}