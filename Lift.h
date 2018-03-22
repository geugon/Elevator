#ifndef GUARD_Lift
#define GUARD_Lift

#include <vector>
#include "Rider.h"

class Lift {
    public:
        Lift() {};
        Lift(int);

        bool has_riders();
        unsigned int closest_dest();
        std::vector<Rider> exchange(std::vector<Rider>);

    private:
        int floor;
        std::vector< std::vector<Rider> > riders;

};

#endif
