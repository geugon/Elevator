#include "Bank.h"
#include <iostream>

using std::cout;
using std::endl;

Bank::Bank(const unsigned int nlifts, const unsigned int nfloors)
:requestsUp(nfloors), requestsDown(nfloors)
{
    lifts.reserve(nlifts);
    for (unsigned int i=0; i != nfloors; ++i){
        lifts.emplace_back(nfloors);
    }
}

void Bank::add_request(const Rider& nextRider){
    if (nextRider.on > nextRider.off){
        requestsDown[nextRider.on].push_back(nextRider);
    }
    else{
        requestsUp[nextRider.on].push_back(nextRider);
    }
}

void Bank::plan(){
    //sets orders for all lifts
}

void Bank::execute(){
    //executes orders for all lifts
}

void Bank::summary(){
    cout << endl;
    for (Requests::iterator iter=requestsUp.begin();
            iter != requestsUp.end(); ++iter){
        if (iter->size() == 0) {
            cout << "NA" << endl;
            continue;
        }
        int firstTick = (*iter)[0].tick;
        cout << firstTick << endl;
    }
}

