#include "Lift.h"

Lift::Lift(int nfloors): floor(0){
    riders.resize(nfloors);
}

bool Lift::has_riders(){
    //returns if anybody currently aboard
}

unsigned int Lift::closest_dest(){
    //returns closes requests target floor
}

std::vector<Rider> Lift::exchange(std::vector<Rider> newRiders){
    //returns list of riders who get off
}
