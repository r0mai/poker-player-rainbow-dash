#include "Hand.h"

#include <algorithm>

Hand2 parseHand2(json::Value value) {
    Hand2 hand;
    hand[0] = Card(value[size_t(0)]);
    hand[1] = Card(value[size_t(1)]);

    std::sort(hand.begin(), hand.end());

    return hand;
}

std::vector<Card> parseHandN(json::Value value) {
    std::vector<Card> hand;
    for (int i = 0; i < value.size(); ++i) {
        hand.push_back(Card{value[size_t(i)]});
    }
    std::sort(hand.begin(), hand.end());
    return hand;
}

HoleCardRank rankHoleCard(const Hand2& hand) {
    bool suited = hand[0].suit == hand[1].suit;
    bool pair = hand[0].rank == hand[1].rank;

    auto a = HoleCardRank::ALLIN;
    auto r = HoleCardRank::RAISABLE;
    auto c = HoleCardRank::CALLABLE;
    auto f = HoleCardRank::FOLDABLE;

    HoleCardRank unsuited_table[15][15] = {
    //       0  1  2  3  4  5  6  7  8  9  T  J  Q  K  A
    /* 0 */ {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
    /* 1 */ {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
    /* 2 */ {f, f, r, f, f, f, f, f, f, f, f, f, f, f, f},
    /* 3 */ {f, f, f, r, f, f, f, f, f, f, f, f, f, f, f},
    /* 4 */ {f, f, f, f, r, f, f, f, f, f, f, f, f, f, f},
    /* 5 */ {f, f, f, f, f, r, f, f, f, f, f, f, f, f, c},
    /* 6 */ {f, f, f, f, f, f, r, f, f, f, f, f, f, f, c},
    /* 7 */ {f, f, f, f, f, f, f, r, f, f, f, f, f, f, c},
    /* 8 */ {f, f, f, f, f, f, f, f, r, f, f, f, f, f, c},
    /* 9 */ {f, f, f, f, f, f, f, f, f, r, f, f, f, f, c},
    /* T */ {f, f, f, f, f, f, f, f, f, f, a, c, r, r, r},
    /* J */ {f, f, f, f, f, f, f, f, f, f, c, a, r, r, r},
    /* Q */ {f, f, f, f, f, f, f, f, f, f, r, r, a, r, r},
    /* K */ {f, f, f, f, f, f, f, f, f, f, c, r, r, a, r},
    /* A */ {f, f, f, f, f, c, c, c, c, c, r, r, r, r, a}
    };

    HoleCardRank suited_table[15][15] = {
    //       0  1  2  3  4  5  6  7  8  9  T  J  Q  K  A
    /* 0 */ {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
    /* 1 */ {f, f, f, f, f, f, f, f, f, f, f, f, f, f, f},
    /* 2 */ {f, f, r, f, f, f, f, f, f, f, f, f, f, f, c},
    /* 3 */ {f, f, f, r, c, f, f, f, f, f, f, f, f, f, c},
    /* 4 */ {f, f, f, c, r, c, f, f, f, f, f, f, f, f, c},
    /* 5 */ {f, f, f, f, c, r, c, f, f, f, f, f, f, f, c},
    /* 6 */ {f, f, f, f, f, c, r, c, f, f, f, f, f, f, c},
    /* 7 */ {f, f, f, f, f, f, c, r, c, f, f, f, f, f, c},
    /* 8 */ {f, f, f, f, f, f, f, c, r, c, c, f, f, f, r},
    /* 9 */ {f, f, f, f, f, f, f, f, c, r, r, c, f, f, r},
    /* T */ {f, f, f, f, f, f, f, f, c, r, r, r, r, r, r},
    /* J */ {f, f, f, f, f, f, f, f, f, c, r, r, r, r, a},
    /* Q */ {f, f, f, f, f, f, f, f, f, f, r, r, r, r, a},
    /* K */ {f, f, f, f, f, f, f, f, f, r, r, r, r, r, a},
    /* A */ {f, f, c, c, c, c, c, c, r, r, r, a, a, a, r}
    };

    return suited ? suited_table[hand[0].rank][hand[1].rank] :
                    unsuited_table[hand[0].rank][hand[1].rank];
}
