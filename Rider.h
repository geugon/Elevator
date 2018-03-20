#ifndef GUARD_Rider
#define GUARD_Rider

#include <iostream>

struct Rider{
    unsigned int tick;
    unsigned int on;
    unsigned int off;
};

std::istream& read(std::istream&, Rider&);

#endif
