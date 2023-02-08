#include "Player.hpp"

void Player::player(int player)
{
	cout << endl;
	if (vec.size() % 2 == 1) // igrac1 uvijek igra prvi stoga ce biti vektor neparan  i obojat cemo igraca pripadnom bojom
	{
		cout << red << "Igrac" << player << color_reset << endl << "Unesite slobodnu poziciju: ";
		cin >> position;
	}
	else
	{
		cout << blue << "Igrac" << player << color_reset << endl << "Unesite slobodnu poziciju: ";
		cin >> position;
	}
	while (cin.fail() || position > 8 || position < 0 || counter != 0) // provjere da vidimo je li igrac1 unio trazeni podatak
	{

		if (cin.fail() || position > 8 || position < 0)
		{
			check_if_string(); // provjera je li korisnik slucajno upisao char/string
		}

		while (!is_in_vector(position)) //gledamo ima li position u vectoru koji cemo unijeti par linija nize 							
		{									// kada zadovoljimo sve potrebne uvjete, da ne punimo vektor nepotrebnim brojevima
			cout << "Pozicija je vec unesena\n";
			cout << "Unesite valjanu poziciju: ";
			cin >> position;

			if (cin.fail() || position > 8 || position < 0) // moram staviti uvjet jos vamo u slucaju da korisnik stavi poziciju koja ne postoji
			{											   // i onda nakon upise ili veci/manji broj ili upise neki char/string
				check_if_string();
			}
		}
		counter = 0; // vracam brojac na nula da zavrsimo sa petljom ako su ostali uvjeti zadovoljeni;
	}
	counter += 1; // dizem brojac na jedan da opet sa sigurnoscu mogu uci u petlju pri pozivu funkcije
	vec.push_back(position); // nakon sta je igrac zadovoljio uvjete unosi se broj, koji se sad vise nece moci koristiti
}


bool Player::player_call(int Tplayer)
{
	player(Tplayer);// poziv igraca
	choice(Tplayer, position); // nakon sto smo zadovoljili uvjete, unosimo u plocu X na odgovarajucu poziciju 

	display_board(); // prikaz trenutne situacije
	check = check_situation(); // gledamo ima li pobjednika
	if (display_result(check)) // da smanjim broj cout-a 
	{
		return true;
	}
	return false;
}

void Player::two_player_game()
{
	while (1)
	{
		if(player_call(player1)) // ako je istina zavrsi s petljom
		{
			break;
		}
		if (player_call(player2))
		{
			break;
		}
	}
}
