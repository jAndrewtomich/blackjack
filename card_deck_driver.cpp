#include <iostream>
#include "player.h"

int main() {

	srand(time(NULL));

	bool game_over = false;

	while (!game_over) {

		Deck game_deck;

		bool win = false, lose = false, tie = false, blackjack = false;

		Player player1, dealer;

		game_deck.shuffle_deck();



		for (int i = 0; i < 2; ++i) {
			player1.add_to_player_hand(game_deck.draw_card(game_deck.get_counter_value()));
			player1.increment_player_score(player1.get_player_card(player1.get_hand_size() - 1));
		}

		for (int i = 0; i < 2; ++i) {
			dealer.add_to_player_hand(game_deck.draw_card(game_deck.get_counter_value()));
			dealer.increment_player_score(dealer.get_player_card(dealer.get_hand_size() - 1));
		}



		player1.player_turn(game_deck, dealer, win, lose, blackjack);



		if (!win && !lose && !blackjack)
			dealer.dealer_turn(game_deck, player1, win, lose, tie);



		if (blackjack) {

			if (dealer.get_player_score() != 21) {

				for (int i = 0; i < 2; ++i) {
					Card card = player1.get_player_card(i);
					card.show_card();
				}
				cout << "BlackJack!! You Win, you Lucky Dog!!" << endl;
			}
			else
				cout << "Awww, Bummer... You and the House BOTH have BlackJack...";
		}



		if (win) {
			if (dealer.get_player_score() > 21) {
				cout << "The House went Bust with a " << dealer.get_player_score() << "!! You Win!!" << endl;
			}
			else {
				cout << "You beat the House!! You Win!!" << endl;
			}
		}



		if (lose) {

			if (player1.get_player_score() > 21) {
				cout << "You went Bust with a " << player1.get_player_score() << "!! You Lose!!" << endl;
			}
			else {
				cout << "The House beat you with a score of " << dealer.get_player_score() << "!! You Lose!!" << endl;
			}
		}



		if (tie) {
			cout << "You have tied with the House!!  No Winner or Loser!!" << endl;
		}



		cout << endl << endl;



		cout << "The dealer's cards were:\n"; //Reveal Dealer's cards to player both for persistence check and authenticity.  Second card should match the card 
											  //that the dealer was initially showing and the first card will be dealer's initial hidden card.
		for (int i = 0; i < dealer.get_hand_size(); ++i) {
			Card card = dealer.get_player_card(i);
			card.show_card();
		}



		cout << "Would you like to play again? ('y' or 'n')\n";
		
		cin >> ws;  //Consume '\n' in iostream

		char play = tolower(cin.get());

		if (play != 'y' && play != 'n') {

			while (play != 'y' && play != 'n') {

				cout << "Invalid Entry.  Choose 'y' or 'n'.\n>> ";

				cin >> ws;

				play = tolower(cin.get());

			}

			if (play == 'n')
				game_over = true;
		}
		else if (play == 'n')
			game_over = true;


		system("CLS");
	}

	cout << "***************\nTHANK YOU FOR PLAYING!!\n***************\n\n";

	system("pause");

	return 0;
}