//
// Created by Carlos David on 5/18/15.
//

#include "RandomNFAGenerator.h"
RandomNFAGenerator::RandomNFAGenerator() {
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

void RandomNFAGenerator::setNfaTransitionTables(vector<dynamic_bitset<>> *nfaTransitionTables) {
    RandomNFAGenerator::nfaTransitionTables = nfaTransitionTables;
}

void RandomNFAGenerator::setGenerator(StreamGenerator *generator) {
    RandomNFAGenerator::generator = generator;
}

vector<dynamic_bitset<>> *RandomNFAGenerator::getNfaTransitionTables() const {
    return nfaTransitionTables;
}

void RandomNFAGenerator::setInitialStates(const dynamic_bitset<> &initialStates) {
    RandomNFAGenerator::initialStates = initialStates;
}