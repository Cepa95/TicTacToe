#ifndef PLAYER_H
#define PLAYER_H
#include "TicTacToe.hpp"

class Player : public TicTacToe
{
public:
	void player(int player);
	bool player_call(int player);
	void two_player_game();
};

#endif