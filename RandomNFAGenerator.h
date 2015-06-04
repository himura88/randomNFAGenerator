//
// Created by Carlos David on 5/18/15.
//

#ifndef UNIFORMRANDOMNFAGENERATOR_RANDOMNFAGENERATOR_H
#define UNIFORMRANDOMNFAGENERATOR_RANDOMNFAGENERATOR_H


#include <boost/dynamic_bitset/dynamic_bitset.hpp>
#include "StreamGenerator.h"

class RandomNFAGenerator
{


public:
    RandomNFAGenerator(StreamGenerator *generator, unsigned int alphabet, unsigned int states);

    RandomNFAGenerator();

    RandomNFAGenerator(const RandomNFAGenerator &orig);

    virtual ~RandomNFAGenerator();


private:

    vector<boost::dynamic_bitset<>> generated_NFAs;
    vector<boost::dynamic_bitset<>> generated_NFAs_final_states;
    StreamGenerator *generator;
    unsigned int alphabet;
    unsigned int states;
    unsigned int number_of_NFAs;

public:


    const vector<dynamic_bitset<>> &getGenerated_NFAs() const;

    void setGenerated_NFAs(const vector<dynamic_bitset<>> &generated_NFAs);

    const vector<dynamic_bitset<>> &getGenerated_NFAs_final_states() const;

    void setGenerated_NFAs_final_states(
            const vector<dynamic_bitset<>> &generated_NFAs_final_states);

    void setGenerator(StreamGenerator *generator);

    unsigned int getStates() const;

    unsigned int getNumber_of_NFAs() const;

    void setNumber_of_NFAs(unsigned int number_of_NFAs);

    void setStates(unsigned int states);

    unsigned int getAlphabet() const;

    void setAlphabet(unsigned int alphabet);

    StreamGenerator *getGenerator() const;

    std::vector<boost::dynamic_bitset<>> &generateUniformRandomNFAs(unsigned sizeOfAlphabet, unsigned numberOfStates,
                                                                    unsigned numberOfNFAs);

    std::vector<boost::dynamic_bitset<>> &generateUniformRandomNFAs();


};


#endif //UNIFORMRANDOMNFAGENERATOR_RANDOMNFAGENERATOR_H
