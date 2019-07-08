#ifndef mobileMoney_H_INCLUDED_
#define mobileMoney_H_INCLUDED_

#include "MODEM.hpp"

using namespace std;

class MOBILE_MONEY {
    private:
    string ussd_code, sender, reciever, responds(string);
    MODEM modem;
    double amount;
    string reference, pin;

    public:
    MOBILE_MONEY(string ussd_code = "*126#");
    void set_modem(MODEM&), run(bool), set_sender(string), set_reciever(string), set_reference(string), set_pin(string);
    string dial();
    bool set();
};

MOBILE_MONEY::MOBILE_MONEY(string ussd_code) {
    cout << "Initializing ussd code" << endl;
    this->ussd_code = ussd_code;
}

void MOBILE_MONEY::set_modem(MODEM& modem) {
    if(modem.set()) {
        this->modem = modem;
        cout << "MODEM ID: " << this->modem.get_id() << endl;
    } else {
        cout << "Modem isn't set!" << endl;
        return;
    }
}

void MOBILE_MONEY::set_sender(string sender) {
    this->sender = sender;
}

void MOBILE_MONEY::set_reciever(string reciever) {
    this->reciever = reciever;
    cout << "SET RECIEVER: " << this->reciever << endl;
}

string MOBILE_MONEY::dial() {
    return pipe_terminal("mmcli -m " + this->modem.get_id() + " --3gpp-ussd-initiate=\"" + this->ussd_code + "\"");
}

void MOBILE_MONEY::set_pin(string pin) {
    this->pin = pin;
    cout << "SET PIN: " << this->pin << endl;
}

void MOBILE_MONEY::set_reference(string reference) {
    this->reference = reference;
    cout << "SET REFERENCE: " << this->reference << endl;
}

string MOBILE_MONEY::responds(string value) {
    return pipe_terminal("mmcli -m " + this->modem.get_id() + " --3gpp-ussd-respond=\"" + value + "\"");
}

bool MOBILE_MONEY::set() {
    if(this->modem.set() && !this->reference.empty() && !this->pin.empty() && !this->reciever.empty()) {
        cout << "MOBILE MONEY: SET" << endl;
        return true;
    }
    cout << "MOBILE MONEY: NOT SET" << endl;
    return false;
}

void MOBILE_MONEY::run(bool debug = false) {
    string main_menu = dial();
    if(debug) cout << main_menu << endl;
    string responds_value = responds("1");
    if(debug) cout << responds_value << endl;
    responds_value = responds("1");
    if(debug) cout << responds_value << endl;
    responds_value = responds("1");
    if(debug) cout << responds_value << endl;
    responds_value = responds(this->reciever);
    if(debug) cout << responds_value << endl;
    responds_value = responds(to_string(this->amount));
    if(debug) cout << responds_value << endl;
    responds_value = responds(this->reference);
    if(debug) cout << responds_value << endl;
    responds_value = responds(this->pin);
    if(debug) cout << responds_value << endl;
}

#endif