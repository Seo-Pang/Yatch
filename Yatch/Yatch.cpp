// Yatch.cpp : 애플리케이션에 대한 진입점을 정의합니다.

#include "Yatch.h"

using namespace std;

int main()
{
	UI UI;
	YatchGame game;
	int player_count = 0;
	int game_continue = 1;
	while (game_continue == 1) {
		player_count = UI.Main_menu();

		game_continue = game.play_game(player_count);
	}
	return 0;
}