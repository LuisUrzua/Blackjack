#include "Deck.h"
#include "Card.h"

#include <random>
#include <iostream>

#define NUMBER_OF_RANKS 13
#define NUMBER_OF_SUITS 4

const Rank all_ranks[] =
{
	Rank::Ace,
	Rank::Two,
	Rank::Three,
	Rank::Four,
	Rank::Five,
	Rank::Six,
	Rank::Seven,
	Rank::Eighth,
	Rank::Nine,
	Rank::Ten,
	Rank::Jack,
	Rank::Queen,
	Rank::King,
};

const Suit all_suits[] =
{
	Suit::Clubs,
	Suit::Diamonds,
	Suit::Hearts,
	Suit::Spades,
};

Deck::Deck()
{
	for (int rank = 0; rank < NUMBER_OF_RANKS; rank++)
	{
		for (int suit = 0; suit < NUMBER_OF_SUITS; suit++)
		{
			cards_in_deck.push_back(std::make_unique<Card> (Card(all_ranks[rank], all_suits[suit])));
		}
	}
}

void Deck::ShuffleDeck()
{
	std::shuffle(cards_in_deck.begin(), cards_in_deck.end(), std::random_device());
}

void Deck::PrintDeck() const
{
	std::cout << "Size of deck: " << cards_in_deck.size() << std::endl;

	for (const auto& card : cards_in_deck)
	{
		card->PrintCard();
	}

	std::cout << std::endl;
}

CardPtr Deck::GrabCardFromDeck()
{
	auto top_card = std::move(cards_in_deck.at(0));
	cards_in_deck.erase(cards_in_deck.begin());
	return std::move(top_card);
}
