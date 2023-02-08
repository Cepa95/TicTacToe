#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <vector>
#include <ctype.h>
#include <ios>
#include <limits>
#include <string>
#include <random>
#include <stdio.h>
#define red "\u001b[31m" // ansci boje za terminal
#define blue "\u001b[34m"
#define yellow "\u001b[33m"
#define cyan "\u001b[36m"
#define green "\u001b[32m."
#define color_reset "\x1b[0m"

using namespace std;

class TicTacToe
{
protected:
	char board[10] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0' };
	int player1, player2, check, position, counter, score1, score2, score3;
	vector <int> vec;

public:
	TicTacToe();
	void intro_display();
	void mode_display();
	void display_board();
	void choice(int player, int position);
	bool is_in_vector(int position);
	int check_situation();
	void check_if_string();
	void display_situation();
	int display_result(int result);
};

#endif