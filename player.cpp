#include <iostream>

#include "player.h"
#include "Hand.h"

const char* Player::VERSION = "Non-Default C++ folding player";

int Player::betRequest(json::Value game_state) {
    int minimum_raise = game_state["minimum_raise"].ToInt();
    int in_action = game_state["in_action"].ToInt();

    int our_bet = game_state["players"][in_action]["bet"];

    int current_buy_in = game_state["current_buy_in"];

    Hand2 hand = parseHand(game_state["players"][in_action]["hole_cards"]);

    auto action = rankHoleCard(hand);

    std::cerr << "XXXXXXXXXX Our hand is = " << hand << std::endl;
    std::cerr << "XXXXXXXXX action is " << int(action) << std::endl;

    switch (action) {
        case HoleCardRank::RAISABLE:
            return current_buy_in - our_bet + minimum_raise;
        case HoleCardRank::FOLDABLE:
            return 0;
        case HoleCardRank::CALLABLE:
            return current_buy_in - our_bet;
    }
    return 0;
}

void Player::showdown(json::Value game_state)
{
}
