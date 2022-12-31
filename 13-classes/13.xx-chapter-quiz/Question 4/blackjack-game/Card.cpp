#include "Card.h"

void Card::print() const
{
    auto rankInitial{[*this]() -> char {
        if (value() < 10 && value() >= 2)
            return static_cast<char>(value()) + '0';

        switch (m_rank)
        {
            case rank_10:
                return 'T';
            case rank_jack:
                return 'J';
            case rank_queen:
                return 'Q';
            case rank_king:
                return 'K';
            case rank_ace:
                return 'A';
            default:
                return '?';
        }
    }};

    auto suitInitial{[*this] {
        switch (m_suit)
        {
            case club:
                return 'C';
            case diamond:
                return 'D';
            case heart:
                return 'H';
            case spade:
                return 'S';
            default:
                return '?';
        }
    }};

    std::cout << rankInitial() << suitInitial();
}

int Card::value() const
{
    if (m_rank == rank_ace)
        return 11;

    if (m_rank == rank_jack || m_rank == rank_queen || m_rank == rank_king)
        return 10;

    return static_cast<int>(m_rank);
}