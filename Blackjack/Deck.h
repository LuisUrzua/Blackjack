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
	void PrintDeck() const;
	CardPtr GrabCardFromDeck();
	void ResetDeck();

private:
	void ShuffleDeck();

private:
	VectorOfCards cards_in_deck;
};

