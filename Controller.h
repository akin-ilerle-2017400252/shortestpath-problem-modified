
#ifndef PROJECT3_AKIN_ILERLE_2017400252_CONTROLLER_H
#define PROJECT3_AKIN_ILERLE_2017400252_CONTROLLER_H

#include <queue>
#include <string>
#include "Town.h"
#include "io/FileIO.h"

class Controller {

    FileIO file;
    vector<Town*> towns;
    priority_queue<Town> priorityQueue;

public:
    void findMinDist(string inputfile, string outputfile);

};

#endif
