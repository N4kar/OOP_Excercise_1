#include "data_reader.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <fstream>
#include <map>
#include <regex>

using namespace std;

void DataReader::checkInFile(const char *inFileName) {
    ifstream fin;
    fin.open(inFileName);
    if (!fin) {
        cout << "Can't open file to read" << endl;
        fin.close();
        exit(0);
    }
}
void DataReader::parseFile(const char *in, int &wordCount, list<pair<float, string>> &wordFrequencyList) {
    checkInFile(in);
    ifstream fin;
    fin.open(in);
    string str;
    map<string, float> myMap;
    map<string, float>::iterator it;
    while (getline(fin, str)) {
        regex re("[^a-zA-Z0-9]"); // Separators everything except letters and numbers
        sregex_token_iterator p(str.begin(), str.end(), re, -1);
        sregex_token_iterator end;
        while (p != end) {
            it = myMap.find(*p);
            if (it == myMap.end()) {
                myMap[*p] = 1;
            } else {
                myMap[*p]++;
            }
            *p++;
            wordCount++;
        }
    }
    for (auto it = myMap.begin(); it != myMap.end(); it++) {
        wordFrequencyList.push_back(make_pair(it->second, it->first));
    }
    wordFrequencyList.sort();
}
