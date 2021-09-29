
#ifndef OOP_FIRST_LAB_0B_WRITEDATA_H
#define OOP_FIRST_LAB_0B_WRITEDATA_H

#include <list>
#include <cstdlib>
#include <string>

class DataWriter {
private:
    void checkOutFile(const char *);

public:
    void print(std::list<std::pair<float, std::string>>&myList, int, const char *);


};


#endif //OOP_FIRST_LAB_0B_WRITEDATA_H
