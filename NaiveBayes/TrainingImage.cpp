//
//  NaiveBayes.cpp
//  NaiveBayes
//
//  Created by Avinda De Silva on 10/22/18.
//  Copyright © 2018 Avinda De Silva. All rights reserved.
//

#include "TrainingImage.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <map>
#include <math.h>

const uint32_t kImageHeight = 28;
const uint32_t kImageWidth = 29;
const uint32_t kTrainingLabels = 5000;
const uint32_t kAllDigits = 10;
const uint32_t kLaPlace = 1.1;



std::vector<std::vector <int> > Image::getImage(std::ifstream &file)
{
    std::vector< std::vector<int> >   imagePixels;
    char pixel;
    if(!file) {
        std::cout << "File failed to open";
    }
    
    for (uint32_t i = 0; i < kImageHeight; i++) {
        std::vector<int> row;
        for (uint32_t j = 0; j < kImageWidth; j++) {
            file.get(pixel);
            if(pixel == '#' || pixel == '+') {
                row.push_back(1);
            } else {
                row.push_back(0);
            }
        }
        imagePixels.push_back(row);
    }
    return imagePixels;
}

int Image::getLabel(std::ifstream &file) {
    std::string label;
    int value;
    if(!file) {
        std::cout << "File failed to open";
    }
    std::getline(file, label);
    value = atoi(label.c_str());
    return value;
}

std::multimap<int, std::vector<std::vector <int> > > getResults(Image &p, std::string images, int fileSize) {
    std::ifstream imageFile(images);
    std::ifstream labelFile;
    if (images == "trainingimages") {
        labelFile.open("traininglabels");
    }
    std::multimap<int, std::vector<std::vector <int> > > testImages;
    for(uint32_t i = 0; i < fileSize; i++) {
        int label;
        if(labelFile.is_open()) {
            label = p.getLabel(labelFile);
        } else {
            label = 0;
        }
        std::vector< std::vector<int> >   imagePixels = p.getImage(imageFile);
        testImages.insert(std::make_pair(label, imagePixels));
    }
    labelFile.close();
    imageFile.close();
    return testImages;
}

double Image::probabilityOfClass(int num) {
    Image image;
    auto testImages = getResults(image, "trainingimages", kTrainingLabels);
    double quotient = (double) testImages.count(num) / testImages.size();
    return quotient;
}

double Image::getProbabilityOfFeature(std::string fileName, int feature) {
    std::ofstream trainingModel;
    trainingModel.open(fileName);
    Image image;
    std::vector< std::vector<double> >   probabilityPixels;
    auto testImages = getResults(image, "trainingimages", kTrainingLabels);
    for (int num = 0; num < kAllDigits; num++) {
        for (int i = 0; i < kImageHeight; i++) {
            std::vector<double> row;
            for (int j = 0; j < 28; j++) {
                int featureCounter = 0;
                for (auto it = testImages.begin(); it != testImages.end(); it++) {
                    if(it->first == num && it->second[i][j] == feature) {
                        featureCounter++;
                    }
                }
                double probability = (double) (kLaPlace + featureCounter) / (2 * kLaPlace + testImages.count(num));
                double nearest = (roundf(probability * 1000) / 1000);
                trainingModel << nearest << " ";
                row.push_back(featureCounter / testImages.count(num));
            }
            trainingModel << "\n";
        }
    }
    trainingModel.close();
    return 0.0;
}



