#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <fstream>
#include <map>
#include <regex>
#include "data_writer.h"
#include "data_reader.h"

#include <list>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Bad input" << std::endl;
        return 0;
    }
    const char *inputFilename = argv[1];
    const char *outputFilename = argv[2];

    auto *dataReader = new DataReader();
    auto *dataWriter = new DataWriter();

    int wordCount = 0;
    list<pair<float, string>> wordFrequencyList;
    dataReader->parseFile(inputFilename, wordCount, wordFrequencyList);

    dataWriter->print(wordFrequencyList, wordCount, outputFilename);

    delete dataReader;
    delete dataWriter;
    return 0;
}




