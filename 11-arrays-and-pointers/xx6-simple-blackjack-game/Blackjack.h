#ifndef BLJ_H
#define BLJ_H

#include "Card.h"

#include <string>
#include <string_view>
#include <vector>

// A 'User' in the game of Blackjack
struct User
{
    // enum to differentiate player 'type' (dealer/player)
    enum Type
    {
        dealer,
        player,
    };

    // current player status
    enum Status
    {
        stand,
        lost,
        idle,
    };

    // player type:
    Type type;

    // player status:
    Status status{idle}; // idle by default

    // User name:
    std::string name{getName()};

    // the cards in the players hand
    std::vector<Card> cardsInHand;

    // total score of cards in hand
    int score{0};

    // retrieves a card from deck, and places it in hand
    void drawFrom(Deck& deck);

    // print player's hand
    void printHand() const;

    // asks for username and returns it
    [[nodiscard]]std::string getName() const;
};

enum Result
{
    draw,
    won,
    lost,
};

// print player stats
void printStats(const User& player);

// returns a card from given deck
Card fromDeck(Deck& deck);

// the starting phase: dealer and player are dealt their cards
void startPhase(Deck& deck, User& dealer, User& player);

// play the game of blackjack
Result playBlackjack(Deck& deck);

#endif