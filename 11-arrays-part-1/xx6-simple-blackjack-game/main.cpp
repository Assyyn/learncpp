#include "Blackjack.h"
#include "Card.h"

int main()
{
    Deck deck{createDeck()};
    shuffleDeck(deck);

    playBlackjack(deck);

    return 0;
}