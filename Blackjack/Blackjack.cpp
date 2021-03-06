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
    Player player;
    Dealer dealer;

    while (true)
    {
        dealer.StartHand(deck);
        player.StartHand(deck);
        player.PlayerTurn(dealer, deck);
        dealer.DealerTurn(deck);
        deck.ResetDeck();
        break;
    }
}
