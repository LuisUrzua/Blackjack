#pragma once

#include <memory>
#include <vector>

class Card;
class Deck;
class Input;
class Strategy;
class Dealer;

typedef std::unique_ptr<Card> CardPtr;
typedef std::vector<CardPtr> VectorOfCards;
typedef std::unique_ptr<Strategy> StrategyPtr;

class Player
{
public:
    Player();
    void StartHand(Deck&);
    void PlayerTurn(const Dealer&, Deck&);
    int HandValue() const;
    bool HandContainsAce() const;
    bool PairedHand() const;
    void CalculateBets(Dealer&);

private:
    void InsertCard(CardPtr);
    void PrintHand() const;

private:
    VectorOfCards player_hand;
    int chips;
};

