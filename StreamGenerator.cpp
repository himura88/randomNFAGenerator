/*
 * File:   StreamGenerator.cpp
 * Author: Carlos David
 *
 * Created on March 6, 2013, 12:15 AM
 */

#include "StreamGenerator.h"
#include <chrono>
#include <fstream>

#define LINE_BREAK "\n"
using namespace std;

StreamGenerator::StreamGenerator(int size, dynamic_bitset<> *defaultBitStream)
{
    this->streamSize = size;
    this->defaultBitStream = defaultBitStream;
}

StreamGenerator::StreamGenerator()
{
    this->streamSize = 0;
    this->defaultBitStream = new dynamic_bitset<>(streamSize);
    this->seed = std::chrono::system_clock::now().time_since_epoch().count();
    this->generator.seed(this ->seed);
}

dynamic_bitset<> StreamGenerator::generateBitStream(int size, int generator_flag)
{
// generator_flag = 1 -> generating nfa; generator_flag = 2 -> generating final states
    dynamic_bitset<> randomBitStream(size);

    //As size of an integer is implementation dependant on C++
    //Using sizeof(int)*8 will give the exact number of bits of an integer
    //depending on the platform in which the program is running. 
    unsigned int sizeOfInteger = sizeof(int) * 8;
    unsigned int iterations = (ceil(size / sizeOfInteger));
    unsigned int startIndex = 0;

   // std::default_random_engine generator(seed);

    std::uniform_int_distribution<unsigned int> distribution(0, UINT_MAX);



    for (int i = 0; i <= iterations; i++)
    {

        unsigned int tempRandomInt = distribution(generator);
        if (generator_flag == 0)
        {
            random_int_final_states.push_back(tempRandomInt);
        }
        else
        {
            random_int_nfa.push_back(tempRandomInt);
        }

        setBitstreamBits(randomBitStream, tempRandomInt, startIndex, 0);
        startIndex = startIndex + sizeOfInteger;
    }

    return randomBitStream;

}

void StreamGenerator::setBitstreamBits(dynamic_bitset<> &bitStream, int num, size_t bitsetIndex, size_t numIndex)
{

    unsigned int size = sizeof(unsigned int) * 8;
    if (numIndex < size)
    {

        if (bitsetIndex < bitStream.size())
        {
            bitStream[bitsetIndex] = (num >> numIndex) & 0x1;
            setBitstreamBits(bitStream, num, bitsetIndex + 1, numIndex + 1);
        }
    }


}


int StreamGenerator::getStreamSize() const
{
    return streamSize;
}

dynamic_bitset<> *StreamGenerator::getDefaultBitStream() const
{
    return defaultBitStream;
}

void StreamGenerator::setDefaultBitStream(dynamic_bitset<> *defaultBitStream)
{
    StreamGenerator::defaultBitStream = defaultBitStream;
}

void StreamGenerator::setStreamSize(int streamSize)
{
    StreamGenerator::streamSize = streamSize;
}

const vector<int> &StreamGenerator::getRandom_int_final_states() const
{
    return random_int_final_states;
}

const vector<int> &StreamGenerator::getRandom_int_nfa() const
{
    return random_int_nfa;
}
