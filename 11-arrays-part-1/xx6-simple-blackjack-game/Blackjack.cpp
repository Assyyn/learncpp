/* Start with the code you wrote in quiz #6. Create a function named
playBlackjack(). This function should:

1. Accept a shuffled deck of cards as a parameter.
2. Implement Blackjack as defined above (note: you can define other functions to
   help with this). Returns true if the player won, and false if they lost.

3. Also write a main() function to play a single game of Blackjack.
*/

#include "Blackjack.h"

Card fromDeck(Deck& deck)
{
    Card result;

    std::uniform_int_distribution r(0, 51);
    std::random_device rd;
    std::mt19937 mt{rd()};

    while (true)
    {
        int rIndex{r(mt)};
        Card& randomCard{
            deck[rIndex]}; // reference used to modify the actual Card in Deck

        // set rank to maxRank, which is not a real rank.
        // Cards in deck having rank maxRank are with the players
        if (randomCard.rank != Rank::maxRank)
        {
            result = randomCard;
            randomCard.rank = Rank::maxRank;
            break;
        }
    }
    return result;
}

void Player::receiveCard(Deck& deck)
{
    // get card from deck
    auto card{fromDeck(deck)};

    // store it in the vector(for future reference)
    cardsInHand.push_back(card);

    // increase total score by the card's value
    score += getCardValue(card);
}

void Player::printHand() const
{
    for (const auto& x : cardsInHand)
    {
        printCard(x);
        std::cout << ' ';
    }
}

// return player type
std::string_view pType(const Player& player)
{
    return (player.type == Player::Type::dealer) ? "Dealer" : "Player";
}

std::string Player::getName()
{
    // maximum characters in username
    constexpr int max_Usize{10};

    std::cout << pType(*this) << ": ";
    std::string username;
    std::cin >> username;

    return username.substr(0, max_Usize);
}

void startPhase(Deck& deck, Player& dealer, Player& user)
{
    // dealer gets one card to start
    dealer.receiveCard(deck);

    // player gets two cards to start
    user.receiveCard(deck);
    user.receiveCard(deck);
}

// print player stats
void printStats(const Player& player)
{
    std::cout << "Type: " << pType(player) << '\t'
              << "username: " << player.name << '\n';

    std::cout << "Hand: ";
    player.printHand();
    std::cout << '\t';

    std::cout << "Score: " << player.score << '\n';
}

// when player 'hits'
bool hit(Deck& deck, Player& player)
{
    std::cout << "\nHit!\n";
    player.receiveCard(deck);

    std::cout << "--> Drew a ";
    printCard(player.cardsInHand.back());
    std::cout << '\n';

    if (player.score > 21)
    {
        printStats(player);
        std::cout << player.name << " lost!\n";

        return false;
    }

    return true;
}

// when player 'stands'
bool stand(const Player& player)
{
    std::cout << "\nTotal Score for " << player.name << ": " << player.score
              << '\n';
    return false;
}

// asks choice of the player, returns it
char playerChoice()
{
    constexpr auto max_Ssize = std::numeric_limits<std::streamsize>::max();

    char choice{};
    while (true)
    {
        std::cout << "Hit or Stand(h/s): ";
        std::cin >> choice;

        if (choice == 'h' || choice == 's')
            return choice;
    }
}

// take action on player's choice
bool endTurn(char choice, Deck& deck, Player& player)
{
    switch (choice)
    {
        case 'h':
            return hit(deck, player);
        case 's':
            return stand(player);
        default: // will never occur
            return false;
    }
}

// returns false if the player lost, else returns true
bool PlayerTurn(Deck& deck, Player& player)
{
    bool hits{true};
    while (hits) // will only end when player stands or player lost
    {
        printStats(player);

        char choice{playerChoice()};
        hits = endTurn(choice, deck, player);
    }
    return true;
}

bool playBlackjack(Deck& deck)
{
    Player dealer{.type{Player::Type::dealer}};
    Player user{.type{Player::Type::player}};

    startPhase(deck, dealer, user);

    PlayerTurn(deck, user);

    return true;
}