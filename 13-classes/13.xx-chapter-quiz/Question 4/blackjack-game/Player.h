#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Deck.h"

#include <iostream>
#include <vector>

// maximum score before losing
constexpr inline int g_maximumScore{21};

// minimum score that the dealer has to have
constexpr inline int g_minimumDealerScore{17};

class Player
{
public:
    using Hand = std::vector<Card>;

private:
    Hand m_hand{};
    int m_score{};

public:
    Player() = default;

    int score() const
    {
        return m_score;
    }

    bool is_bust() const
    {
        return m_score > g_maximumScore;
    }

    const Card& drawCard(Deck& deck);

    void printHand() const;
};

#endif