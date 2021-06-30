//
//  TrainingMain.cpp
//  TrainingModel
//
//  Created by Avinda De Silva on 10/24/18.
//  Copyright © 2018 Avinda De Silva. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <map>
#include "TrainingImage.hpp"
#include <stdio.h>
#include "Training.hpp"


int main() {
    Image testImages;
    testImages.getProbabilityOfFeature("trainingModelForeground.txt", 1);
    return 0;
}
