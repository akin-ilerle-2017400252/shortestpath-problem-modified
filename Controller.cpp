#include <iostream>
#include "Controller.h"


void Controller::findMinDist(string inputfile, string outputfile){

    towns = file.read(inputfile);
    vector<bool> defaultCoins;
    defaultCoins.reserve(file.getNumOfThieves()+1);
    for(int i=0;i< file.getNumOfThieves()+1;i++)
        defaultCoins.push_back(false);
    towns[1]->updateDistance(defaultCoins,Distance(0,""));

    priorityQueue.push(*towns[1]);

    bool found = false;

    while(!priorityQueue.empty()){
        Town next = priorityQueue.top();
        priorityQueue.pop();

        if(next==*towns[file.getNumOfTowns()]) {
            found = true;
            break;
        }
        Distance dist = next.getMinDist();
        vector<bool> coins;

        for(auto& pair: next.getDistMap()){
            if(pair.second==dist){
                coins=pair.first;
                break;
            }
        }

        towns[next.getTownNo()]->getDistMapCopy().erase(coins); //delete current connection from consideration

        if(!towns[next.getTownNo()]->getDistMapCopy().empty()) //if there are other connections to consider, push again
            priorityQueue.push(*towns[next.getTownNo()]);

        for(auto& c: next.getAvailableCoins()){
            coins[c]=true;
        }

        for(auto& connection: next.getConnections()){
            bool canaccess=true;
            for(auto neededCoin: connection.neededCoins){
                if(!coins[neededCoin])
                    canaccess=false;
            }
            if(!canaccess)
                continue;
            Distance distance(connection.length+dist.distance,dist.route);
            bool updated = towns[connection.neighbor]->updateDistance(coins,distance);
            if(updated) {
                priorityQueue.push(*towns[connection.neighbor]);
            }
        }
    }

    file.write(outputfile,towns,found);

    for (auto&& town : towns) {
        delete town;
    }
}