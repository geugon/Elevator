#include <iostream>
#include <string>
#include <vector>
#include "Rider.h"

using std::vector;
using std::cout;
using std::endl;

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

    // Run
    unsigned int tick = 0;
    bool running = true;
    vector<Rider>::iterator nextRider = riders.begin();

    std::cout << "Elevator Simulation Initiated" << std::endl;
    while (running){
        while (nextRider->tick == tick){
            cout << nextRider->on << " " << nextRider->off << endl;
            ++nextRider;
            // Add code to turn into an actual request        
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

