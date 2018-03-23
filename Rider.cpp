#include "Rider.h"

using std::cout;
using std::endl;

std::istream& read(std::istream& is, Rider& r){
    is >> r.tick >> r.on >> r.off;
    return is;
}

bool compare(const Rider& a, const Rider& b){
    return a.tick < b.tick;
}

void print_riders(SortedRiders riders){
    for (SortedRiders::iterator iter=riders.begin();
         iter != riders.end(); ++iter){
        cout << iter->size() << endl;
    }
}
