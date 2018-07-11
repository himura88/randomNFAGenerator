#include <iostream>
#include <sstream>
#include <fstream>
#include "StreamGenerator.h"
#include "RandomNFAGenerator.h"
#include <boost/date_time/posix_time/posix_time_io.hpp>

#define LINE_BREAK "\n"

using namespace std;
using namespace boost::posix_time;

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

    time_facet *facet = new time_facet("%d-%b-%Y %H-%M-%S");


    ofstream final_states_ints("/home/himura88/final_states_ints.txt");
    ofstream random_nfa_ints("/home/himura88/random_nfa_ints.txt");
    vector<int> final_states_ints_vector = stream_generator->getRandom_int_final_states();
    vector<int> nfa_ints_vector = stream_generator->getRandom_int_nfa();

    for (int i = 0; i < final_states_ints_vector.size(); i++)
    {
        final_states_ints << final_states_ints_vector.at(i) << LINE_BREAK;

    }

    for (int i = 0; i < nfa_ints_vector.size(); i++)
    {
        random_nfa_ints << nfa_ints_vector.at(i) << LINE_BREAK;
    }

    final_states_ints.close();
    random_nfa_ints.close();
    return 0;
}