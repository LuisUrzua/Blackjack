#pragma once

enum class PlayerAction
{
    Hit,
    Stand,
    Double,
    Split,
    Undefined,
};

class Input
{
public:
    PlayerAction ReadInput();
};

