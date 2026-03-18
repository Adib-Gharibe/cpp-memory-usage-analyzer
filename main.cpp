#include <iostream>
#include <sys/resource.h>
#include <thread>
#include <vector>

using namespace std;


void funcMem(rusage * memUsagePtr) {
    u_int64_t i = 0;
    vector<unsigned long> numbers = {}; // dynamisches Array mit New

    do {
        numbers.push_back(i);
        if (i % 1000000 == 0) {
            getrusage(RUSAGE_SELF, memUsagePtr);
            cout << " used memory: " << memUsagePtr->ru_maxrss << " kB" << endl;


        }
        i++;
    }
    while(i < 1000000 * 200);
    auto _startIt = numbers.begin();
    auto _endIt = numbers.end();

    unsigned long _output = (*_startIt++ + *_endIt--); //zusätzliche arithmetische Berechnungen.

    while (_startIt != _endIt) {
        _output = (*_startIt++ + *_endIt--);
        if ((*_startIt & 1000000) == 0) {
            cout << _output << endl;
        }
    }

}


int main() {
    auto * rUsagePtr = new rusage;
    auto * rLimitPtr = new rlimit;

    funcMem(rUsagePtr);
    delete rUsagePtr;


    delete rLimitPtr;

    return 0;
}
