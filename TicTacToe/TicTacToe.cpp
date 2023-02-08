#include "TicTacToe.hpp"
#include "Player.hpp"

TicTacToe::TicTacToe()
{
	player1 = 1;
	player2 = 2;
	check = 0; // provjera ima li pobjednika ili ne
	position = 0;
	score1 = 0; // pobjede prvog igraca
	score2 = 0; // pobjede drugog igraca
	score3 = 0; // koliko je bilo nerijesenih partija
	counter = 1; // brojac mi je jedan da mi u display_game prvi samo udje jednom u petlju, smanjim potrebu za jednim whilom
}

void TicTacToe::intro_display()
{
	cout << cyan;
	cout << "-----------TicTacToe-----------\n" << color_reset << yellow << endl;
	cout << "           0 | 1 | 2         " << endl;
	cout << "          -----------        " << endl;
	cout << "           3 | 4 | 5         " << endl;
	cout << "          -----------         " << endl;
	cout << "           6 | 7 | 8         " << color_reset << endl;
}

void TicTacToe::mode_display()
{
	cout << cyan;
	cout << endl;
	cout << "     Odaberite nacin igre:\n" << endl;
	cout << "     Player vs Player[1]" << endl;
	cout << "     Player vs Computer[2]" << endl;
	cout << "     Computer vs Computer[3]" << endl;
	cout << "     Exit[4]" << color_reset << endl;
}

void TicTacToe::display_board()
{
	for (int i = 0; i < 9; i += 1)
	{
		if (board[i] == 'X')
		{
			cout << "  " << blue << board[i] << color_reset;
		}
		else if (board[i] == 'O')
		{
			cout << "  " << red << board[i] << color_reset;
		}
		else
		{
			cout << "  " << board[i];
		}
		if (i == 0 || i == 1 || i == 3 || i == 4 || i == 6 || i == 7) // radi tablicu
		{
			cout << yellow << "  |"; // bojanje tablice zutom bojom
		}
		if (i == 2 || i == 5 || i == 9)
		{
			cout << endl;
		}
		if (i == 2 || i == 5)
		{
			cout << yellow << "------------------\n";
		}
		cout << color_reset;
	}
	cout << endl;
}

void TicTacToe::choice(int player, int position)
{
	cout << endl;
	if (player == 1)
	{
		board[position] = 'X';
	}
	else
	{
		board[position] = 'O';
	}
}

bool TicTacToe::is_in_vector(int position)
{
	for (int x : vec) // stavljamo u vektor sve brojeve koji su unijeti, tako da ih vise ne smijemo koristiti, unosimo ih par linija nize
	{
		if (x == position)
		{
			return 0;
		}
	}
	return 1;
}

int TicTacToe::check_situation()
{
	if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ') // provjera prvog reda
	{
		if (board[0] == 'X')
		{
			score1 += 1;
			return 1;
		}
		else
		{
			score2 += 1;
			return 2;
		}
	}
	else if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ') // provjera drugog reda
	{
		if (board[3] == 'X')
		{
			score1 += 1;
			return 1;
		}
		else
		{
			score2 += 1;
			return 2;
		}
	}

	else if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ') // provjera treceg reda
	{
		if (board[6] == 'X')
		{
			score1 += 1;
			return 1;
		}
		else
		{
			score2 += 1;
			return 2;
		}
	}

	else if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ') // provjera prvog stupca
	{
		if (board[0] == 'X')
		{
			score1 += 1;
			return 1;
		}
		else
		{
			score2 += 1;
			return 2;
		}
	}

	else if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')  // provjera drugog stupca
	{
		if (board[1] == 'X')
		{
			score1 += 1;
			return 1;
		}
		else
		{
			score2 += 1;
			return 2;
		}
	}

	else if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ') // provjera treceg stupca
	{
		if (board[2] == 'X')
		{
			score1 += 1;
			return 1;
		}
		else
		{
			score2 += 1;
			return 2;
		}
	}

	else if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')   //provjera vertikale
	{
		if (board[0] == 'X')
		{
			score1 += 1;
			return 1;
		}
		else
		{
			score2 += 1;
			return 2;
		}
	}

	else if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')  // provjera vertikale
	{
		if (board[2] == 'X')
		{
			score1 += 1;
			return 1;
		}
		else
		{
			score2 += 1;
			return 2;
		}
	}

	for (int i = 0; board[i] != '\0'; i += 1) // u slucaju da nema pobjednika, provjerim je li igra zavrsila
	{
		if (board[i] == ' ')
		{
			return -1; // igra jos traje
		}
	}
	score3 += 1;
	return 0; // zavrsila je
}

void TicTacToe::check_if_string() //  funkcija gdje cistimo string, ako je string/char
{
	cin.clear(); 
	cin.ignore(numeric_limits<streamsize> ::max(), '\n');
	cout << "Unesite broj, ali broj slobodne pozicije: ";
	cin >> position;
}

void TicTacToe::display_situation()
{
	cout << endl;
	cout << "Trenutno stanje:\n";
	cout << blue << "Igrac1: " << score1 << " pobjeda/pobjede" << color_reset << endl;
	cout << red << "Igrac2: " << score2 << " pobjeda/pobjede" << color_reset << endl;
	cout << yellow << "Nerijeseno: " << score3 << color_reset << endl;
}

int TicTacToe::display_result(int result)
{
	if (check == 1)
	{
		cout << blue << "\nIgrac" << player1 << " je pobijedio" << color_reset << endl;
		display_situation();
		return 1;
	}
	else if (check == 2)
	{
		cout << red << "\nIgrac" << player2 << " je pobijedio" << color_reset << endl;
		display_situation();
		return 1;
	}

	else if (check == 0)
	{
		cout << yellow << "\nNerijeseno" << color_reset << endl;
		display_situation();
		return 1;
	}
	return 0;
}

