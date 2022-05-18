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
    Dealer();
    void StartHand(Deck&);
    void DealerTurn(Deck&);
    int HandValue() const;

private:
    void InsertCard(CardPtr);
    void PrintHand() const;

private:
    VectorOfCards dealer_hand;
    int chips;
};

