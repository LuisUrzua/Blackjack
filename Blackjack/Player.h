#pragma once

#include <memory>
#include <vector>

class Card;

typedef std::unique_ptr<Card> CardPtr;
typedef std::vector<CardPtr> VectorOfCards;

class Player
{
public:
    void InsertCard(CardPtr);
    void PrintHand() const;

private:
    VectorOfCards player_hand;
};

