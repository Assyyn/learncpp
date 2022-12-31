# testing the classes and functions for blackjack-game

```cpp
#include "Card.h"
#include "Deck.h"
#include "Player.h"

#include <iostream>

int main()
{
    std::cout << "test a):\n";

    // test a)
    const Card cardQueenHearts{Card::rank_queen, Card::heart};
    cardQueenHearts.print();
    std::cout << " has the value " << cardQueenHearts.value() << '\n';

    std::cout << "\ntest b) and c):\n";

    // test b) & c)
    Deck deck{};
    deck.shuffle();
    deck.print();

    std::cout << "The first card has value: " << deck.dealCard().value()
              << '\n';
    std::cout << "The second card has value: " << deck.dealCard().value()
              << '\n';

    std::cout << "\ntest d):\n";

    // test d)
    Deck deck2{};
    deck2.shuffle();
    deck2.print();

    Player player{};
    Player dealer{};

    Card playerCard{player.drawCard(deck2)};
    std::cout << "The player drew a card with value " << playerCard.value()
              << " and now has score " << player.score() << '\n';

    Card dealerCard{dealer.drawCard(deck2)};
    std::cout << "The dealer drew a card with value " << dealerCard.value()
              << " and now has score " << dealer.score() << '\n';

    return 0;
}
```
