#ifndef SIMCARD_H_INCLUDED_
#define SIMCARD_H_INCLUDED_

#include <iostream>
using namespace std;


class SIMCARD {
    public:
    SIMCARD() {
        cout << "SIMCARD INITIATED" << endl;
    }

    void dialer(string values), presses(vector<int> logistics);
};


void SIMCARD::dialer(string value) {
    cout << "Checking dialing code - CODE [" << value << "]" << endl;
    string command = 
}

void SIMCARD::presses(vector<int> logistics) {

}

#endif