#pragma once

#include <ostream>

#include "Card.h"

#include <array>

using Hand2 = std::array<Card, 2>;
using Hand5 = std::array<Card, 5>;
using Hand6 = std::array<Card, 6>;
using Hand7 = std::array<Card, 7>;

Hand2 parseHand(json::Value value);

template<int N>
std::ostream& operator<<(std::ostream& os, const std::array<Card, N>& hand) {
    os << hand[0];
    for (int i = 1; i < hand.size(); ++i) {
        os << ", " << hand[i];
    }
    return os;
}
