//
//  Testing.cpp
//  LearningC++
//
//  Created by Avinda De Silva on 10/8/18.
//  Copyright © 2018 Avinda De Silva. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include <iostream>
#include <cmath>
#include <array>
#include "Bananas.hpp"
#include "catch.hpp"

TEST_CASE("Sum of Bananas is computed", "[bananas]") {
    REQUIRE(getSumOfBananas(4, 5) == 3);
}
