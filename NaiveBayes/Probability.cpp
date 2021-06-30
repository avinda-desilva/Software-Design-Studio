//
//  Probability.cpp
//  NaiveBayes
//
//  Created by Avinda De Silva on 10/24/18.
//  Copyright © 2018 Avinda De Silva. All rights reserved.
//

#include "Probability.hpp"
#include "TrainingImage.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <map>

const uint32_t kImageHeight = 28;
const uint32_t kImageWidth = 29;
const uint32_t kTrainingLabels = 5000;
const uint32_t kAllDigits = 9;


