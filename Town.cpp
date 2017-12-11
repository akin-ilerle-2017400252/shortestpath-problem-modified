#include "Town.h"


bool Town::updateDistance(const vector<bool> &coins, Distance dist){

    if( (distMap.count(coins)==1 && distMap.at(coins)>dist) || distMap.count(coins)==0){
        dist.setRoute(townNo);
        distMap[coins]=dist;
        distMapCopy[coins]=dist;
        return true;
    }

    return false;
}

void Town::addCoin(int coin) {
    availableCoins.insert(coin);
}

void Town::addConnection(Road &road) {
    connections.emplace_back(road);
}

Distance Town::getMinDist() const{
    Distance min=Distance(INT32_MAX,"");
    for(auto& road: distMapCopy){
        if(min>road.second)
            min=road.second;
    }
    return min;
}

bool Town::operator<(const Town &rhs) const {

    return getMinDist()>rhs.getMinDist();

}

vector<Road> &Town::getConnections() {
    return connections;
}

const set<int> &Town::getAvailableCoins() const {
    return availableCoins;
}

const map<vector<bool>, Distance> &Town::getDistMap() const{
    return distMap;
}

bool Town::operator==(const Town &rhs) const {
    return townNo==rhs.townNo;
}

bool Town::operator!=(const Town &rhs) const {
    return rhs.townNo != townNo;
}

Town::Town(int townNo) : townNo(townNo) {}

int Town::getTownNo() const {
    return townNo;
}

map<vector<bool>, Distance> &Town::getDistMapCopy() {
    return distMapCopy;
}


Road::Road(int neighbor, int length, const set<int> &neededCoins) : neighbor(neighbor), length(length),
                                                                            neededCoins(neededCoins) {}

Distance::Distance(int distance, const string &route) : distance(distance), route(route) {}

bool Distance::operator<(const Distance &rhs) const {
    return distance < rhs.distance;
}

bool Distance::operator>(const Distance &rhs) const {
    return rhs < *this;
}

bool Distance::operator<=(const Distance &rhs) const {
    return !(rhs < *this);
}

bool Distance::operator>=(const Distance &rhs) const {
    return !(*this < rhs);
}

void Distance::setRoute(int route) {
    Distance::route = Distance::route + to_string(route) + " ";
}

Distance::Distance() = default;

bool Distance::operator==(const Distance &rhs) const {
    return distance == rhs.distance &&
           route == rhs.route;
}

bool Distance::operator!=(const Distance &rhs) const {
    return !(rhs == *this);
}


