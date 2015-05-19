#include <iostream>
#include "StreamGenerator.h"
#include "RandomNFAGenerator.h"

using namespace std;

int main() {


    StreamGenerator * myStream;
    RandomNFAGenerator * automataGenerator;
    automataGenerator = new RandomNFAGenerator();

    automataGenerator->generateUniformRandomNFAs(3,9,10000);
    myStream = new StreamGenerator();

    StreamGenerator * soo;
    soo = new StreamGenerator(502);
    dynamic_bitset<> randomStream = soo->generateBitStream();
    //std::cout << "randomStream:  " << randomStream << std::endl;
    dynamic_bitset<> foo = myStream->generateBitStream((256));
    //std::cout << "foo:  " << foo << std::endl;
    return 0;
}