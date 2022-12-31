#ifndef DECK_H
#define DECK_H

#include "Card.h"

#include <algorithm>
#include <array>
#include <iostream>
#include <random>

class Deck
{
public:
    using DeckType = std::array<Card, 52>;
    using Index = DeckType::size_type;

private:
    class init_Deck
    {
    public:
        static inline DeckType defaultDeck()
        {
            int index{0};

            DeckType deck;
            for (int suit{Card::club}; suit < Card::max_suits; ++suit)
            {
                for (int rank{Card::rank_2}; rank < Card::max_rank; ++rank)
                {
                    deck[index] = Card{static_cast<Card::Rank>(rank),
                                       static_cast<Card::Suit>(suit)};
                    ++index;
                }
            }
            return deck;
        }
    };

    DeckType m_deck{};
    Index m_cardIndex{};

public:
    Deck() : m_deck{init_Deck::defaultDeck()}, m_cardIndex{0} {}

    void print() const;

    void shuffle();

    const Card& dealCard();
};

#endif