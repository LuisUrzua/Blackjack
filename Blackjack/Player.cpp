#include "Player.h"
#include "Card.h"

#include <iostream>

void Player::InsertCard(CardPtr new_card)
{
    player_hand.push_back(std::move(new_card));
}

void Player::PrintHand() const
{
    std::cout << "Size of player hand: " << player_hand.size() << std::endl;

    for (const auto& card : player_hand)
    {
        card->PrintCard();
    }
}
