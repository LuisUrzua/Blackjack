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
    input.ReadInput();
    deck.ShuffleDeck();
    deck.PrintDeck();
}
