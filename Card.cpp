#include <iostream>
#include "Card.h"

Card::Card(json::Value value) {
    auto rank_string = value["rank"].ToString();
    auto suit_string = value["suit"].ToString();

    if (rank_string == "2") { rank = 2; }
    else if (rank_string == "3") { rank = 3; }
    else if (rank_string == "4") { rank = 4; }
    else if (rank_string == "5") { rank = 5; }
    else if (rank_string == "6") { rank = 6; }
    else if (rank_string == "7") { rank = 7; }
    else if (rank_string == "8") { rank = 8; }
    else if (rank_string == "9") { rank = 9; }
    else if (rank_string == "10") { rank = 10; }
    else if (rank_string == "J") { rank = JACK; }
    else if (rank_string == "Q") { rank = QUEEN; }
    else if (rank_string == "K") { rank = KING; }
    else if (rank_string == "A") { rank = ACE; }
    else { std::cerr << "Rank parse error " << rank_string << std::endl; }

    if (suit_string == "clubs") { suit = Suit::CLUB; }
    else if (suit_string == "spades") { suit = Suit::SPADE; }
    else if (suit_string == "hearts") { suit = Suit::HEART; }
    else if (suit_string == "diamonds") { suit = Suit::DIAMOND; }
    else { std::cerr << "Suit parse error " << rank_string << std::endl; }
}
