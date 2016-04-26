#include <iostream>

#include "player.h"
#include "Hand.h"

const char* Player::VERSION = "Pwnies";

int minimum_raise;
int in_action;
int our_bet;
int current_buy_in;
Hand2 hole_cards;

int toAction(HoleCardRank rank) {
    std::cerr << "XXXXXXXXX action is " << int(rank) << std::endl;

    switch (rank) {
        case HoleCardRank::ALLIN:
            return 5000;
        case HoleCardRank::RAISABLE:
            return current_buy_in - our_bet + 3*minimum_raise;
        default:
            std::cerr << "Unknown action" << std::endl;
        case HoleCardRank::FOLDABLE:
            return 0;
        case HoleCardRank::CALLABLE:
            return current_buy_in - our_bet;
    }
}

int preFlop(json::Value game_state) {
    return toAction(rankHoleCard(hole_cards));
}

int flop(json::Value game_state) {
    if (!game_state.HasKey("eval")) {
        std::cerr << "NO eval in flop()" << std::endl;
        return preFlop(game_state);
    }

    int rank = game_state["eval"]["rank"].ToInt();

    switch (rank) {
        default:
            std::cerr << "Unknown rank" << std::endl;
        case 0: return toAction(HoleCardRank::FOLDABLE);
        case 1: return toAction(HoleCardRank::CALLABLE);
        case 2: return toAction(HoleCardRank::CALLABLE);
        case 3: return toAction(HoleCardRank::RAISABLE);
        case 4: return toAction(HoleCardRank::RAISABLE);
        case 5: return toAction(HoleCardRank::ALLIN);
        case 6: return toAction(HoleCardRank::ALLIN);
        case 7: return toAction(HoleCardRank::ALLIN);
        case 8: return toAction(HoleCardRank::ALLIN);
    }
}

int turn(json::Value game_state) {
    if (!game_state.HasKey("eval")) {
        std::cerr << "NO eval in turn()" << std::endl;
        return preFlop(game_state);
    }
    return flop(game_state);
}

int river(json::Value game_state) {
    if (!game_state.HasKey("eval")) {
        std::cerr << "NO eval in river()" << std::endl;
        return preFlop(game_state);
    }
    return flop(game_state);
}

int Player::betRequest(json::Value game_state) {
    minimum_raise = game_state["minimum_raise"].ToInt();
    in_action = game_state["in_action"].ToInt();
    our_bet = game_state["players"][in_action]["bet"];
    current_buy_in = game_state["current_buy_in"];

    hole_cards = parseHand(game_state["players"][in_action]["hole_cards"]);

    std::cerr << "XXXXXXXXXX Our hand is = " << hole_cards << std::endl;

    switch (game_state["community_cards"].ToArray().size()) {
        default:
        case 0:
            return preFlop(game_state);
        case 3:
            return flop(game_state);
        case 4:
            return turn(game_state);
        case 5:
            return river(game_state);
    }

}

void Player::showdown(json::Value game_state)
{
}
