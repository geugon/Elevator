#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "Rider.h"

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

    // Run
    unsigned int tick = 0;
    bool running = true;
    vector<Rider>::const_iterator nextRider = riders.begin();
    Requests requests(nfloors);

    std::cout << "Elevator Simulation Initiated" << std::endl;
    while (running){

        // Generate request as riders appear
        while (nextRider->tick == tick){
            requests[nextRider->on].push_back(*nextRider);
            ++nextRider;
        }
  
        // Plan and Execute tick for elevators
        // TODO


        // Remove Completed Requests
        cout << endl;
        for (Requests::iterator iter=requests.begin();
             iter != requests.end(); ++iter){
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

        // Termination condition will switch to when last ride is complete, once that data exists
        if (nextRider == riders.end()){
            running = false;
        }

        ++tick;
    }

    std::cout << "Simulation Complete" << std::endl;
    return 0;
}

