#include <iostream>
#include "Controller.h"
using namespace std;


int main(int argc, char* argv[]) {

    Controller controller;

    if(argc==3)
        controller.findMinDist(argv[1], argv[2]);
    else
        controller.findMinDist("input.txt", "output.txt");


    return 0;
}