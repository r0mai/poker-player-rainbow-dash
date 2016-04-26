#include "Hand.h"

Hand2 parseHand(json::Value value) {
    Hand2 hand;
    hand[0] = Card(value[size_t(0)]);
    hand[1] = Card(value[size_t(1)]);

    std::sort(hand.begin(), hand.end());

    return hand;
}

HoleCardRank rankHoleCard(const Hand2& hand) {
    bool suited = hand[0].suit == hand[1].suit;
    bool pair = hand[0].rank == hand[1].rank;

    auto r = HoleCardRank::RAISABLE;
    auto c = HoleCardRank::CALLABLE;
    auto f = HoleCardRank::FOLDABLE;

    HoleCardRank unsuited_table[15][15] = {
    //       0  1  2  3  4  5  6  7  8  9  T  J  Q  K  A
    /* 0 */ {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
    /* 1 */ {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
    /* 2 */ {f, f, r, f, f, f, f, f, f, f, f, f, f, f, r},
    /* 3 */ {f, f, f, r, f, f, f, f, f, f, f, f, f, f, r},
    /* 4 */ {f, f, f, f, r, f, f, f, f, f, f, f, f, f, r},
    /* 5 */ {f, f, f, f, f, r, f, f, f, f, f, f, f, f, r},
    /* 6 */ {f, f, f, f, f, f, r, f, f, f, f, f, f, f, r},
    /* 7 */ {f, f, f, f, f, f, f, r, f, f, f, f, f, f, r},
    /* 8 */ {f, f, f, f, f, f, f, f, r, f, f, f, f, f, r},
    /* 9 */ {f, f, f, f, f, f, f, f, f, r, f, f, f, f, r},
    /* T */ {f, f, f, f, f, f, f, f, f, f, r, c, r, r, r},
    /* J */ {f, f, f, f, f, f, f, f, f, f, f, r, r, r, r},
    /* Q */ {f, f, f, f, f, f, f, f, f, f, r, r, r, r, r},
    /* K */ {f, f, f, f, f, f, f, f, f, r, r, r, r, r, r},
    /* A */ {f, f, r, r, r, r, r, r, r, r, r, r, r, r, r}
    };

    HoleCardRank suited_table[15][15] = {
    //       0  1  2  3  4  5  6  7  8  9  T  J  Q  K  A
    /* 0 */ {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
    /* 1 */ {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
    /* 2 */ {f, f, r, f, f, f, f, f, f, f, f, f, f, f, r},
    /* 3 */ {f, f, f, r, c, f, f, f, f, f, f, f, f, f, r},
    /* 4 */ {f, f, f, c, r, c, f, f, f, f, f, f, f, f, r},
    /* 5 */ {f, f, f, f, c, r, c, f, f, f, f, f, f, f, r},
    /* 6 */ {f, f, f, f, f, c, r, c, f, f, f, f, f, f, r},
    /* 7 */ {f, f, f, f, f, f, c, r, c, f, f, f, f, f, r},
    /* 8 */ {f, f, f, f, f, f, f, c, r, c, c, f, f, f, r},
    /* 9 */ {f, f, f, f, f, f, f, f, c, r, r, c, f, f, r},
    /* T */ {f, f, f, f, f, f, f, f, c, r, r, r, r, r, r},
    /* J */ {f, f, f, f, f, f, f, f, f, c, r, r, r, r, r},
    /* Q */ {f, f, f, f, f, f, f, f, f, f, r, r, r, r, r},
    /* K */ {f, f, f, f, f, f, f, f, f, r, r, r, r, r, r},
    /* A */ {f, f, r, r, r, r, r, r, r, r, r, r, r, r, r}
    };

    return suited ? suited_table[hand[0].rank][hand[1].rank] :
                    unsuited_table[hand[0].rank][hand[1].rank];
}
