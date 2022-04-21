#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"
#include "Input.h"

#include <iostream>

void Test();

int main()
{
    std::cout << "Blackjack" << std::endl;

    Test();

    return 0;
}

void Test()
{
    Deck deck;
    Input input;
    Player player;
    input.ReadInput();
    deck.ShuffleDeck();
    deck.PrintDeck();
    player.InsertCard(deck.GrabCardFromDeck());
    deck.PrintDeck();
    player.PrintHand();
}
