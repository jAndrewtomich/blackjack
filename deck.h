#pragma once
#include "card.h"


class Deck {

private:

	const int DECK_SIZE = 52;

	const int SUIT_SIZE = 13;

	int deck_counter = 0;

	vector<Card> cards;

public:

	Deck() {

		int val;

		for (int i = 0; i < DECK_SIZE; ++i) {

			if (i % SUIT_SIZE < 8)
				val = (i % SUIT_SIZE) + 2;
			if (i % SUIT_SIZE > 7 && i % SUIT_SIZE < 12)
				val = 10;
			if (i % SUIT_SIZE == 12)
				val = 11;

			Card new_card;

			new_card.set_card_values(i / SUIT_SIZE, i % SUIT_SIZE, val);

			this->cards.push_back(new_card);

		}


	}

	void shuffle_deck() {

		int shuffs = DECK_SIZE - 1;

		for (int i = 0; i < DECK_SIZE; ++i) {

			int swapee = rand() % shuffs;

			while (swapee == i) {

				swapee = rand() % --shuffs;
			}

			Card temp_card;

			vector<int> vals_i = this->cards[i].get_card_values();

			vector<int> vals_s = this->cards[swapee].get_card_values();

			temp_card.set_card_values(vals_i[0], vals_i[1], vals_i[2]);

			vector<int> vals_t = temp_card.get_card_values();

			this->cards[i].set_card_values(vals_s[0], vals_s[1], vals_s[2]);

			this->cards[swapee].set_card_values(vals_t[0], vals_t[1], vals_t[2]);
		}

		this->set_counter_value(0);

	}

	Card draw_card(int n) {

		if (this->deck_counter > 51) {
			this->shuffle_deck();
			this->deck_counter = 0;
			n = this->deck_counter;
		}
		
		Card new_card;

		vector<int> vals_c = this->cards[n].get_card_values();

		new_card.set_card_values(vals_c[0], vals_c[1], vals_c[2]);

		this->deck_counter++;

		return new_card;

	}

	void set_counter_value(int c) {

		this->deck_counter = c;

	}

	int get_counter_value() {

		return this->deck_counter;

	}



	~Deck() {}

};





































/*private:

	vector<Card> cards;

	vector<vector<int>> discards;

	const int NUM_CARDS = 52;

	const int CARDS_PER_SUIT = 13;

public:

	Deck() {}

	Deck(bool build = false) {
		
		if (build) {

			for (int i = 0; i < NUM_CARDS; ++i) {
				
				int suit = i / CARDS_PER_SUIT;

				int name = i % CARDS_PER_SUIT;

				int val;

				if (name < 9)
					val = name;

				else if (name > 8 && name < 12)
					val = 10;

				else
					val = 11;

				Card new_card;

				new_card.set_card_values(suit, name, val);

				this->cards.push_back(new_card);

			}

		}

	}

	void shuffle_deck() {

		int swaps = rand() % 26;

		for (int i = 0; i < swaps; ++i) {

			int swapee = rand() % 51;

			while (swapee == i)
				swapee = rand() % 51;

			Card temp_card;

			temp_card.set_card_values(this->cards[i].get_card_values(0), this->cards[i].get_card_values(1), this->cards[i].get_card_values(2));

			this->cards[i].set_card_values(this->cards[swapee].get_card_values(0), this->cards[swapee].get_card_values(1), this->cards[swapee].get_card_values(2));

			this->cards[swapee].set_card_values(temp_card.get_card_values(0), temp_card.get_card_values(1), temp_card.get_card_values(2));
			
		}

	}

	Card draw_card() {
		Card drawn_card;
		bool legit = false;
		while (!legit) {
			srand(time(NULL));
			int card = rand() % 51;
			drawn_card.set_card_values(this->cards[card].get_card_values(0), this->cards[card].get_card_values(1), this->cards[card].get_card_values(2));
			for (int i = 0; i < this->discards.size(); ++i) {
				for (int j = 0; j < this->discards[i].size(); ++j) {
					if (this->discards[i][j] == drawn_card.get_card_values(0)) {
						if (this->discards[i + 1][j] == drawn_card.get_card_values(1)) {
							legit = false;
						}
					}					
				}
				legit = true;
				break;
			}
		}

		for (int i = 0; i < 2; ++i)
			this->discards[i].push_back(drawn_card.get_card_values(i));
		
		return drawn_card;
	}*/


