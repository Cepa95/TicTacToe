#include <iostream>
#include "TicTacToe.hpp"
#include "Player.hpp"
#include "AIPlayer.hpp"
#include "Game.hpp"

using namespace std;

int main()
{
	try
	{
		Game start;
		start.choose_player_mode();
	}
	catch (const char* message)
	{
		cout << message;
		return -1;
	}
}