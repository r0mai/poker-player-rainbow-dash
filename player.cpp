#include <iostream>

#include "player.h"
#include "Hand.h"

const char* Player::VERSION = "Non-Default C++ folding player";

int minimum_raise;
int in_action;
int our_bet;
int current_buy_in;
Hand2 hole_cards;

int preFlop(json::Value game_state) {
    auto action = rankHoleCard(hole_cards);

    std::cerr << "XXXXXXXXX action is " << int(action) << std::endl;

    switch (action) {
        case HoleCardRank::ALLIN:
            return 5000;
        case HoleCardRank::RAISABLE:
            return current_buy_in - our_bet + 3*minimum_raise;
        case HoleCardRank::FOLDABLE:
            return 0;
        case HoleCardRank::CALLABLE:
            return current_buy_in - our_bet;
    }
    return 0;
}

int flop(json::Value game_state) {

}

int turn(json::Value game_state) {

}

int river(json::Value game_state) {

}

int Player::betRequest(json::Value game_state) {
    minimum_raise = game_state["minimum_raise"].ToInt();
    in_action = game_state["in_action"].ToInt();
    our_bet = game_state["players"][in_action]["bet"];
    current_buy_in = game_state["current_buy_in"];

    hole_cards = parseHand(game_state["players"][in_action]["hole_cards"]);

    std::cerr << "XXXXXXXXXX Our hand is = " << hole_cards << std::endl;

    return preFlop(game_state);
}

void Player::showdown(json::Value game_state)
{
}
