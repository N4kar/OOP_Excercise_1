#ifndef OOP_FIRST_LAB_0B_READDATA_H
#define OOP_FIRST_LAB_0B_READDATA_H

// Читает данные из входного файла и парсит так что слова могут быть только из букв и цифр

#include <list>
#include <cstdlib>
#include <string>

class DataReader {
private:
    void checkInFile(const char *);

public:
    void parseFile(const char *inputFilename, int &wordCount, std::list<std::pair<float, std::string>>&wordFrequencyList);
};

#endif
