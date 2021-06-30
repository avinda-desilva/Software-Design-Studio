//
//  main.cpp
//  NaiveBayes
//
//  Created by Avinda De Silva on 10/22/18.
//  Copyright © 2018 Avinda De Silva. All rights reserved.
//
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <map>
#include "TrainingImage.hpp"
#include "TrainingImage.hpp"
#include "Training.hpp"
#include <math.h>
#include <algorithm>

const uint32_t kImageHeight = 28;
const uint32_t kImageWidth = 28;

int predictedClass() {
    std::ofstream predictedClass;
    predictedClass.open("predictedLabels.txt");
    Image testImages;
    auto imageMap = getResults(testImages, "testimages", 1000);
    auto probabilityMap = saveModel();
        std::vector<double> probabilities;
    for (auto imageIterate = imageMap.begin(); imageIterate != imageMap.end(); imageIterate++) {
        for (auto probIterate = probabilityMap.begin(); probIterate != probabilityMap.end(); probIterate++) {
            double probOfClass = testImages.probabilityOfClass(probIterate->first);
            double product = 0;
            for (int i = 0; i < kImageHeight; i++) {
                for (int j = 0; j < kImageWidth; j++) {
                    if (imageIterate->second[i][j] == 1) {
                        std::cout << probIterate->second[i][j];
                        product+= log(probIterate->second[i][j]);
                    } else {
                        product+= log((1 - (probIterate->second[i][j])));
                    }
                    product+= log(probOfClass);
                }
            }
            probabilities.push_back(product);
            predictedClass << std::fixed << product << "||";

        }
        predictedClass << std::endl;
}
    predictedClass.close();
    return 0;
}

int main() {
    predictedClass();
}
