/* Question #6

Let’s pretend we’re writing a card game.
*/

/* a) A deck of cards has 52 unique cards (13 card ranks of 4 suits). Create
 * enumerations for the card ranks (2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen,
 * King, Ace) and suits (clubs, diamonds, hearts, spades). Those enumerators
 * will not be used to index arrays.
 */
enum class Suit
{
    club,
    diamond,
    heart,
    spade,

    maxSuits,
};

enum class Rank
{
    two = 2,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace,

    maxRank,
};

/* b) Each card will be represented by a struct named Card that contains a rank
 * and a suit. Create the struct.
 */
struct Card
{
    Suit suit{Suit::club};
    Rank rank{Rank::two};
};

/* c) Create a printCard() function that takes a const Card reference as a
 * parameter and prints the card rank and suit as a 2-letter code (e.g. the jack
 * of spades would print as JS).
 */
char rankInitial(const Rank rank)
{
    using enum Rank;

    switch (rank)
    {
        case two:
        case three:
        case four:
        case five:
        case six:
        case seven:
        case eight:
        case nine:
            return '0' + static_cast<int>(rank);

        case ten:
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

    std::cout << rI << sI << '\n';
}