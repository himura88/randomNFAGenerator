#include <iostream>
#include <sstream>
#include "StreamGenerator.h"
#include "RandomNFAGenerator.h"

using namespace std;

int main(int argc, char *argv[])
{

    RandomNFAGenerator *automataGenerator;
    automataGenerator = new RandomNFAGenerator();

    unsigned alphabet, states, numberOfNFAs;

    std::istringstream sigma(argv[1]);
    std::istringstream numStates(argv[2]);
    std::istringstream numNFAs(argv[3]);

    sigma >> alphabet;
    numStates >> states;
    numNFAs >> numberOfNFAs;

    automataGenerator->setAlphabet(alphabet);
    automataGenerator->setStates(states);
    automataGenerator->setNumberOfNFAs(numberOfNFAs);
    automataGenerator->generateUniformRandomNFAs();

    return 0;
}