#include "Blackjack.h"
#include "Card.h"

#include <iostream>

int main()
{
	Deck deck{createDeck()};
	shuffleDeck(deck);

	if (const Result results = playBlackjack(deck); results == won)
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
