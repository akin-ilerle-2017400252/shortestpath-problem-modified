#include "FileIO.h"

vector<Town*> & FileIO::read(const string& inputFile){

    ifstream input;
    input.open(inputFile);
    input>>numOfTowns;
    input>>numOfRoads;
    input>>numOfThieves;
    input>>numOfJevelers;

    auto *towns = new vector<Town*>(numOfTowns+1);

    for(int i=1;i<numOfTowns+1;i++){
        towns->at(i)=new Town(i);
    }

    for(int i=0;i<numOfJevelers;i++){
        unsigned int townNo,numOfCoins;
        input>>townNo;
        input>>numOfCoins;
        for(int j=0;j<numOfCoins;j++){
            int coin;
            input>>coin;
            towns->at(townNo)->addCoin(coin);
        }
    }

    for(int i=0;i<numOfRoads;i++){
        unsigned int town1,town2,length,numOfCoinsNeeded;
        input>>town1;
        input>>town2;
        input>>length;
        input>>numOfCoinsNeeded;
        set<int> neededCoins;
        for(int j=0;j<numOfCoinsNeeded;j++){
            int coin;
            input >> coin;
            neededCoins.insert(coin);
        }
        Road road1=Road(town2,length,neededCoins);
        Road road2=Road(town1,length,neededCoins);
        towns->at(town1)->addConnection( road1 );
        towns->at(town2)->addConnection( road2 );
    }

    input.close();

    return *towns;

}

unsigned int FileIO::getNumOfTowns() const {
    return numOfTowns;
}

unsigned int FileIO::getNumOfThieves() const {
    return numOfThieves;
}

void FileIO::write(const string &outputfile, const vector<Town*> &towns, bool found) {
    ofstream writer;
    writer.open(outputfile);
    if(found){
        auto it = towns.end()-1;
        writer << (*(*it)).getMinDist().route;
    }
    else{
        writer << to_string(-1);
    }
    writer.close();
}
