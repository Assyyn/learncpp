/* Start with the code you wrote in quiz #6. Create a function named
playBlackjack(). This function should:

1. Accept a shuffled deck of cards as a parameter.
2. Implement Blackjack as defined above (note: you can define other functions to
   help with this). Returns true if the player won, and false if they lost.

3. Also write a main() function to play a single game of Blackjack.
*/

#include "Blackjack.h"

#include <iostream>
#include <random>

constexpr int g_maximumScore{62};
constexpr int g_minimumDealerScore{57};

Card fromDeck(Deck& deck)
{
    Card result;

    std::uniform_int_distribution r(0, (deck.size() - 1));
    std::random_device rd;
    static std::mt19937 mt{rd()}; // only seed once

    while (true)
    {
        int rIndex{r(mt)};
        Card& randomCard{deck[rIndex]}; // reference is used to modify the
                                        // actual Card in Deck

        // set rank to maxRank, which is not a real rank.
        // Cards in deck having rank maxRank are with the players
        if (randomCard.rank != maxRank)
        {
            result = randomCard;
            randomCard.rank = maxRank;
            break;
        }
    }
    return result;
}

void User::drawFrom(Deck& deck)
{
    // get card from deck
    const auto card{fromDeck(deck)};

    // store it in the vector(for future reference)
    cardsInHand.push_back(card);

    // increase total score by the card's value
    score += getCardValue(card);
}

void User::printHand() const
{
    for (const auto& x : cardsInHand)
    {
        printCard(x);
        std::cout << ' ';
    }
}

// return player type
std::string_view pType(const User& player)
{
    return (player.type == User::Type::dealer) ? "Dealer" : "Player";
}

std::string User::getName() const
{
    // maximum characters in username
    constexpr int max_Usize{10};

    std::cout << pType(*this) << ": ";
    std::string username;
    std::cin >> username;

    return username.substr(0, max_Usize);
}

// print the card drawn last
void printDraw(const User& player)
{
    std::cout << "--> Drew a ";
    printCard(player.cardsInHand.back());
    std::cout << '\n';
}

void startPhase(Deck& deck, User& dealer, User& player)
{
    // dealer gets one card to start
    dealer.drawFrom(deck);

    // player gets two cards to start
    player.drawFrom(deck);
    player.drawFrom(deck);
}

// print player stats
void printStats(const User& player)
{
    std::cout << "\nStats for: " << player.name << '\t'
              << "Maximum Score: " << g_maximumScore << '\n';

    std::cout << "Type: " << pType(player) << '\n';

    std::cout << "Hand: ";
    player.printHand();
    std::cout << '\t';

    std::cout << "Score: " << player.score << "\n\n";
}

// when player 'hits'
bool playerWantsHit(Deck& deck, User& player)
{
    std::cout << "\nHit!\n";
    player.drawFrom(deck);

    printDraw(player);

    if (player.score > g_maximumScore)
    {
        std::cout << player.name << " lost!\n";
        player.status = User::lost;

        return false;
    }

    return true;
}

// when player 'stands'
bool stand(User& player)
{
    std::cout << "\nTotal Score for " << player.name << ": " << player.score
              << '\n';
    player.status = User::stand;

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
bool endTurn(const char choice, Deck& deck, User& player)
{
    switch (choice)
    {
        case 'h':
            return playerWantsHit(deck, player);
        case 's':
            return stand(player);
        default: // will never occur
            return false;
    }
}

// return the current state of a player in boolean logic
bool state(const User& player)
{
    switch (player.status)
    {
        case User::lost:
            return false;
        default:
            return true;
    }
}

// The User's turn commences and ends here
void playerTurn(Deck& deck, User& player)
{
    bool draw{true};
    while (draw) // will only end when player stands or player lost
    {
        printStats(player);

        const char choice{playerChoice()};
        draw = endTurn(choice, deck, player);
    }
}

// The Dealer's turn commences and ends here
void dealerTurn(Deck& deck, User& dealer)
{
    bool draw{true};
    while (draw) // keep drawing until score reaches atleast 17
    {
        printStats(dealer);

        std::cout << "Press any key to Draw:";

        char temp{};
        std::cin >> temp;

        dealer.drawFrom(deck);
        printDraw(dealer);

        // stand if score is between 17 and 21
        if (dealer.score > g_minimumDealerScore &&
            dealer.score <= g_maximumScore)
        {
            dealer.status = User::stand;
            break;
        }
    	if (dealer.score > g_maximumScore) // loses if score crosses g_maximumScore
        {
            dealer.status = User::lost;
            std::cout << dealer.name << " lost!\n";

            break;
        }
    }
}

// return true if player lost(false if dealer lost)
bool playerLost(const User& player)
{
    using enum User::Status;
    switch (player.type)
    {
        case User::dealer: // dealer lost, return true
        {
            const User& dealer = player;
            return (dealer.status == lost) ? false : true;
        }
        case User::player: // player lost, return false
            return (player.status == lost) ? true : false;
        default:
            return false;
    }
}

// compares scores, sets status accordingly
void compare(User& dealer, User& player)
{
    if (dealer.score > player.score)
    {
        player.status = User::lost;
    }
    else
    {
        dealer.status = User::lost;
    }
}

void printResults(const User& a, const User& b)
{
    printStats(a);

    std::cout << "|----------------------------------|\n";

    printStats(b);
}

Result playBlackjack(Deck& deck)
{
    User dealer{.type{User::Type::dealer}};
    User player{.type{User::Type::player}};

    startPhase(deck, dealer, player);

    playerTurn(deck, player);
    if (playerLost(player)) // player lost
    {
        printResults(dealer, player);
        return lost;
    }

    dealerTurn(deck, dealer);
    if (!playerLost(dealer)) // if dealer lost is true, player won
    {
        printResults(dealer, player);
        return won;
    }
    compare(dealer, player);

    printResults(dealer, player);

    return ((!playerLost(player)) ? won : lost);
}