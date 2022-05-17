#include "Strategy.h"
#include "Player.h"
#include "Dealer.h"

#include <iostream>

Action Strategy::PlayerStrategy(const Player& player, const Dealer& dealer)
{
    Action player_action = Action::Undefined;

    if (!player.HandContainsAce() && !player.PairedHand())
    {
        player_action = RegularHandStrategy(player, dealer);
    }
    else if (player.HandContainsAce() && !player.PairedHand())
    {
        player_action = SoftHandStrategy(player, dealer);
    }
    else if (player.PairedHand())
    {
        player_action = PairedHandStrategy(player, dealer);
    }
    else
    {
        std::cout << "Error in Strategy::PlayerStrategy()" << std::endl;
    }

    return player_action;
}

Action Strategy::RegularHandStrategy(const Player& player, const Dealer& dealer)
{
    Action player_action = Action::Undefined;

    if (player.HandValue() >= 17)
    {
        player_action = Action::Stand;
    }
    else if (player.HandValue() <= 16 && player.HandValue() >= 13)
    {
        if (dealer.HandValue() >= 2 && dealer.HandValue() <= 6)
        {
            player_action = Action::Stand;
        }
        else if (dealer.HandValue() >= 7 && dealer.HandValue() <= 11)
        {
            player_action = Action::Hit;
        }
        else
        {
            std::cout << "Error in Strategy::RegularHandStrategy(): player.HandValue(16->13)" << std::endl;
        }
    }
    else if (player.HandValue() == 12)
    {
        if (dealer.HandValue() == 2 || dealer.HandValue() == 3)
        {
            player_action = Action::Hit;
        }
        else if (dealer.HandValue() >= 4 && dealer.HandValue() <= 6)
        {
            player_action = Action::Stand;
        }
        else if (dealer.HandValue() >= 7 && dealer.HandValue() <= 11)
        {
            player_action = Action::Hit;
        }
        else
        {
            std::cout << "Error in Strategy::RegularHandStrategy(): player.HandValue(12)" << std::endl;
        }
    }
    else if (player.HandValue() == 11)
    {
        if (dealer.HandValue() >= 2 && dealer.HandValue() <= 10)
        {
            player_action = Action::Double;
        }
        else if (dealer.HandValue() == 11)
        {
            player_action = Action::Hit;
        }
        else
        {
            std::cout << "Error in Strategy::RegularHandStrategy(): player.HandValue(11)" << std::endl;
        }
    }
    else if (player.HandValue() == 10)
    {
        if (dealer.HandValue() >= 2 && dealer.HandValue() <= 9)
        {
            player_action = Action::Double;
        }
        else if (dealer.HandValue() == 10 || dealer.HandValue() == 11)
        {
            player_action = Action::Hit;
        }
        else
        {
            std::cout << "Error in Strategy::RegularHandStrategy(): player.HandValue(10)" << std::endl;
        }
    }
    else if (player.HandValue() == 9)
    {
        if (dealer.HandValue() == 2)
        {
            player_action = Action::Hit;
        }
        else if (dealer.HandValue() >= 3 && dealer.HandValue() <= 6)
        {
            player_action = Action::Double;
        }
        else if (dealer.HandValue() >= 7 && dealer.HandValue() <= 11)
        {
            player_action = Action::Hit;
        }
        else
        {
            std::cout << "Error in Strategy::RegularHandStrategy(): player.HandValue(9)" << std::endl;
        }
    }
    else if (player.HandValue() >= 5 && player.HandValue() <= 8)
    {
        if (dealer.HandValue() >= 2 && dealer.HandValue() <= 11)
        {
            player_action = Action::Hit;
        }
        else
        {
            std::cout << "Error in Strategy::RegularHandStrategy(): player.HandValue(5->8)" << std::endl;
        }
    }
    else
    {
        std::cout << "Error in Strategy::RegularHandStrategy(): player.HandValue() not found." << std::endl;
    }

    return player_action;
}

Action Strategy::SoftHandStrategy(const Player& player, const Dealer& dealer)
{
    Action player_action = Action::Undefined;

    if (player.HandValue() == 21) // A,10
    {
        player_action = Action::Stand;
    }
    else if (player.HandValue() == 20) // A,9
    {
        player_action = Action::Stand;
    }
    else if (player.HandValue() == 19) // A,8
    {
        player_action = Action::Stand;
    }
    else if (player.HandValue() == 18) // A,7
    {
        if (dealer.HandValue() == 2)
        {
            player_action = Action::Split;
        }
        else if (dealer.HandValue() >= 3 && dealer.HandValue() <= 6)
        {
            player_action = Action::Double;
        }
        else if (dealer.HandValue() >= 7 && dealer.HandValue() <= 8)
        {
            player_action = Action::Stand;
        }
        else if (dealer.HandValue() >= 9 && dealer.HandValue() <= 11)
        {
            player_action = Action::Hit;
        }
        else
        {
            std::cout << "Error in Strategy::SoftHandStrategy() player.HandValue(A,7)." << std::endl;
        }
    }
    else if (player.HandValue() == 17) // A,6
    {
        if (dealer.HandValue() == 2)
        {
            player_action = Action::Hit;
        }
        else if (dealer.HandValue() >= 3 && dealer.HandValue() <= 6)
        {
            player_action = Action::Double;
        }
        else if (dealer.HandValue() >= 7 && dealer.HandValue() <= 11)
        {
            player_action = Action::Hit;
        }
        else
        {
            std::cout << "Error in Strategy::SoftHandStrategy() player.HandValue(A,6)." << std::endl;
        }
    }
    else if (player.HandValue() == 16) // A,5
    {
        if (dealer.HandValue() >= 2 && dealer.HandValue() <= 3)
        {
            player_action = Action::Hit;
        }
        else if (dealer.HandValue() >= 4 && dealer.HandValue() <= 6)
        {
            player_action = Action::Double;
        }
        else if (dealer.HandValue() >= 7 && dealer.HandValue() <= 11)
        {
            player_action = Action::Hit;
        }
        else
        {
            std::cout << "Error in Strategy::SoftHandStrategy() player.HandValue(A,5)." << std::endl;
        }
    }
    else if (player.HandValue() == 15) // A,4
    {
        if (dealer.HandValue() >= 2 && dealer.HandValue() <= 3)
        {
            player_action = Action::Hit;
        }
        else if (dealer.HandValue() >= 4 && dealer.HandValue() <= 6)
        {
            player_action = Action::Double;
        }
        else if (dealer.HandValue() >= 7 && dealer.HandValue() <= 11)
        {
            player_action = Action::Hit;
        }
        else
        {
            std::cout << "Error in Strategy::SoftHandStrategy() player.HandValue(A,4)." << std::endl;
        }
    }
    else if (player.HandValue() == 14) // A,3
    {
        if (dealer.HandValue() >= 2 && dealer.HandValue() <= 4)
        {
            player_action = Action::Hit;
        }
        else if (dealer.HandValue() >= 5 && dealer.HandValue() <= 6)
        {
            player_action = Action::Double;
        }
        else if (dealer.HandValue() >= 7 && dealer.HandValue() <= 11)
        {
            player_action = Action::Hit;
        }
        else
        {
            std::cout << "Error in Strategy::SoftHandStrategy() player.HandValue(A,3)." << std::endl;
        }
    }
    else if (player.HandValue() == 13) // A,2
    {
        if (dealer.HandValue() >= 2 && dealer.HandValue() <= 4)
        {
            player_action = Action::Hit;
        }
        else if (dealer.HandValue() >= 5 && dealer.HandValue() <= 6)
        {
            player_action = Action::Double;
        }
        else if (dealer.HandValue() >= 7 && dealer.HandValue() <= 11)
        {
            player_action = Action::Hit;
        }
        else
        {
            std::cout << "Error in Strategy::SoftHandStrategy() player.HandValue(A,2)." << std::endl;
        }
    }

    return player_action;
}

Action Strategy::PairedHandStrategy(const Player& player, const Dealer& dealer)
{
    Action player_action = Action::Undefined;

    if (player.HandValue() == 12 && player.HandContainsAce()) // Pair of Aces
    {
        player_action = Action::Split;
    }
    else if (player.HandValue() == 20) // Pair of Tens
    {
        player_action = Action::Stand;
    }
    else if (player.HandValue() == 18) // Pair of Nines
    {
        if (dealer.HandValue() >= 2 && dealer.HandValue() <= 6)
        {
            player_action = Action::Split;
        }
        else if (dealer.HandValue() == 7)
        {
            player_action = Action::Stand;
        }
        else if (dealer.HandValue() == 8 || dealer.HandValue() == 9)
        {
            player_action = Action::Split;
        }
        else if (dealer.HandValue() == 10 || dealer.HandValue() == 11)
        {
            player_action = Action::Stand;
        }
        else
        {
            std::cout << "Error in Strategy::PairedHandStrategy() player.HandValue(18)." << std::endl;
        }
    }
    else if (player.HandValue() == 16) // Pair of Eights
    {
        player_action = Action::Split;
    }
    else if (player.HandValue() == 14) // Pair of Sevens
    {
        if (dealer.HandValue() >= 2 && dealer.HandValue() <= 7)
        {
            player_action = Action::Split;
        }
        else if (dealer.HandValue() >= 8 && dealer.HandValue() <= 11)
        {
            player_action = Action::Hit;
        }
        else
        {
            std::cout << "Error in Strategy::PairedHandStrategy() player.HandValue(14)." << std::endl;
        }
    }
    else if (player.HandValue() == 12) // Pair of Sixes
    {
        if (dealer.HandValue() >= 2 && dealer.HandValue() <= 6)
        {
            player_action = Action::Split;
        }
        else if (dealer.HandValue() >= 7 && dealer.HandValue() <= 11)
        {
            player_action = Action::Hit;
        }
        else
        {
            std::cout << "Error in Strategy::PairedHandStrategy() player.HandValue(12)." << std::endl;
        }
    }
    else if (player.HandValue() == 10) // Pair of Fives
    {
        if (dealer.HandValue() >= 2 && dealer.HandValue() <= 9)
        {
            player_action = Action::Double;
        }
        else if (dealer.HandValue() >= 10 && dealer.HandValue() <= 11)
        {
            player_action = Action::Hit;
        }
        else
        {
            std::cout << "Error in Strategy::PairedHandStrategy() player.HandValue(10)." << std::endl;
        }
    }
    else if (player.HandValue() == 8) // Pair of Fours
    {
        if (dealer.HandValue() >= 2 && dealer.HandValue() <= 4)
        {
            player_action = Action::Hit;
        }
        else if (dealer.HandValue() >= 5 && dealer.HandValue() <= 6)
        {
            player_action = Action::Split;
        }
        else if (dealer.HandValue() >= 7 && dealer.HandValue() <= 11)
        {
            player_action = Action::Hit;
        }
        else
        {
            std::cout << "Error in Strategy::PairedHandStrategy() player.HandValue(8)." << std::endl;
        }
    }
    else if (player.HandValue() == 6) // Pair of Threes
    {
        if (dealer.HandValue() >= 2 && dealer.HandValue() <= 7)
        {
            player_action = Action::Split;
        }
        else if (dealer.HandValue() >= 8 && dealer.HandValue() <= 11)
        {
            player_action = Action::Hit;
        }
        else
        {
            std::cout << "Error in Strategy::PairedHandStrategy() player.HandValue(6)." << std::endl;
        }
    }
    else if (player.HandValue() == 4) // Pair of Twos
    {
        if (dealer.HandValue() >= 2 && dealer.HandValue() <= 7)
        {
            player_action = Action::Split;
        }
        else if (dealer.HandValue() >= 8 && dealer.HandValue() <= 11)
        {
            player_action = Action::Hit;
        }
        else
        {
            std::cout << "Error in Strategy::PairedHandStrategy() player.HandValue(4)." << std::endl;
        }
    }
    else
    {
        std::cout << "Error in Strategy::PairedHandStrategy(): player.HandValue() not found." << std::endl;
    }

    return player_action;
}
