#include "Lift.h"

using std::vector;

Lift::Lift(int nfloors): floor(0){
    riders.resize(nfloors);
}

bool Lift::has_riders(){
    //returns if anybody is currently aboard
    for (SortedRiders::iterator iter=riders.begin();
         iter != riders.end(); ++iter){
        if (iter->size() > 0) {
            return true;
        }
    }
    return false;
}

unsigned int Lift::closest_dest(){
    //returns closest requested target floor
    //assumes at least one rider is on board, no check!

    for (unsigned int i=0; i<riders.size(); ++i){
        if (riders[floor+i].size() > 0){
            return floor+i;
        }
        if (riders[floor-i].size() > 0){
            return floor-i;
        }
    }    

}

vector<Rider> Lift::exchange(vector<Rider> ridersOn){
    // Some riders get on
    for (vector<Rider>::iterator iter=ridersOn.begin();
         iter!=ridersOn.end(); ++iter){
        riders[iter->off].push_back(*iter);
    }

    // Some riders get off
    vector<Rider> ridersOff = riders[floor];
    riders[floor].clear();
    return ridersOff;
}

