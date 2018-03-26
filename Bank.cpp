#include "Bank.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

Bank::Bank(const unsigned int l, const unsigned int f)
:nlifts(l), nfloors(f), requestsUp(f), requestsDown(f), orders(l, exchangeUp)
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
    
    //early algorithm for initial test will have an up-focused lift and a down-focused lift.  Not a good stragegy, but convenient for testing
    
    unsigned int cur_floor;
    int target; // can be for down elevator with no target

    // Up elevator
    cur_floor = lifts[0].floor;
    if (lifts[0].has_riders()){
        if (lifts[0].riders[cur_floor].size() != 0 ||
            requestsUp[cur_floor].size() != 0){
            orders[0] = exchangeUp;
        }
        else{
            orders[0] = up;
        }
    }
    else {
        for (target=0; target!=nfloors; ++target){
            if (requestsUp[target].size() != 0) {
              break;
            }
        }
        if (target == nfloors) { //i.e. no-one to pickup
            if (cur_floor == 0){
                orders[0] = exchangeUp;
            }
            else{
                orders[0] = down;
            }
        }
        else if (target > lifts[0].floor){
            orders[0] = up;
        }
        else if (target < lifts[0].floor){
            orders[0] = down;
        }
        else{
            orders[0] = exchangeUp;
        }
    }

    // Down elevator
    cur_floor = lifts[1].floor;
    if (lifts[1].has_riders()){
        if (lifts[1].riders[cur_floor].size() != 0 ||
            requestsDown[cur_floor].size() != 0){
            orders[1] = exchangeDown;
        }
        else{
            orders[1] = down;
        }
    }
    else {
        for (target=nfloors-1; target!=-1; --target){
            if (requestsDown[target].size() != 0) {
              break;
            }
        }
        if (target == -1) { //i.e. no-one to pickup
            if (cur_floor == nfloors-1){
                orders[1] = exchangeDown;
            }
            else{
                orders[1] = up;
            }
        }
        else if (target > lifts[1].floor){
            orders[1] = up;
        }
        else if (target < lifts[1].floor){
            orders[1] = down;
        }
        else{
            orders[1] = exchangeDown;
        }
    }
}


void Bank::execute(){
    vector <Rider> unloaded; //trashed for now, could use for tracking later
    for (unsigned int i=0; i!=nlifts; ++i){
        switch (orders[i]) {
            case up:
                ++(lifts[i].floor);
                break;
            case down:
                --(lifts[i].floor);
                break;
            case exchangeUp:
                unloaded = lifts[i].exchange(requestsUp[lifts[i].floor]);
                break;
            case exchangeDown:
                unloaded = lifts[i].exchange(requestsDown[lifts[i].floor]);
                break;
        }
    }
}

void Bank::summary(){
    cout << endl;
    cout << endl;

    for (unsigned int i=nfloors-1; i != -1; --i){
        cout << requestsUp[i].size() << "\t" 
             << requestsDown[i].size() << "\t";
        for (unsigned int j=0; j != nlifts; ++j){
            if (lifts[j].floor == i){
                cout << "X" << "\t";
            }
            else {
                cout << "." << "\t";
            }
        }
        cout << endl;
    }

    cout << "\t\t";
    for (unsigned int i=0; i != nlifts; ++i){
        cout << orders[i] << "\t";
    } 
}

