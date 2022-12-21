#include "Card.h"

/* c) Create a printCard() function that takes a const Card reference as a
 * parameter and prints the card rank and suit as a 2-letter code (e.g. the jack
 * of spades would print as JS).
 */
char rankInitial(const Rank& rank)
{
    using enum Rank;

    switch (rank)
    {
        case rank_2:
        case rank_3:
        case rank_4:
        case rank_5:
        case rank_6:
        case rank_7:
        case rank_8:
        case rank_9:
            return '0' + static_cast<int>(rank);

        case rank_10:
            return 'T';
        case jack:
            return 'J';
        case queen:
            return 'Q';
        case king:
            return 'K';
        case ace:
            return 'A';
        default:
            return '?';
    }
}

char suitInitial(const Suit& suit)
{
    using enum Suit;

    switch (suit)
    {
        case club:
            return 'C';
        case diamond:
            return 'D';
        case spade:
            return 'S';
        case heart:
            return 'H';
        default:
            return '?';
    }
}

void printCard(const Card& card)
{
    auto rI{rankInitial(card.rank)};
    auto sI{suitInitial(card.suit)};

    std::cout << rI << sI;
}

/* d) A deck of cards has 52 cards. Create an array (using std::array) to
 * represent the deck of cards, and initialize it with one of each card. Do this
 * in a function named createDeck and call createDeck from main. createDeck
 * should return the deck to main.
 */

void set(Card& card)
{
    static int rank{2};
    static int suit{0};
    if (rank == static_cast<int>(Rank::maxRank))
    {
        rank = 2;
        suit++;
    }
    if (suit == static_cast<int>(Suit::maxSuits))
    {
        suit = 0;
    }

    card.rank = static_cast<Rank>(rank++);
    card.suit = static_cast<Suit>(suit);
}

Deck createDeck()
{
    Deck deck;

    std::for_each(deck.begin(), deck.end(), set);

    return deck;
}

/* f) Write a function named shuffleDeck to shuffle the deck of cards using
 * std::shuffle. Update your main function to shuffle the deck and print out the
 * shuffled deck.
 */
void shuffleDeck(Deck& deck)
{
    // create and seed PRNG
    std::random_device rd;
    std::mt19937 mt(rd());

    std::shuffle(deck.begin(), deck.end(), mt);
}

/* g) Write a function named getCardValue() that returns the value of a Card
 * (e.g. a 2 is worth 2, a ten, jack, queen, or king is worth 10. Assume an Ace
 * is worth 11).
 */
int getCardValue(const Card& card)
{
    auto cardValue{static_cast<int>(card.rank)};
    if ((Rank)cardValue < Rank::rank_2 || (Rank)cardValue > Rank::maxRank)
        assert(false && "should never happen");

    if (cardValue == (int)Rank::ace)
        return 11;

    if (cardValue >= (int)Rank::rank_10 && cardValue <= (int)Rank::king)
        return 10;

    return cardValue;
}

void printDeck(const Deck& deck)
{
    for (const auto& card : deck)
    {
        printCard(card);
        std::cout << ' ';
    }
    std::cout << '\n';
}