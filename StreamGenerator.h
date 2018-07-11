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

    int streamSize;
    dynamic_bitset<> *defaultBitStream;
    vector<int> random_int_final_states;
    vector<int> random_int_nfa;
    unsigned int seed;
    std::default_random_engine generator;


public:


    int getStreamSize() const;

    void setStreamSize(int streamSize);

    const vector<int> &getRandom_int_final_states() const;

    const vector<int> &getRandom_int_nfa() const;

    StreamGenerator(int streamSize, dynamic_bitset<> *defaultBitStream); //param constructor

    StreamGenerator(const StreamGenerator &orig);

    StreamGenerator();

//option 1, using a method with no return type to fill the string vector that contains the bit representation of the generated random number in each position
    dynamic_bitset<> generateBitStream(int size, int generator_flag);

    void setBitstreamBits(dynamic_bitset<> &bitStream, int num, size_t bitsetIndex, size_t numIndex);

    dynamic_bitset<> *getDefaultBitStream() const;

    void setDefaultBitStream(dynamic_bitset<> *defaultBitStream);


};

#endif	/* UNIFORMRANDOMNFAGENERATOR_H */

