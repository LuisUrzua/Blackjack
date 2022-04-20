#pragma once

#include <vector>
#include <memory>

class Card;

typedef std::unique_ptr<Card> CardPtr;
typedef std::vector<CardPtr> VectorOfCards;

class Deck
{
public:
	Deck();

private:
	VectorOfCards cards_in_deck;
};

