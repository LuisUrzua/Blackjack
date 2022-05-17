#include "Strategy.h"
#include "Player.h"
#include "Dealer.h"

Action Strategy::PlayerStrategy(const Player& player, const Dealer& dealer)
{
    if (!player.HandContainsAce() && !player.PairedHand())
    {
        RegularHandStrategy(player, dealer);
    }
    else if (player.HandContainsAce() && !player.PairedHand())
    {

    }
    else if (player.PairedHand())
    {

    }

    return Action::Undefined;
}

Action Strategy::RegularHandStrategy(const Player& player, const Dealer& dealer)
{
    return Action::Undefined;
}

Action Strategy::SoftHandStrategy(const Player& player, const Dealer& dealer)
{
    return Action::Undefined;
}

Action Strategy::PairedHandStrategy(const Player& player, const Dealer& dealer)
{
    return Action::Undefined;
}
