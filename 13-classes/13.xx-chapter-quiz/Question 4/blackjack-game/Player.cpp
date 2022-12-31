#include "Player.h"

const Card& Player::drawCard(Deck& deck)
{
    Card card{deck.dealCard()};
    m_hand.push_back(card);
    m_score += card.value();

    // as it is the card that was just drawn and will not be modified, returned
    // reference to the top of Player's hand
    return m_hand.back();
}

void Player::printHand() const
{
    for (const auto& card : m_hand)
    {
        card.print();
        std::cout << ' ';
    }
}
