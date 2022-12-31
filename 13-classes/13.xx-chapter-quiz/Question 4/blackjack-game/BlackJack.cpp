#include "Card.h"
#include "Deck.h"
#include "Player.h"

#include <iostream>

bool playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit, (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
            case 'h':
                return true;
            case 's':
                return false;
        }
    }
}

// Returns true if the player went bust. False otherwise.
bool playerTurn(Deck& deck, Player& player)
{
    while (true)
    {
        if (player.is_bust())
        {
            std::cout << "You busted!\n";
            return true;
        }
        else
        {
            if (playerWantsHit())
            {
                Card card{player.drawCard(deck)};
                std::cout << "You were dealt a ";
                card.print();

                std::cout << " and now have score: " << player.score() << '\n';
            }
            else
            {
                // The player didn't go bust
                return false;
            }
        }
    }
}

// returns true if dealer went bust. False otherwise
bool dealerTurn(Deck& deck, Player& dealer)
{
    // Draw cards until we reach the minimum value
    while (dealer.score() < g_minimumDealerScore)
    {
        Card card{dealer.drawCard(deck)};
        std::cout << "The dealer turned up a ";
        card.print();

        std::cout << " and now has a score: " << dealer.score() << '\n';
    }

    if (dealer.is_bust())
    {
        std::cout << "The dealer busted\n";
        return true;
    }

    return false;
}

enum class Result
{
    player_won,
    player_lost,
    drawn,
};

Result playBlackJack(Deck& deck)
{
    // Create the dealer and give them 1 card.
    Player dealer{};
    dealer.drawCard(deck);

    // The dealer's card is face up, the player can see it
    std::cout << "The dealer is showing ";
    dealer.printHand();
    std::cout << ". Score: " << dealer.score() << '\n';

    // Create the player and give them 2 cards.
    Player player{};
    player.drawCard(deck);
    player.drawCard(deck);
    std::cout << "You have: ";
    player.printHand();
    std::cout << ". Score: " << player.score() << '\n';

    if (playerTurn(deck, player))
    {
        // The player went bust.
        return Result::player_lost;
    }

    if (dealerTurn(deck, dealer))
    {
        // The dealer went bust.
        return Result::player_won;
    }

    if (player.score() == dealer.score())
        return Result::drawn;

    return (player.score() > dealer.score()) ? Result::player_won
                                             : Result::player_lost;
}