#include "Card.h"
#include "Deck.h"
#include "Player.h"

#include <iostream>

bool playerWantsHit();
bool playerTurn(Deck& deck, Player& player);
bool dealerTurn(Deck& deck, Player& dealer);

enum class Result
{
    player_won,
    player_lost,
    drawn,
};

Result playBlackJack(Deck& deck);

int main()
{
    Deck deck{};

    deck.shuffle();

    switch (playBlackJack(deck))
    {
        case Result::player_won:
            std::cout << "You won!\n";
            break;
        case Result::player_lost:
            std::cout << "You lose!\n";
            break;
        case Result::drawn:
            std::cout << "It was a draw!\n";
            break;
    }
}