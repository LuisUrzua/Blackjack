#include "Card.h"
#include "Deck.h"
#include "Player.h"

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
    Player player;
    player.ReadInput();
    deck.ShuffleDeck();
    deck.PrintDeck();
}
