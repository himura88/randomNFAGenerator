#include <iostream>
#include <sstream>
#include "StreamGenerator.h"
#include "RandomNFAGenerator.h"

using namespace std;

int main(int argc, char *argv[])
{

    RandomNFAGenerator *automata_generator;
    automata_generator = new RandomNFAGenerator();

    unsigned alphabet, states, numberOfNFAs;

    std::istringstream sigma(argv[1]);
    std::istringstream numStates(argv[2]);
    std::istringstream numNFAs(argv[3]);

    sigma >> alphabet;
    numStates >> states;
    numNFAs >> numberOfNFAs;

    automata_generator->setAlphabet(alphabet);
    automata_generator->setStates(states);
    automata_generator->setNumber_of_NFAs(numberOfNFAs);
    automata_generator->generateUniformRandomNFAs();

    automata_generator->write_generated_NFAs(automata_generator->getGenerated_NFAs());

    return 0;
}