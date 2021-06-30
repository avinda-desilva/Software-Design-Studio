//
//  NaiveBayes.hpp
//  NaiveBayes
//
//  Created by Avinda De Silva on 10/22/18.
//  Copyright © 2018 Avinda De Silva. All rights reserved.
//

#ifndef TrainingImage_hpp
#define TrainingImage_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <map>
#include <fstream>

class Image{
public:
    std::string fileName;
    Image() {
        fileName = "trainingImages";
    }
    /*
     * Creates a 2d vector that stores the image pixels as 1 or 0. Takes images from
     * trainingimages file
     */
    std::vector<std::vector <int> > getImage(std::ifstream &file);
    /*
     * Gets the label from the traininglabel file
     */
    int getLabel(std::ifstream &file);
    double probabilityOfClass(int num);
    /*
     * Creates the file of all the probabilites of each class from the trainingimages
     */
    double getProbabilityOfFeature(std::string fileName, int feature);
};

/*
 * Creates a map of all training labels (key) and maps them to the 2d image pixel vector (value)
 */
std::multimap<int, std::vector<std::vector <int> > > getResults(Image &p, std::string images, int fileSize);
#endif /* NaiveBayes_hpp */

