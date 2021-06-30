//
//  Training.hpp
//  TrainingModel
//
//  Created by Avinda De Silva on 10/24/18.
//  Copyright © 2018 Avinda De Silva. All rights reserved.
//

#ifndef Training_hpp
#define Training_hpp

/*
 * Creates a map of all the image pixel probabilities from the saved file (value) to the class (key)
 */
std::multimap<int, std::vector<std::vector <double> > > saveModel();

/*
 * Creates a 2d vector that contains the probability pixels of a class.
 */
std::vector<std::vector <double> > getProbabilityImage(std::ifstream &file);

#endif /* Training_hpp */
