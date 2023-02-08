#ifndef GAME_H
#define GAME_H
#include "TicTacToe.hpp"
#include "Player.hpp"
#include "AIPlayer.hpp"

class Game : public AIPlayer
{
public:
	char play_continuation();
	void continue_game_decision(int decision);
	void choose_player_mode();
};

#endif