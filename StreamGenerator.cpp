/*
 * File:   StreamGenerator.cpp
 * Author: Carlos David
 *
 * Created on March 6, 2013, 12:15 AM
 */

#include "StreamGenerator.h"
#include <chrono>

using namespace std;

StreamGenerator::StreamGenerator(int size, dynamic_bitset<> defaultBitStream) {
    this->streamSize = size;
    this->defaultBitStream = defaultBitStream;
}

StreamGenerator::StreamGenerator() {
    this->streamSize = 0;
    this->defaultBitStream = dynamic_bitset<>(streamSize);
}


dynamic_bitset<> StreamGenerator::generateBitStream(int size) {

    dynamic_bitset<> randomBitStream(size);

    //As size of an integer is implementation dependant on C++
    //Using sizeof(int)*8 will give the exact number of bits of an integer
    //depending on the platform in which the program is running. 
    unsigned int sizeOfInteger = sizeof (int)*8;
    unsigned int iterations = (ceil(size / sizeOfInteger));
    unsigned int startIndex = 0;


    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<unsigned int> distribution(0, UINT_MAX);


    for (int i = 0; i <= iterations; i++) {
        unsigned int tempRandomInt = distribution(generator);
        setBitstreamBits(randomBitStream, tempRandomInt, startIndex, 0);
        startIndex = startIndex + sizeOfInteger;
    }

    return randomBitStream;

}

void StreamGenerator::setBitstreamBits(dynamic_bitset<>& bitStream,
                                       int num, size_t bitsetIndex, size_t numIndex) {

    unsigned int size = sizeof (unsigned int)*8;
    if (numIndex < size) {

        if (bitsetIndex < bitStream.size()) {
            bitStream[bitsetIndex] = (num >> numIndex) & 0x1;
            setBitstreamBits(bitStream, num, bitsetIndex + 1, numIndex + 1);
        }
    }


}


const dynamic_bitset<> &StreamGenerator::getDefaultBitStream() const {
    return defaultBitStream;
}

void StreamGenerator::setDefaultBitStream(const dynamic_bitset<> &defaultBitStream) {
    StreamGenerator::defaultBitStream = defaultBitStream;
}

int StreamGenerator::getStreamSize() const {
    return streamSize;
}