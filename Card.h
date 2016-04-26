#pragma once

enum class Suit {
    SPADE,
    DIAMOND,
    HEART,
    CLUB
};

const int TEN = 10;
const int JACK = 11;
const int QUEEN = 12;
const int KING = 13;
const int ACE = 14;

class Card {
public:
    Suit suit;
    int rank;
};
