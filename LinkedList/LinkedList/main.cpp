//
//  main.cpp
//  LinkedList
//
//  Created by Avinda De Silva on 10/27/18.
//  Copyright © 2018 Avinda De Silva. All rights reserved.
//
#include "ll.h"
#include <iostream>

using namespace cs126LinkedList;
/*
int oldmain(int argc, const char * argv[]) {
    // insert code here...
    std::vector<std::string> numbers = {"wow", "2", "3", "4", "5ive", "6ix9ine"};
    LinkedList<std::string> test(numbers);
    printList(test);
    LinkedList<std::string> newList = test;
    printList(newList);
    //newList.clear();
    //printList(newList);
    //std::cout << test.back();
    newList.clear();
    printList(newList);
    return 0;
}
 */

int oldmain(int argc, const char * argv[]) {
    /*
    std::vector<std::string> listOfStrings = {"wow", "2", "3", "4", "5ive", "lit"};
    LinkedList<std::string> test(listOfStrings);
    std::cout << test;
    std::cout << "------------" << std::endl;
    LinkedList<std::string> newList = test;
    newList.push_back("eskeddit!!!!");
    std::cout << test;
    std::cout << "------------" << std::endl;
    std::cout << newList;
    std::cout << "------------" << std::endl;
    test.clear();
     */
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<int> diffNumbers = {1, 2, 3, 4, 6};
    LinkedList<int> numberList(numbers);
    //std::cout << numberList;
    LinkedList<int> comparedList(diffNumbers);
    std::cout << (numberList ==(comparedList)) << std::endl;
    std::cout << (numberList !=(comparedList)) << std::endl;
    //std::cout << numberList.size();
    //std::cout << comparedList.size();
    const auto it = numberList.begin();
    auto lt = comparedList.begin();
    std::cout << *lt << std::endl;
    std::cout << *lt << std::endl;
    std::cout << (lt != it);
    return 0;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    LinkedList<int> numberList(numbers);
    std::cout << numberList;
    numberList.~LinkedList();
    std::cout << numberList;
}
