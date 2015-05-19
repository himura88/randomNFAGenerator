//
// Created by Carlos David on 5/18/15.
//

#include "RandomNFAGenerator.h"
RandomNFAGenerator::RandomNFAGenerator() {
    this->generator = new StreamGenerator();
}

RandomNFAGenerator::RandomNFAGenerator(const RandomNFAGenerator& orig) {
}

RandomNFAGenerator::~RandomNFAGenerator() {
}


void RandomNFAGenerator::setFinalStates(const dynamic_bitset<> &finalStates) {
    RandomNFAGenerator::finalStates = finalStates;
}

const dynamic_bitset<> &RandomNFAGenerator::getFinalStates() const {
    return finalStates;
}



void RandomNFAGenerator::setGenerator(StreamGenerator *generator) {
    RandomNFAGenerator::generator = generator;
}


void RandomNFAGenerator::setInitialStates(const dynamic_bitset<> &initialStates) {
    RandomNFAGenerator::initialStates = initialStates;
}

std::vector<boost::dynamic_bitset<>> &RandomNFAGenerator::generateUniformRandomNFAs(unsigned sizeOfAlphabet,
                                                                                    unsigned numberOfStates,
                                                                                    unsigned numberOfNFAs)
{

    unsigned transitionTableSize = sizeOfAlphabet*(numberOfStates*numberOfStates);
    for (int i = 0; i <= numberOfNFAs; i++)
    {
        dynamic_bitset<> currentNFA = generator->generateBitStream(transitionTableSize);
        this->nfaTransitionTables.push_back(currentNFA);
        //std::cout << "currentNFA:" << currentNFA << std::endl;
       // nfaTransitionTables.push_back(push_backcurrentNFA);

        std::cout << i << "-currentNFA:" << currentNFA << std::endl;
    }
    return nfaTransitionTables;
}
