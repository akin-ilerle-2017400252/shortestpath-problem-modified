#ifndef PROJECT3_AKIN_ILERLE_2017400252_TOWN2_H
#define PROJECT3_AKIN_ILERLE_2017400252_TOWN2_H

#include <map>
#include <vector>
#include <set>
#include <string>

using namespace std;

class Distance;
class Road;


class Town{
    map <vector<bool>,Distance> distMap; //coin sets -> the distances of this town from the starting node having the coins
    map <vector<bool>,Distance> distMapCopy; //copy of the distmap
    set<int> availableCoins;
    vector<Road> connections;
    int townNo;

public:

    explicit Town(int townNo);

    /**
     * updates the distance of the town for the according coin set.
     * returns a boolean to tell if the node should be added to the priorityQueue.
     * @param coins
     * @param dist
     * @return
     */
    bool updateDistance(const vector<bool> &coins,Distance dist);

    void addCoin(int coin);

    void addConnection(Road& road);

    /**
     * returns the shortest distance from this town to starting town, along with the route.
     * @return
     */
    Distance getMinDist() const;

    const set<int> &getAvailableCoins() const;

    vector<Road> &getConnections() ;

    const map<vector<bool>, Distance> &getDistMap() const;

    map<vector<bool>, Distance> &getDistMapCopy();

    bool operator<(const Town &rhs) const;

    bool operator==(const Town &rhs) const;

    bool operator!=(const Town &rhs) const;

    int getTownNo() const;

};

struct Road {   //a conncetion between two towns.

    int length;
    std::set<int> neededCoins;  //coins needed to pass this road safely
    int neighbor;

    Road(int neighbor, int length, const std::set<int> &neededCoins);

};


struct Distance{

    int distance;   //distance from the starting node
    string route;   //route from the starting node
    Distance(int distance, const string &route);
    Distance();

    void setRoute(int route);

    bool operator<(const Distance &rhs) const;

    bool operator>(const Distance &rhs) const;

    bool operator<=(const Distance &rhs) const;

    bool operator>=(const Distance &rhs) const;

    bool operator==(const Distance &rhs) const;

    bool operator!=(const Distance &rhs) const;
};


#endif //PROJECT3_AKIN_ILERLE_2017400252_TOWN2_H
