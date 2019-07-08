#ifndef MODEM_H_INCLUDED_
#define MODEM_H_INCLUDED_

#include "functions.hpp"

using namespace std;

class MODEM {
    string pos_id;
    bool state = false, ready = false;
    public:
    bool get_modem(), enable(), set();
    string get_id();
};

bool MODEM::get_modem() {
    string device_status = pipe_terminal("mmcli -L");
    if(device_status.find("No modems were found")!=string::npos) {
        return false;
    } else {
        vector<string> split = seperate(device_status);
        //cout << "--test--: " << split[2] << endl;
        auto pos1 = split[2].find("m/");
        if(pos1 !=string::npos) {
            //cout << "Modem ID: " << split[2][pos1 + 2] << endl;
            this->pos_id.push_back(split[2][pos1 + 2]);
            //cout << "POSID: " << this->pos_id << endl;
            this->state = true;
            return true;
        }
    }
    return false;
}

bool MODEM::enable() {
    if(this->pos_id.empty()) {
        get_modem();
    }
    string command = "mmcli -m " + this->pos_id + " -e";
    string device_status = pipe_terminal(command);
    cout << device_status << endl;
    if(device_status.find("successfully")!=string::npos) {
        cout << "Device successfully enabled!" << endl;
        this->ready = true;
        return true;
    } else {
        cout << "Could not enable device, please try again..." << endl;
        return false;
    }
}

string MODEM::get_id() {
    return this->pos_id;
}

bool MODEM::set() {
    if(!pos_id.empty() and state and ready) return true;
    return false;
}

#endif