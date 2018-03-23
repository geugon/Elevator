#ifndef GUARD_Lift
#define GUARD_Lift

#include "Rider.h"

struct Lift {
    Lift() {};
    Lift(int);

    bool has_riders();
    unsigned int closest_dest();
    std::vector<Rider> exchange(std::vector<Rider>);

    int floor;
    SortedRiders riders;

};

#endif
