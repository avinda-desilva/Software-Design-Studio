//
//  Training.cpp
//  TrainingModel
//
//  Created by Avinda De Silva on 10/24/18.
//  Copyright © 2018 Avinda De Silva. All rights reserved.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <map>
#include "TrainingImage.hpp"
#include <stdio.h>
#include "Training.hpp"
#include <math.h>

const uint32_t kImageHeight = 28;
const uint32_t kImageWidth = 28;
const uint32_t kAllDigits = 10;


std::vector<std::vector <double> > getProbabilityImage(std::ifstream &file) {
    std::vector< std::vector<double> >   imagePixels;
    double pixel;
    while(file.good()) {
    for (uint32_t i = 0; i < kImageHeight; i++) {
        std::vector<double> row;
        for (uint32_t j = 0; j < kImageWidth; j++) {
            file >> std::fixed >> pixel;
            row.push_back(pixel);
        }
        imagePixels.push_back(row);
    }
    }
    return imagePixels;
}

std::multimap<int, std::vector<std::vector <double> > > saveModel() {
    std::ifstream trainingFile("trainingModelForeground.txt");
    std::multimap<int, std::vector<std::vector <double> > > probabilityMap;
    double pixel;
    while(trainingFile.good()) {
        if (probabilityMap.size() == 10) {break;}
        for (uint32_t num = 0; num < kAllDigits; num++) {
            std::vector< std::vector<double> >   imagePixels;
        for (uint32_t i = 0; i < kImageHeight; i++) {
            std::vector<double> row;
            for (uint32_t j = 0; j < kImageWidth; j++) {
                trainingFile >> std::fixed >> pixel;
                row.push_back(pixel - 0.001);
            }
            imagePixels.push_back(row);
        }
            probabilityMap.insert(std::make_pair(num, imagePixels));
    }
    }
    return probabilityMap;
}
