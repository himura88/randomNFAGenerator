#include <iostream>
#include <sstream>
#include <fstream>
#include "StreamGenerator.h"
#include "RandomNFAGenerator.h"


#define LINE_BREAK "\n"

using namespace std;


int main(int argc, char *argv[])
{

    RandomNFAGenerator *automata_generator;
    automata_generator = new RandomNFAGenerator();
    StreamGenerator *stream_generator = automata_generator->getGenerator();

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

    string generated_ints_file_path = "/home/himura88/";


    ofstream final_states_ints(
            generated_ints_file_path + "final_states_ints_input" + std::to_string(alphabet) + std::to_string(states) +
            std::to_string(numberOfNFAs) + ".txt");
    ofstream random_nfa_ints(
            generated_ints_file_path + "random_nfa_ints_input" + std::to_string(alphabet) + std::to_string(states) +
            std::to_string(numberOfNFAs) + ".txt");

    vector<unsigned long> final_states_ints_vector = stream_generator->getRandom_int_final_states();
    vector<unsigned long> nfa_ints_vector = stream_generator->getRandom_int_nfa();

    for (unsigned long i = 0; i < final_states_ints_vector.size(); i++)
    {
        final_states_ints << final_states_ints_vector.at(i) << LINE_BREAK;

    }

    for (unsigned long i = 0; i < nfa_ints_vector.size(); i++)
    {
        random_nfa_ints << nfa_ints_vector.at(i) << LINE_BREAK;
    }

    final_states_ints.close();
    random_nfa_ints.close();
    return 0;
}