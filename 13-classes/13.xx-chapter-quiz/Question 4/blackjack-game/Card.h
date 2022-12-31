#ifndef CARD_H
#define CARD_H

#include <array>
#include <cassert>
#include <iostream>
#include <string_view>

class Card
{
public:
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
        rank_jack,
        rank_queen,
        rank_king,
        rank_ace,

        max_rank,
    };

    enum Suit
    {
        club,
        diamond,
        heart,
        spade,

        max_suits,
    };

private:
    Rank m_rank{};
    Suit m_suit{};

public:
    Card() = default;

    Card(Rank rank, Suit suit) : m_rank{rank}, m_suit{suit} {}

    void print() const;

    int value() const;
};

#endif