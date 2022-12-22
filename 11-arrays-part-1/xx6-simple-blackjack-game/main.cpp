#include "Blackjack.h"
#include "Card.h"

int main()
{
    Deck deck{createDeck()};
    shuffleDeck(deck);
    Result results = playBlackjack(deck);
    if (results == won)
    {
        std::cout << "Player won\n";
    }
    else if (results == lost)
    {
        std::cout << "Player lost\n";
    }
    else
        std::cout << "Draw\n";

    return 0;
}