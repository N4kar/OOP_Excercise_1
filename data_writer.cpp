#include "data_writer.h"

#include "data_reader.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <fstream>
#include <map>
#include <regex>

using namespace std;

void DataWriter::checkOutFile(const char *outFileName) {
    ofstream out;
    out.open(outFileName);
    if (!out) {
        cout << "Can't open file to write" << endl;
        out.close();
        exit(0);
    }
}


void DataWriter::print(list<pair<float, string>> &myList, int allWords, const char *outFile) {
    checkOutFile(outFile);
    ofstream out;
    out.open(outFile);
    for (auto iterator_list = myList.rbegin(); iterator_list != myList.rend(); ++iterator_list) {
        out << iterator_list->second << ";" << iterator_list->first << ";" << ((iterator_list->first) / allWords) * 100
            << "%" << endl;
    }
    cout << "Words have been counted!" << endl;
    out.close();
}
