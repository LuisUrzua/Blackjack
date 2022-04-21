#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"
#include "Input.h"

#include <iostream>

void StartGame();

int main()
{
    std::cout << "Blackjack" << std::endl;

    StartGame();

    return 0;
}

void StartGame()
{
    Deck deck;
    Input input;
    Player player;
    Dealer dealer;

    deck.ShuffleDeck();
    dealer.StartHand(deck);
    player.StartHand(deck);
    player.PlayerTurn(input, deck);
    dealer.DealerTurn(deck);
}
