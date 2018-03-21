#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "Rider.h"
#include "Lift.h"

using std::vector;
using std::map;
using std::cout;
using std::endl;

typedef vector< vector<Rider> > Requests;

int main(){

    // Import Settings
    //   Hard-coded for now, will turn into json or something
    //   similar after more options are available
    const unsigned int nfloors = 10;
    const unsigned int nlifts = 2;

    // Import Riders (technically riders-to-be, not on lifts yet!)
    vector<Rider> riders;
    Rider rider;
    while (read(std::cin, rider)){
        riders.push_back(rider);
    }
    sort(riders.begin(), riders.end(), compare);

    // Initialize Elevators
    vector<Lift> lifts;
    lifts.reserve(nlifts);
    for (unsigned int i=0; i != nfloors; ++i){
        lifts.emplace_back(nfloors);
    }

    // Run
    unsigned int tick = 0;
    bool running = true;
    vector<Rider>::const_iterator nextRider = riders.begin();
    Requests requestsUp(nfloors);
    Requests requestsDown(nfloors);

    std::cout << "Elevator Simulation Initiated" << std::endl;
    while (running){

        // Generate request as riders appear
        while (nextRider->tick == tick){
            if (nextRider->on > nextRider->off){
               requestsDown[nextRider->on].push_back(*nextRider);
            }
            else{
               requestsUp[nextRider->on].push_back(*nextRider);
            }
            ++nextRider;
        }
  
        // Plan Elevators 
        // TODO        

        // Execute Elevators
        // TODO

        // Remove Completed Requests
        cout << endl;
        for (Requests::iterator iter=requestsUp.begin();
             iter != requestsUp.end(); ++iter){
            // For now assume everyone is picked up 10 ticks after the first request to a floor is made
            if (iter->size() == 0) {
                cout << "NA" << endl;
                continue;
            }
            int firstTick = (*iter)[0].tick;
            cout << firstTick << endl;
            if (firstTick + 10 <= tick){
                iter->clear();
            }
        }

        // Generate visual report

        // Termination condition will switch to when last ride is complete, once that data exists
        if (nextRider == riders.end()){
            running = false;
        }

        ++tick;
    }

    std::cout << "Simulation Complete" << std::endl;
    return 0;
}

