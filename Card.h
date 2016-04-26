#pragma once

#include <ostream>

#include "json.h"

enum class Suit {
    SPADE,
    DIAMOND,
    HEART,
    CLUB
};

const int JACK = 11;
const int QUEEN = 12;
const int KING = 13;
const int ACE = 14;

class Card {
public:
    Card() = default;
    Card(json::Value value);
    Card(Suit suit, int rank) : suit(suit), rank(rank) {}

    Suit suit = Suit::SPADE;
    int rank = ACE;
};

std::ostream& operator<<(std::ostream& os, const Suit& suit);
std::ostream& operator<<(std::ostream& os, const Card& card);
