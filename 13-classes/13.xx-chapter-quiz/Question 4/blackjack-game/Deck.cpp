#include "Deck.h"

void Deck::print() const
{
    for (const auto& card : m_deck)
    {
        card.print();
        std::cout << ' ';
    }

    std::cout << '\n';
}

void Deck::shuffle()
{
    std::random_device rd;
    std::seed_seq ssq{rd(), rd(), rd(), rd(), rd(), rd(), rd()};

    std::mt19937 mt{ssq};

    std::shuffle(m_deck.begin(), m_deck.end(), mt);

    m_cardIndex = 0;
}

const Card& Deck::dealCard()
{
    assert(m_cardIndex < m_deck.size());

    return m_deck[m_cardIndex++];
}