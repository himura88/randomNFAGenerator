//
// Created by Carlos David on 5/18/15.
//

#include <fstream>
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


std::vector<boost::dynamic_bitset<>> &RandomNFAGenerator::generateUniformRandomNFAs(unsigned sizeOfAlphabet,
                                                                                    unsigned numberOfStates,
                                                                                    unsigned numberOfNFAs)
{

    unsigned transitionTableSize = sizeOfAlphabet * (numberOfStates * numberOfStates);
    for (int i = 0; i <= numberOfNFAs; i++)
    {
        dynamic_bitset<> currentNFA = generator->generateBitStream(transitionTableSize);
        dynamic_bitset<> finalStates = generator->generateBitStream(transitionTableSize);//change this to use the number of states

        this->generated_NFAs.push_back(currentNFA);
        this->generated_NFAs_final_states.push_back(finalStates);


       std::cout << i << "-currentNFA:" << currentNFA << std::endl;
    }
    return generated_NFAs;
}


std::vector<boost::dynamic_bitset<>> &RandomNFAGenerator::generateUniformRandomNFAs()
{
    return this->generateUniformRandomNFAs(this->alphabet, this->states, this->number_of_NFAs);
}

const vector<dynamic_bitset<>> &RandomNFAGenerator::getGenerated_NFAs() const
{
    return generated_NFAs;
}

void RandomNFAGenerator::setGenerated_NFAs(const vector<dynamic_bitset<>> &generated_NFAs)
{
    RandomNFAGenerator::generated_NFAs = generated_NFAs;
}

const vector<dynamic_bitset<>> &RandomNFAGenerator::getGenerated_NFAs_final_states() const
{
    return generated_NFAs_final_states;
}

void RandomNFAGenerator::setGenerated_NFAs_final_states(
        const vector<dynamic_bitset<>> &generated_NFAs_final_states)
{
    RandomNFAGenerator::generated_NFAs_final_states = generated_NFAs_final_states;
}

void RandomNFAGenerator::setGenerator(StreamGenerator *generator)
{
    RandomNFAGenerator::generator = generator;
}

unsigned int RandomNFAGenerator::getStates() const
{
    return states;
}

unsigned int RandomNFAGenerator::getNumber_of_NFAs() const
{
    return number_of_NFAs;
}

void RandomNFAGenerator::setNumber_of_NFAs(unsigned int number_of_NFAs)
{
    RandomNFAGenerator::number_of_NFAs = number_of_NFAs;
}

void RandomNFAGenerator::setStates(unsigned int states)
{
    RandomNFAGenerator::states = states;
}

unsigned int RandomNFAGenerator::getAlphabet() const
{
    return alphabet;
}

void RandomNFAGenerator::setAlphabet(unsigned int alphabet)
{
    RandomNFAGenerator::alphabet = alphabet;
}

StreamGenerator *RandomNFAGenerator::getGenerator() const
{
    return generator;
}

void RandomNFAGenerator::writeNFA()
{
    ofstream myfile ("example.txt");
    if (myfile.is_open())
    {
        myfile << "This is a line.\n";
        myfile << "This is another line.\n";
        myfile.close();
    }
    else cout << "Unable to open file";

}
