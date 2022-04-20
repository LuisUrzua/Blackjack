#pragma once

#include <vector>

class Card;

typedef std::vector<Card*> VectorOfCards;

class Deck
{
public:
	Deck();

private:
	VectorOfCards cards_in_deck;
};

