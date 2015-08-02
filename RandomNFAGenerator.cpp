//
// Created by Carlos David on 5/18/15.
//

#include <fstream>
#include <sstream>
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


std::vector<boost::dynamic_bitset<>> &RandomNFAGenerator::generateUniformRandomNFAs()
{

    unsigned nfa_bit_stream_size = getAlphabet() * (getStates() * getStates());
    for (int i = 0; i <= getNumber_of_NFAs() - 1; i++)
    {
        dynamic_bitset<> currentNFA = generator->generateBitStream(nfa_bit_stream_size);
        dynamic_bitset<> finalStates = generator->generateBitStream(getStates());

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



void RandomNFAGenerator::write_generated_NFAs(vector<boost::dynamic_bitset<>> generated_NFAs)
{


    ofstream generated_nfa_desc_file("/home/hassingard/Desktop/example3.txt");

    generated_nfa_desc_file << "# Alfabeto" << "\n" << "{";


    size_t nfa_bit_stream_index = 0;
    size_t number_of_states = getStates();
    size_t size_of_alphabet = getAlphabet();
    size_t nfa_vector_size = generated_NFAs.size() - 1;
    size_t nfa_bit_stream_size = getNfa_stream_size();

    for (size_t alphabet = 1; alphabet <= size_of_alphabet; alphabet++)
    {
        generated_nfa_desc_file << alphabet << ",";
    }

    generated_nfa_desc_file << "}"  << "\n";

    generated_nfa_desc_file << "# Numero de estados" << "\n" << number_of_states << "\n";


    for (size_t nfa_vector_index = 0; nfa_vector_index <= nfa_vector_size; nfa_vector_index++)
    {
        generated_nfa_desc_file << "# Estados iniciales" << "\n" << 1 << "\n";
        generated_nfa_desc_file << "# Estados finales" << "\n" << get_final_states_int_rep(nfa_vector_index) << "\n";
        generated_nfa_desc_file << "# Descripcion de las transiciones" << "\n";


        dynamic_bitset<> current_nfa = generated_NFAs.at(nfa_vector_index);
        for (size_t i = 0; i < number_of_states; i++)
        {
            for (size_t j = 0; j < number_of_states; j++)
            {

                for (size_t k = 0; k < size_of_alphabet; k++)
                {

                    std::cout << "nfa_bit_stream_index:" << nfa_bit_stream_index << std::endl;
                    if (current_nfa.test(nfa_bit_stream_index))
                    {

                        generated_nfa_desc_file << i + 1 << " " << k + 1 << " " << j + 1 << "\n";
                    }

                    nfa_bit_stream_index += 1;
                    if (nfa_bit_stream_index >= nfa_bit_stream_size)//reset the nfa_bit_stream_index when needed
                    {
                        nfa_bit_stream_index = 0;
                    }
                }
            }

        }

        generated_nfa_desc_file << "\n";

    }

    generated_nfa_desc_file.close();
}


unsigned int RandomNFAGenerator::getNfa_stream_size() const
{

   return getAlphabet()*(getStates()*getStates());
}


string RandomNFAGenerator::get_final_states_int_rep(int pos_n) const
{
    std::string nfa_states_list;
    dynamic_bitset<> final_states_current_nfa_bit_stream = this->getGenerated_NFAs_final_states().at(pos_n);

    for (int i = 0; i < getStates(); i ++)
    {

        if (final_states_current_nfa_bit_stream.test(i))
        {

            nfa_states_list += std::to_string(i + 1);
            nfa_states_list += " ";
        }
    }

    return nfa_states_list;
}
