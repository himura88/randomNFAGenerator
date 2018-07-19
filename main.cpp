#include <iostream>
#include <sstream>
#include <fstream>
#include "StreamGenerator.h"
#include "RandomNFAGenerator.h"


#define LINE_BREAK "\n"

using namespace std;

void write_bistream_file (vector<boost::dynamic_bitset<>> stream_vector, ofstream &file_stream)
{
    for (size_t i = 0; i < stream_vector.size(); i++)
    {
        string current_bitstream;
        boost::to_string(stream_vector.at(i), current_bitstream);
        file_stream << current_bitstream << LINE_BREAK;
    }
    file_stream.close();
}


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

    string generated_nfa_ints_file_path = "/home/himura88/generatednfas/nfaints/";
    string generated_final_states_ints_file_path = "/home/himura88/generatednfas/finalstatesints/";
    string generated_nfa_bitstreams_file_path = "/home/himura88/generatednfas/nfabitstreams/";
    string generated_final_states_bitstreams_filepath = "/home/himura88/generatednfas/statesbitstreams/";


    vector<unsigned long> final_states_ints_vector = stream_generator->getRandom_int_final_states();
    vector<unsigned long> nfa_ints_vector = stream_generator->getRandom_int_nfa();

    vector<boost::dynamic_bitset<>> generated_NFAs = automata_generator->getGenerated_NFAs();
    vector<boost::dynamic_bitset<>> generated_NFAs_final_states = automata_generator->getGenerated_NFAs_final_states();

    //writing the generated numbers for final states into a file
    ofstream final_states_ints(
            generated_final_states_ints_file_path + "final-states-ints-input" + std::to_string(alphabet) + std::to_string(states) +
            std::to_string(numberOfNFAs) + ".txt");
    for (unsigned long i = 0; i < final_states_ints_vector.size(); i++)
    {
        final_states_ints << final_states_ints_vector.at(i) << LINE_BREAK;

    }

    //writing the generated numbers used to construct the nfa bitstreams into a file
    ofstream random_nfa_ints(
            generated_nfa_ints_file_path + "random-nfa-ints-input" + std::to_string(alphabet) + std::to_string(states) +
            std::to_string(numberOfNFAs) + ".txt");
    for (unsigned long i = 0; i < nfa_ints_vector.size(); i++)
    {
        random_nfa_ints << nfa_ints_vector.at(i) << LINE_BREAK;
    }

    //writing the generated nfa bit streams into a file
    ofstream random_nfa_bitstream(
            generated_nfa_bitstreams_file_path + "generated-nfa-bitstreams-" + std::to_string(alphabet) + "-" +
            std::to_string(states) + "-" +
            std::to_string(numberOfNFAs) + ".txt");

    write_bistream_file(generated_NFAs, random_nfa_bitstream );
  //  size_t nfa_vector_size = generated_NFAs.size() - 1;
   /* for (size_t i = 0; i < nfa_vector_size; i++)
    {
        string current_bitstream;
        boost::to_string(generated_NFAs.at(i), current_bitstream);
        random_nfa_bitstream << current_bitstream << LINE_BREAK;

    }*/

    //writing the generated bit streams for final states of nfa's into a file
    ofstream random_nfa_final_states(
            generated_final_states_bitstreams_filepath + "generated-final-states-bitstreams-" + std::to_string(alphabet) + "-" +
            std::to_string(states) + "-" +
            std::to_string(numberOfNFAs) + ".txt");

    for (size_t i = 0; i < generated_NFAs_final_states.size() -1 ; i++)
    {
        string current_bitstream;
        boost::to_string(generated_NFAs_final_states.at(i), current_bitstream);
        random_nfa_bitstream << current_bitstream << LINE_BREAK;
    }


    final_states_ints.close();
    random_nfa_ints.close();
    random_nfa_bitstream.close();
    random_nfa_final_states.close();
    return 0;
}