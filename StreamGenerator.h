/* 
 * File:   StreamGenerator.h
 * Author: Carlos David
 *
 * Created on March 6, 2013, 12:15 AM
 */

#ifndef UNIFORMRANDOMNFAGENERATOR_H
#define    UNIFORMRANDOMNFAGENERATOR_H

#include <climits>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <bitset>
#include <iostream>
#include <vector>
#include <random>
#include <boost/dynamic_bitset.hpp>//To make this include work, Boost library has to be installed on the target SO


using namespace std;
using namespace boost;

class StreamGenerator
{

private:

    unsigned long streamSize;
    vector<unsigned long> random_int_final_states;
    vector<unsigned long> random_int_nfa;
    unsigned long seed;
    std::default_random_engine generator;
    std::uniform_int_distribution<unsigned int> distribution{0, UINT_MAX};

public:


    vector<unsigned long> getRandom_int_final_states() const;

    vector<unsigned long> getRandom_int_nfa() const;

    StreamGenerator(const StreamGenerator &orig);

    StreamGenerator();

//option 1, using a method with no return type to fill the string vector that contains the bit representation of the generated random number in each position
    dynamic_bitset<> generateBitStream(unsigned long size, int generator_flag);

    void setBitstreamBits(dynamic_bitset<> &bitStream, unsigned int num, size_t bitsetIndex, size_t numIndex);


};

#endif	/* UNIFORMRANDOMNFAGENERATOR_H */

