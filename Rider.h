#ifndef GUARD_Rider
#define GUARD_Rider

#include <iostream>
#include <vector>

struct Rider{
    unsigned int tick;
    unsigned int on;
    unsigned int off;
};

typedef std::vector< std::vector<Rider> > SortedRiders;

std::istream& read(std::istream&, Rider&);
bool compare(const Rider&, const Rider&);
void print_riders(SortedRiders);

#endif
