#include "Blackjack.h"
#include "Card.h"

int main()
{
    Deck deck{createDeck()};
    shuffleDeck(deck);

    if (playBlackjack(deck))
    {
        std::cout << "Player won\n";
    }
    else
        std::cout << "Player lost\n";

    return 0;
}