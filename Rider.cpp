#include "Rider.h"

std::istream& read(std::istream& is, Rider& r){
    is >> r.tick >> r.on >> r.off;
    return is;
}
