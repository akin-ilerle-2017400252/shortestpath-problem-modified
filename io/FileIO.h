#ifndef PROJECT3_AKIN_ILERLE_2017400252_FILEIO_H
#define PROJECT3_AKIN_ILERLE_2017400252_FILEIO_H

#include <string>
#include <fstream>
#include "../Town.h"


class FileIO {

    unsigned int numOfTowns, numOfRoads, numOfThieves,numOfJevelers;

public:
    vector<Town*> & read(const string& inputFile);

    unsigned int getNumOfTowns() const;

    unsigned int getNumOfThieves() const;

    void write(const string &outputfile, const vector<Town*> &towns, bool found);
};


#endif //PROJECT3_AKIN_ILERLE_2017400252_FILEIO_H
