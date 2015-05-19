#include <iostream>
#include "StreamGenerator.h"

using namespace std;

int main() {


    StreamGenerator * myStream;
    myStream = new StreamGenerator();

    dynamic_bitset<> foo = myStream->generateBitStream((324));
    std::cout << "foo:  " << foo << std::endl;
    return 0;
}