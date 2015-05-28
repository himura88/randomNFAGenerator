//
// Created by hassingard on 5/18/15.
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
    dynamic_bitset<> initialStates;
    dynamic_bitset<> finalStates;
    vector<boost::dynamic_bitset<>> nfaTransitionTables;
    StreamGenerator *generator;
    unsigned int alphabet;
    unsigned int states;
    unsigned int numberOfNFAs;


public:
    unsigned int getNumberOfNFAs() const;

    void setNumberOfNFAs(unsigned int numberOfNFAs);

public:
    const dynamic_bitset<> &getInitialStates() const
    {
        return initialStates;
    }

    void setInitialStates(const dynamic_bitset<> &initialStates);

    unsigned int getStates() const
    {
        return states;
    }

    void setStates(unsigned int states)
    {
        RandomNFAGenerator::states = states;
    }

    unsigned int getAlphabet() const
    {
        return alphabet;
    }

    void setAlphabet(unsigned int alphabet)
    {
        RandomNFAGenerator::alphabet = alphabet;
    }

    StreamGenerator *getGenerator() const
    {
        return generator;
    }

    void setGenerator(StreamGenerator *generator);

    vector<dynamic_bitset<>> *getNfaTransitionTables() const;

    void setNfaTransitionTables(vector<dynamic_bitset<>> *nfaTransitionTables);

    const dynamic_bitset<> &getFinalStates() const;

    void setFinalStates(const dynamic_bitset<> &finalStates);

    std::vector<boost::dynamic_bitset<>> &generateUniformRandomNFAs(unsigned sizeOfAlphabet, unsigned numberOfStates,
                                                                    unsigned numberOfNFAs);

    std::vector<boost::dynamic_bitset<>> &generateUniformRandomNFAs();


};


#endif //UNIFORMRANDOMNFAGENERATOR_RANDOMNFAGENERATOR_H
