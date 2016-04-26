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

    std::cerr << "XXXXXXXXXX Our hand is = " << hand << std::endl;

    return current_buy_in - our_bet + minimum_raise;
}

void Player::showdown(json::Value game_state)
{
}
