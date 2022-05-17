#pragma once

enum class Rank
{
	Ace,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eighth,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
};

enum class Suit
{
	Clubs,
	Diamonds,
	Hearts,
	Spades,
};

class Card
{
public:
	Card(Rank, Suit);
	void PrintCard() const;
	int CardValue() const;
	Rank GetRank() const;

private:
	Rank rank;
	Suit suit;
};

