#pragma once

enum class Action
{
    Hit,
    Stand,
    Undefined,
};

class Input
{
public:
    Action ReadInput();
};

