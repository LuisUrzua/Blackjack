#include "Dealer.h"
#include "Card.h"
#include "Deck.h"

#include <iostream>

#define BLACKJACK 21
#define DEALER_STANDS_ON_17 17

void Dealer::InsertCard(CardPtr new_card)
{
    dealer_hand.push_back(std::move(new_card));
}

void Dealer::PrintHand() const
{
    std::cout << "Dealer hand: " << HandValue() << std::endl;

    for (const auto& card : dealer_hand)
    {
        card->PrintCard();
    }

    std::cout << std::endl;
}

void Dealer::DealerTurn(Deck& deck)
{
    InsertCard(deck.GrabCardFromDeck());
    PrintHand();

    while (true)
    {
        const int hand_value = HandValue();

        if (hand_value < DEALER_STANDS_ON_17)
        {
            std::cout << "Dealer hits..." << std::endl << std::endl;
            InsertCard(deck.GrabCardFromDeck());
            PrintHand();
        }
        else if (hand_value >= DEALER_STANDS_ON_17 && hand_value <= BLACKJACK)
        {
            std::cout << "Dealer stands..." << std::endl << std::endl;
            break;
        }
        else if (hand_value > BLACKJACK)
        {
            std::cout << "Dealer busts..." << std::endl << std::endl;
            break;
        }
    }

    dealer_hand.clear();
}

void Dealer::StartHand(Deck& deck)
{
    InsertCard(deck.GrabCardFromDeck());
    PrintHand();
}

int Dealer::HandValue() const
{
    int sum = 0;
    int number_of_aces = 0;

    for (const auto& card : dealer_hand)
    {
        if (card->CardValue() == 1)
        {
            number_of_aces++;
        }

        sum += card->CardValue();
    }

    if (number_of_aces > 0 && (sum + 10) <= BLACKJACK)
    {
        sum += 10;
    }

    return sum;
}
