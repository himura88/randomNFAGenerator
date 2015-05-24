#include <iostream>
#include <sstream>
#include "StreamGenerator.h"
#include "RandomNFAGenerator.h"

using namespace std;

int main(int argc, char *argv[])
{


    StreamGenerator *myStream;
    RandomNFAGenerator *automataGenerator;
    automataGenerator = new RandomNFAGenerator();

    unsigned alphabet, states, numberOfNFAs;

    std::istringstream sigma(argv[1]);
    std::istringstream numStates(argv[2]);
    std::istringstream numNFAs(argv[3]);

    sigma >> alphabet;
    numStates >> states;
    numNFAs >> numberOfNFAs;

    automataGenerator->generateUniformRandomNFAs(alphabet, states, numberOfNFAs);
    myStream = new StreamGenerator();

    //StreamGenerator *soo;
    //soo = new StreamGenerator(502);
   // dynamic_bitset<> randomStream = soo->generateBitStream();
    //std::cout << "randomStream:  " << randomStream << std::endl;
   // dynamic_bitset<> foo = myStream->generateBitStream((256));
    //std::cout << "foo:  " << foo << std::endl;
    return 0;
}