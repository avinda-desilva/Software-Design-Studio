//
//  main.cpp
//  ProjectTests
//
//  Created by Avinda De Silva on 12/12/18.
//

#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "Player.hpp"

std::vector<int> numbers = {1, 2, 3, 4, 5};
std::vector<int> diffNumbers = {1, 2, 3, 4, 6};


TEST_CASE("Checks if default radius is correct") {
    std::ostringstream printedList;
    Player testPlayer = Player(0, 0);
    REQUIRE(testPlayer.getScore() == 100);
}
