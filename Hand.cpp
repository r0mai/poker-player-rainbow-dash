#include "Hand.h"

Hand2 parseHand(json::Value value) {
    Hand2 hand;
    hand[0] = Card(value[size_t(0)]);
    hand[1] = Card(value[size_t(1)]);
    return hand;
}
