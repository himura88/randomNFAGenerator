//
// Created by Carlos David on 5/18/15.
//

#include <fstream>
#include <sstream>
#include <chrono>
#include "RandomNFAGenerator.h"

#define DEFAULT_COMMA ","
#define OPEN_CURLY_BRACKET "{"
#define CLOSE_CURLY_BRACKET "}"
#define LINE_BREAK "\n"
#define START_STATE "1"
#define NUMBER_OF_START_STATES "1"
#define SPACE " "

RandomNFAGenerator::RandomNFAGenerator()
{
    this->generator = new StreamGenerator();
}

RandomNFAGenerator::RandomNFAGenerator(const RandomNFAGenerator &orig)
{
}

//Class default constructor
RandomNFAGenerator::~RandomNFAGenerator()
{
}

/*
 * Function that generates a vector of boost::dynamic_bitset that are going to be
 * interpreted as randomly generated NFAs.
 */
std::vector<boost::dynamic_bitset<>> &RandomNFAGenerator::generateUniformRandomNFAs()
{

    unsigned nfa_bit_stream_size = getAlphabet() * (getStates() * getStates());
    this->generated_NFAs.reserve(getNumber_of_NFAs());
    this->generated_NFAs_final_states.reserve(getNumber_of_NFAs());


    for (int i = 0; i <= getNumber_of_NFAs() - 1; i++)
    {
        dynamic_bitset<> currentNFA = generator->generateBitStream(nfa_bit_stream_size, 1);//replace magic number
        dynamic_bitset<> finalStates = generator->generateBitStream(getStates(), 0);//replace magic number

        this->generated_NFAs.push_back(currentNFA);
        this->generated_NFAs_final_states.push_back(finalStates);

    }
    return generated_NFAs;
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


/**
 * Function that takes a vector of boost::dynamic_bitset and write a text filed reading each bitset
 * as an NFA
 */
void RandomNFAGenerator::write_generated_NFAs(vector<boost::dynamic_bitset<>> generated_NFAs)
{


    std::string header_nfa_desc; //variable used to add header information to each NFA (#initial state and alphabet symbols


    header_nfa_desc.append("# Alfabeto");
    header_nfa_desc.append(LINE_BREAK);;
    header_nfa_desc.append(OPEN_CURLY_BRACKET);

    string generated_nfa_path = "/home/himura88/";



    ofstream generated_nfa_desc_file(generated_nfa_path + "generated-nfas-" + std::to_string(this->alphabet) + "-" +
                                     std::to_string(this->states) + "-" + std::to_string(this->number_of_NFAs) +
                                    "-" + ".txt");//TODO: Change the path for property file or input parameter


    size_t nfa_bit_stream_index = 0; //index used in the iteration of each bitstream.
    size_t number_of_states = getStates(); //number of states that each NFA has
    size_t size_of_alphabet = getAlphabet();//number of symbols of the alphabet of the NFA
    size_t nfa_vector_size = generated_NFAs.size() - 1; //Count the number of generated NFAs
    size_t nfa_bit_stream_size = getNfa_stream_size();//Size of the generated bitstream that represents a single NFA

    //Adding the symbols of the alphabet as a list {1,...,n}
    for (size_t alphabet = 1; alphabet <= size_of_alphabet; alphabet++)
    {
        header_nfa_desc.append(std::to_string(alphabet));
        header_nfa_desc.append(DEFAULT_COMMA);
    }

    header_nfa_desc.erase(header_nfa_desc.size() - 1);
    header_nfa_desc.append(CLOSE_CURLY_BRACKET);
    header_nfa_desc.append(LINE_BREAK);
    header_nfa_desc.append("# Numero de estados");
    header_nfa_desc.append(LINE_BREAK);
    header_nfa_desc.append(std::to_string(number_of_states));
    header_nfa_desc.append(LINE_BREAK);


    header_nfa_desc.append("# Estados iniciales");
    header_nfa_desc.append(LINE_BREAK);
    header_nfa_desc.append(NUMBER_OF_START_STATES);
    header_nfa_desc.append(SPACE);
    header_nfa_desc.append(START_STATE); //Start State is always 1
    header_nfa_desc.append(LINE_BREAK);


    /*
     * Outer cycle used to iterate over the whole list of generated bitstreams (Each bitstream/position of the vector
     * is going to be interpreted/read as an NFA)
     */
    for (size_t nfa_vector_index = 0; nfa_vector_index <= nfa_vector_size; nfa_vector_index++)
    {
        generated_nfa_desc_file << header_nfa_desc;
        generated_nfa_desc_file << "# Estados finales" << LINE_BREAK << get_final_states_int_rep(nfa_vector_index) << LINE_BREAK;
        generated_nfa_desc_file << "# Descripcion de las transiciones" << LINE_BREAK;


        dynamic_bitset<> current_nfa = generated_NFAs.at(nfa_vector_index);
        /*
         * The following set of loops are used to read the NFA transition table from the bitstreams.
         * The first one is iterating through the starting states (This means, the states from which each transition
         * is going to depart). The second one is reading the arriving states and the third one is reading the
         * alphabet symbols which labels the transition.
         */

        for (size_t i = 0; i < number_of_states; i++)
        {
            for (size_t j = 0; j < number_of_states; j++)
            {

                for (size_t k = 0; k < size_of_alphabet; k++)
                {

                    //std::cout << "nfa_bit_stream_index:" << nfa_bit_stream_index << std::endl;
                    if (current_nfa.test(nfa_bit_stream_index))
                    {
                        /*
                         * if entering here, that means that it is a none zero occurrence of a bit
                         * thus, a transition exists from i to j and labeled by k
                         */

                        generated_nfa_desc_file << i + 1 << SPACE << k + 1 << SPACE << j + 1 << LINE_BREAK;
                    }

                    nfa_bit_stream_index += 1;
                    if (nfa_bit_stream_index >= nfa_bit_stream_size)//reset the nfa_bit_stream_index when needed
                    {
                        nfa_bit_stream_index = 0;
                    }
                }
            }

        }

        generated_nfa_desc_file << LINE_BREAK;

    }

    generated_nfa_desc_file.close();
}


unsigned int RandomNFAGenerator::getNfa_stream_size() const
{

    return getAlphabet() * (getStates() * getStates());
}


string RandomNFAGenerator::get_final_states_int_rep(unsigned long pos_n) const
{
    std::string nfa_states_list;
    dynamic_bitset<> final_states_current_nfa_bit_stream = this->getGenerated_NFAs_final_states().at(pos_n);
    int number_of_final_states = 0;

    for (unsigned long i = 0; i < getStates(); i++)
    {

        if (final_states_current_nfa_bit_stream.test(i))
        {

            nfa_states_list += std::to_string(i + 1);
            nfa_states_list += SPACE;
            number_of_final_states += 1;
        }
    }

    nfa_states_list.insert(0, std::to_string(number_of_final_states));
    nfa_states_list.insert(1, SPACE);

    return nfa_states_list;
}
