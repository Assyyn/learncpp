#ifndef CARD_H
#define CARD_H

#include <array>

// represents the Suit of a Card
enum Suit
{
    club,
    diamond,
    heart,
    spade,

    maxSuits,
};

// represents the Rank of a Card
enum Rank
{
    rank_2 = 2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    jack,
    queen,
    king,
    ace,

    maxRank,
};

/* b) Each card will be represented by a struct named Card that contains a rank
 * and a suit. Create the struct.
 */

// A typical Card in our game, by default the first card in a default deck
struct Card
{
    Rank rank{Rank::rank_2};
    Suit suit{Suit::club};
};

// returns rank initial, helper function for printCard()
char rankInitial(const Rank& rank);

// returns suit initial, helper function for printCard()
char suitInitial(const Suit& suit);

// prints card initials, e.g. Joker of Spades = JS.
void printCard(const Card& card);

// sets card value, helper function to create a default deck of order
// Club, Diamond, Hearts, Spade
void set(Card& card);

// A Deck is always 52 cards in our game
using Deck = std::array<Card, 52>;

// creates a default deck of order Club, Diamond, Hearts, Spade arranged by
// value
Deck createDeck();

// shuffles the given deck
void shuffleDeck(Deck& deck);

// returns the value of given card
int getCardValue(const Card& card);

// prints out a deck
void printDeck(const Deck& deck);

#endif