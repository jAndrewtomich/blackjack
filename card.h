#pragma once
#include <vector>
#include <string>

using namespace std;

class Card {

private:

	int suit, name, value;

public:

	Card() :suit{ 0 }, name{ 0 }, value{ 0 } {}

	void set_card_values(int suit, int name, int value) {
		this->suit = suit;
		this->name = name;
		this->value = value;
	}

	vector<int> get_card_values() {
		vector<int> vals;

		vals.push_back(this->suit);
		vals.push_back(this->name);
		vals.push_back(this->value);

		return vals;
	}

	string get_card_name() {
		if (this->name == 0)
			return "2";
		if (this->name == 1)
			return "3";
		if (this->name == 2)
			return "4";
		if (this->name == 3)
			return "5";
		if (this->name == 4)
			return "6";
		if (this->name == 5)
			return "7";
		if (this->name == 6)
			return "8";
		if (this->name == 7)
			return "9";
		if (this->name == 8)
			return "10";
		if (this->name == 9)
			return "J";
		if (this->name == 10)
			return "Q";
		if (this->name == 11)
			return "K";
		if (this->name == 12)
			return "A";
	}

	void show_card() {
		string suit_string;
		string name_string;

		if (this->suit == 0)
			suit_string = "Clubs";
		if (this->suit == 1)
			suit_string = "Diamonds";
		if (this->suit == 2)
			suit_string = "Hearts";
		if (this->suit == 3)
			suit_string = "Spades";

		if (this->name < 9)
			name_string = to_string(this->name + 2);
		if (this->name == 9)
			name_string = "J";
		if (this->name == 10)
			name_string = "Q";
		if (this->name == 11)
			name_string = "K";
		if (this->name == 12)
			name_string = "Ace";

		cout << "======" << endl << "Card: " << name_string << "\nSuit: " << suit_string << endl << "======" << endl;
	}



	~Card(){}
};







