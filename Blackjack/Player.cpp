#include "Player.h"
#include "Card.h"
#include "Deck.h"
#include "Input.h"
#include "Strategy.h"

#include <iostream>
#include <stdlib.h>

#define BLACKJACK 21

void Player::InsertCard(CardPtr new_card)
{
    player_hand.push_back(std::move(new_card));
}

void Player::PrintHand() const
{
    std::cout << "Player hand: " << HandValue() << std::endl;

    for (const auto& card : player_hand)
    {
        card->PrintCard();
    }

    std::cout << std::endl;
}

void Player::PlayerTurn(Input& input, Deck& deck)
{
    PlayerAction action = PlayerAction::Undefined;

    while (true)
    {
        action = input.ReadInput();

        if (action == PlayerAction::Hit)
        {
            std::cout << "Player hits..." << std::endl << std::endl;
            InsertCard(deck.GrabCardFromDeck());
            PrintHand();

            if (HandValue() > BLACKJACK)
            {
                std::cout << "Player busts..." << std::endl << std::endl;
                break;
            }

            continue;
        }
        else if (action == PlayerAction::Stand)
        {
            std::cout << "Player stands..." << std::endl << std::endl;
            break;
        }
        else
        {
            /* Undefined */
            std::cout << "Error: PlayerTurn() undefined." << std::endl;
        }
    }

    //system("cls");
    player_hand.clear();
}

void Player::PlayerTurn(const Dealer& dealer, Deck& deck)
{
    Action action = Action::Undefined;
    StrategyPtr basic_strategy = std::make_unique<Strategy>(Strategy());

    while (true)
    {
        action = basic_strategy->PlayerStrategy(*this, dealer);

        if (action == Action::Hit)
        {
            std::cout << "Player hits..." << std::endl << std::endl;
            InsertCard(deck.GrabCardFromDeck());
            PrintHand();

            if (HandValue() > BLACKJACK)
            {
                std::cout << "Player busts..." << std::endl << std::endl;
                break;
            }

            continue;
        }
        else if (action == Action::Stand)
        {
            std::cout << "Player stands..." << std::endl << std::endl;
            break;
        }
        else if (action == Action::Double)
        {
            std::cout << "Player doubles..." << std::endl << std::endl;
            InsertCard(deck.GrabCardFromDeck());
            PrintHand();
            // DoubleWager();

            if (HandValue() > BLACKJACK)
            {
                std::cout << "Player busts..." << std::endl << std::endl;
                break;
            }

            break;
        }
        else if (action == Action::Split)
        {
            std::cout << "Player splits..." << std::endl << std::endl;
            // SplitHand();
            break;
        }
        else if (action == Action::Undefined)
        {
            std::cout << "Error in Player::PlayerTurn() action undefined" << std::endl << std::endl;
            break;
        }
    }
}

void Player::StartHand(Deck& deck)
{
    InsertCard(deck.GrabCardFromDeck());
    InsertCard(deck.GrabCardFromDeck());
    PrintHand();
}

int Player::HandValue() const
{
    int sum = 0;
    int number_of_aces = 0;

    for (const auto& card : player_hand)
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

bool Player::HandContainsAce() const
{
    for (const auto& card : player_hand)
    {
        if (card->GetRank() == Rank::Ace)
        {
            return true;
        }
    }

    return false;
}

bool Player::PairedHand() const
{
    if (player_hand.size() != 2)
    {
        return false;
    }

    if (player_hand.at(0)->CardValue() == player_hand.at(1)->CardValue())
    {
        return true;
    }

    return false;
}
