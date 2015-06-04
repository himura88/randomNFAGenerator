//
// Created by Carlos David on 5/18/15.
//

#include "RandomNFAGenerator.h"

RandomNFAGenerator::RandomNFAGenerator()
{
    this->generator = new StreamGenerator();
}

RandomNFAGenerator::RandomNFAGenerator(const RandomNFAGenerator &orig)
{
}

RandomNFAGenerator::~RandomNFAGenerator()
{
}


void RandomNFAGenerator::setGenerator(StreamGenerator *generator)
{
    RandomNFAGenerator::generator = generator;
}


std::vector<boost::dynamic_bitset<>> &RandomNFAGenerator::generateUniformRandomNFAs(unsigned sizeOfAlphabet,
                                                                                    unsigned numberOfStates,
                                                                                    unsigned numberOfNFAs)
{

    unsigned transitionTableSize = sizeOfAlphabet * (numberOfStates * numberOfStates);
    for (int i = 0; i <= numberOfNFAs; i++)
    {
        dynamic_bitset<> currentNFA = generator->generateBitStream(transitionTableSize);
        dynamic_bitset<> finalStates = generator->generateBitStream(transitionTableSize);

        this->generated_NFAs.push_back(currentNFA);
        this->generated_NFAs_final_states.push_back(finalStates);

        //std::cout << "currentNFA:" << currentNFA << std::endl;
        // generated_NFAs.push_back(push_backcurrentNFA);

        //std::cout << i << "-currentNFA:" << currentNFA << std::endl;
    }
    return generated_NFAs;
}


std::vector<boost::dynamic_bitset<>> &RandomNFAGenerator::generateUniformRandomNFAs()
{
    return this->generateUniformRandomNFAs(this->alphabet, this->states, this->number_of_NFAs);
}

void RandomNFAGenerator::setNumberOfNFAs(unsigned int numberOfNFAs)
{
    RandomNFAGenerator::number_of_NFAs = numberOfNFAs;
}

unsigned int RandomNFAGenerator::getNumberOfNFAs() const
{
    return number_of_NFAs;
}