#pragma once

#include <ostream>

#include "Card.h"

#include <array>

using Hand2 = std::array<Card, 2>;
using Hand4 = std::array<Card, 5>;
using Hand5 = std::array<Card, 5>;
using Hand6 = std::array<Card, 6>;
using Hand7 = std::array<Card, 7>;

Hand2 parseHand2(json::Value value);

std::vector<Card> parseHandN(json::Value value);

enum class HoleCardRank {
    ALLIN,
    RAISABLE,
    CALLABLE,
    FOLDABLE
};

HoleCardRank rankHoleCard(const Hand2& hand);

inline
std::ostream& operator<<(std::ostream& os, const std::array<Card, 2>& hand) {
    os << hand[0];
    for (int i = 1; i < hand.size(); ++i) {
        os << ", " << hand[i];
    }
    return os;
}

inline
std::ostream& operator<<(std::ostream& os, const std::array<Card, 5>& hand) {
    os << hand[0];
    for (int i = 1; i < hand.size(); ++i) {
        os << ", " << hand[i];
    }
    return os;
}
inline
std::ostream& operator<<(std::ostream& os, const std::array<Card, 6>& hand) {
    os << hand[0];
    for (int i = 1; i < hand.size(); ++i) {
        os << ", " << hand[i];
    }
    return os;
}
inline
std::ostream& operator<<(std::ostream& os, const std::array<Card, 7>& hand) {
    os << hand[0];
    for (int i = 1; i < hand.size(); ++i) {
        os << ", " << hand[i];
    }
    return os;
}
