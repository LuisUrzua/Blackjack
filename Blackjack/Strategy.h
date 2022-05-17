#pragma once

class Player;
class Dealer;

enum class Action
{
    Hit,
    Stand,
    Double_Down,
    Split,
    Undefined,
};

class Strategy
{
public:
    Action PlayerStrategy(const Player&, const Dealer&);

private:
    Action RegularHandStrategy(const Player&, const Dealer&);
    Action SoftHandStrategy(const Player&, const Dealer&);
    Action PairedHandStrategy(const Player&, const Dealer&);
};

