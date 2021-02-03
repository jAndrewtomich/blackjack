#pragma once
#include "deck.h"

class Player {

private:

	int score;

	vector<Card> player_hand;

public:

	Player() : score{0} {}

	void add_to_player_hand(Card card) {
		this->player_hand.push_back(card);
	}

	int get_hand_size() {
		return this->player_hand.size();
	}

	Card get_player_card(int i) {
		return this->player_hand[i];
	}

	void increment_player_score(Card card) {
		this->score += card.get_card_values()[2];
	}

	int get_player_score() {
		return this->score;
	}

	void adjust_player_score(int i) {
		this->score -= i;
	}

	void player_turn(Deck game_deck, Player dealer, bool &win, bool &lose, bool &blackjack) {

		if (this->get_player_score() == 21) {
			blackjack = true;
			return;
		}

		int ace_counter = 0;

		cout << "_____PLAYER'S TURN_____\n\nYour cards are:\n";

		for (int i = 0; i < this->get_hand_size(); ++i) {
			Card card = this->get_player_card(i);
			if (card.get_card_name() == "A")
				ace_counter++;
			card.show_card();
		}

		cout << "Your score is " << this->get_player_score() << endl << "The dealer is showing " << dealer.get_player_card(1).get_card_name() << endl;

		while (!(this->get_player_score() > 21)) {

			cout << "Would you like to hit? ('y' or 'n')\n";

			cin >> ws;

			char hit = cin.get();

			if (hit == 'y') {
				Card new_card = game_deck.draw_card(game_deck.get_counter_value());
				this->add_to_player_hand(new_card);
				this->increment_player_score(new_card);

				if (new_card.get_card_name() == "A")
					ace_counter++;

				cout << "Your new card is:\n";

				new_card.show_card();

				if (this->get_player_score() > 21) {
					while ( this->get_player_score() > 21 && ace_counter > 0) {
						this->adjust_player_score(10);
						ace_counter--;
					}
				}

				cout << endl << "Your score is now: " << this->get_player_score() << endl;
			}

			else if (hit == 'n') {
				break;
			}
			else {
				cout << "Invalid option." << endl;
			}

		}

		if (this->get_player_score() > 21) {
			lose = true;

		}


	}

	void dealer_turn(Deck game_deck, Player player, bool &win, bool &lose, bool &tie) {

		cout << "_____DEALER'S TURN_____\n\nDEALER'S FACE-UP CARD: \n";
		this->get_player_card(this->get_hand_size() - 1).show_card();
		cout << endl;

		while (!(this->get_player_score() > 16)) {

			Card new_card = game_deck.draw_card(game_deck.get_counter_value());
			this->add_to_player_hand(new_card);
			this->increment_player_score(new_card);

			cout << "DEALER HAS DRAWN: \n";
			new_card.show_card();

			if (this->get_player_score() > 21)
				break;

		}

		if (this->get_player_score() > 21 || this->get_player_score() < player.get_player_score())
			win = true;

		else if (this->get_player_score() > player.get_player_score())
			lose = true;

		if (this->get_player_score() == player.get_player_score())
			tie = true;

	}

};