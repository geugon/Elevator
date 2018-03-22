#ifndef GUARD_Bank
#define GUARD_Bank

#include <vector>
#include "Rider.h"
#include "Lift.h"

typedef std::vector< std::vector<Rider> > Requests;

/* The lifts Bank contains all lifts and active requests.
 * It determines and where lifts should go */

class Bank {
    public:
        Bank() {};
        Bank(const unsigned int, const unsigned int);
        void add_request(const Rider&);
        void plan();
        void execute();
        void summary();

    private:
        int floor;
        std::vector< Lift > lifts;
        Requests requestsUp;
        Requests requestsDown;

};
#endif