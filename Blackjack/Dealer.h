#pragma once

#include <memory>
#include <vector>

class Card;
class Deck;

typedef std::unique_ptr<Card> CardPtr;
typedef std::vector<CardPtr> VectorOfCards;

class Dealer
{
public:
    void StartHand(Deck&);
    void DealerTurn(Deck&);

private:
    void InsertCard(CardPtr);
    void PrintHand() const;
    int HandValue() const;

private:
    VectorOfCards dealer_hand;
};

