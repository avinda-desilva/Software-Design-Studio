//
//  main.cpp
//  CatchTesting
//
//  Created by Avinda De Silva on 10/30/18.
//  Copyright © 2018 Avinda De Silva. All rights reserved.
//
#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "ll.h"

using namespace cs126LinkedList;
std::vector<int> numbers = {1, 2, 3, 4, 5};
std::vector<int> diffNumbers = {1, 2, 3, 4, 6};
LinkedList<int> numberList(numbers);
LinkedList<int> comparedList(diffNumbers);

TEST_CASE("Checks if list is printed correctly") {
    std::ostringstream printedList;
    printedList << numberList;
    REQUIRE(printedList.str() == "1 2 3 4 5 ");
}

TEST_CASE("Checks if copy assignment is correct") {
    comparedList = numberList;
    comparedList.push_back(3);
    std::ostringstream printedList;
    printedList << numberList;
    REQUIRE(printedList.str() == "1 2 3 4 5 ");
    std::ostringstream printOtherList;
    printOtherList << comparedList;
    REQUIRE(printOtherList.str() == "1 2 3 4 5 3 ");
}

TEST_CASE("Checks if move assignment is correct") {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    LinkedList<int> numberList(numbers);
    LinkedList<int> comparedList;
    comparedList = std::move(numberList);
    std::ostringstream printedList;
    printedList << numberList;
    std::ostringstream printOtherList;
    printOtherList << comparedList;
    REQUIRE(printedList.str() == "this is an empty list");
    REQUIRE(printOtherList.str() == "1 2 3 4 5 ");
}

TEST_CASE("Checks if copy constructor works correctly") {
    LinkedList<int> comparedList(numberList);
    std::ostringstream printedList;
    printedList << comparedList;
    REQUIRE(printedList.str() == "1 2 3 4 5 ");
}

TEST_CASE("Checks if move constructor works correctly") {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    LinkedList<int> numberList(numbers);
    LinkedList<int> comparedList(std::move(numberList));
    std::ostringstream printedList;
    printedList << numberList;
    std::ostringstream printOtherList;
    printOtherList << comparedList;
    REQUIRE(printedList.str() == "this is an empty list");
    REQUIRE(printOtherList.str() == "1 2 3 4 5 ");
}


TEST_CASE("Checks if push front works") {
    LinkedList<int> testList = numberList;
    testList.push_front(3);
    std::ostringstream printList;
    printList << testList;
    REQUIRE(printList.str() == "3 1 2 3 4 5 ");
}

TEST_CASE("Checks if push back works") {
    LinkedList<int> testList = numberList;
    testList.push_back(3);
    std::ostringstream printList;
    printList << testList;
    REQUIRE(printList.str() == "1 2 3 4 5 3 ");
}

TEST_CASE("Checks if front and back functions returns the correct element and if size returns num of elements") {
    SECTION("Checks front()") {
        REQUIRE(numberList.front() == 1);
    }
    SECTION("Checks back()") {
        REQUIRE(numberList.back() == 5);
    }
    SECTION("Checks size()") {
        REQUIRE(numberList.size() == 5);
    }
}

TEST_CASE("Checks if pop front works and correct element is deleted") {
    LinkedList<int> testList = numberList;
    testList.pop_front();
    std::ostringstream printList;
    printList << testList;
    REQUIRE(printList.str() == "2 3 4 5 ");
}

TEST_CASE("Checks if pop back works and correct element is deleted") {
    LinkedList<int> testList = numberList;
    testList.pop_back();
    std::ostringstream printList;
    printList << testList;
    REQUIRE(printList.str() == "1 2 3 4 ");
}

TEST_CASE("Checks if the empty function correctly identifies list") {
    SECTION("Non-Empty List") {
        REQUIRE(numberList.empty() == false);
    }
    SECTION("Empty List") {
        LinkedList<std::string> emptyList;
        REQUIRE(emptyList.empty() == true);
    }
}

TEST_CASE("Makes sure that list is actually cleared when clear function is called") {
    LinkedList<int> duplicate = numberList;
    duplicate.clear();
    REQUIRE(duplicate.empty() == true);
}

TEST_CASE("Checking to see if correct element is removed when using removeNth()") {
    LinkedList<int> duplicate = numberList;
    duplicate.RemoveNth(2);
    std::ostringstream printList;
    printList << duplicate;
    REQUIRE(printList.str() == "1 2 4 5 ");
}

TEST_CASE("Checking to see if two lists are equal") {
    std::vector<int> newNumbers = {1, 2, 3, 4, 5};
    LinkedList<int> comparedList(newNumbers);
    bool answer = numberList == comparedList;
    REQUIRE(answer == true);
}

TEST_CASE("Checks to see if two lists are not equal") {
    std::vector<int> diffNumbers = {1, 2, 3, 4, 6};
    LinkedList<int> comparedList(diffNumbers);
    bool answer = numberList != comparedList;
    REQUIRE(answer == true);
}

TEST_CASE("Different element types") {
    SECTION("Elements of type string") {
        std::vector<std::string> greetings = {"hello", "hi", "sup", "saaah", "yo"};
        LinkedList<std::string> greetingList(greetings);
        std::ostringstream printList;
        printList << greetingList;
        REQUIRE(printList.str() == "hello hi sup saaah yo ");
        greetingList.RemoveNth(4);
        printList.str("");
        printList << greetingList;
        REQUIRE(printList.str() == "hello hi sup saaah ");
    }
    SECTION("Elements of type boolean") {
        std::vector<bool> booleans = {false, true, true, true};
        LinkedList<bool> booleanList(booleans);
        std::ostringstream printList;
        printList << booleanList;
        REQUIRE(printList.str() == "0 1 1 1 ");
    }
}

TEST_CASE("Checking if iterator can iterate through linkedList") {
    std::ostringstream printList;
    auto it = numberList.begin();
    while (it != numberList.end()) {
        printList << *it << " ";
        ++it;
    }
    REQUIRE(printList.str() == "1 2 3 4 5 ");
}

TEST_CASE("Putting multiple functions together and see if it list stays intact") {
    LinkedList<int> duplicate = numberList;
    LinkedList<int> movedList(std::move(duplicate));
    movedList.push_front(8);
    movedList.push_back(2);
    movedList.RemoveNth(3);
    movedList.pop_back();
    std::ostringstream printList;
    printList << movedList;
    REQUIRE(printList.str() == "8 1 2 4 5 ");
    printList.str("");
    printList << duplicate;
    REQUIRE(printList.str() == "this is an empty list");
}

TEST_CASE("New Test") {
    LinkedList<int> testList;
    testList.clear();
    testList.push_back(1);
    std::ostringstream printList;
    printList << testList;
    REQUIRE(printList.str() == "1 ");
}




