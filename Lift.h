#ifndef GUARD_Lift
#define GUARD_Lift

#include <vector>
#include "Rider.h"

enum Plan { up, down, doorsOpen };

class Lift {
    public:
        Lift() {};
        Lift(int);

        bool has_riders();
        unsigned int closest_dest();
        void move();
        std::vector<Rider> exchange(std::vector<Rider>);

        int floor;
        std::vector< std::vector<Rider> > riders;
        Plan plan;

};

#endif
