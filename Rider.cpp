#include "Rider.h"

std::istream& read(std::istream& is, Rider& r){
    is >> r.tick >> r.on >> r.off;
    return is;
}

bool compare(const Rider& a, const Rider& b){
    return a.tick < b.tick;
}
