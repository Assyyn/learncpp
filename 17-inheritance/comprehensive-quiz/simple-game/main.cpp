#include "Game.h"

#include <iostream>
#include <string>

int main()
{
    Game game;

    while (true)
    {
        game.play();

        if (game.playAgain())
            game.reset();
        else
            break;
    }

    return 0;
}