//
// Created by hassingard on 5/18/15.
//

#ifndef UNIFORMRANDOMNFAGENERATOR_RANDOMNFAGENERATOR_H
#define UNIFORMRANDOMNFAGENERATOR_RANDOMNFAGENERATOR_H


#include <boost/dynamic_bitset/dynamic_bitset.hpp>
#include "StreamGenerator.h"

class RandomNFAGenerator {

    StreamGenerator* generator;
    uint alphabet;
    uint states;
    vector<boost::dynamic_bitset<>>* nfaTransitionTables;

public:

    RandomNFAGenerator();
    RandomNFAGenerator(const RandomNFAGenerator& orig);
    virtual ~RandomNFAGenerator();


};


#endif //UNIFORMRANDOMNFAGENERATOR_RANDOMNFAGENERATOR_H
