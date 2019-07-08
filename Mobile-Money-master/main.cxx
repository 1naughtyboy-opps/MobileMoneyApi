#include "MOBILE_MONEY.hpp"
using namespace std;


int main() {
    MODEM modem;
    if(modem.get_modem()) {
        modem.enable();

        MOBILE_MONEY mobileMoney;
        mobileMoney.set_modem(modem);
        mobileMoney.set_reciever("676968696");
        mobileMoney.set_reference("tenga test transaction");
        mobileMoney.set_pin("11235");

        if(mobileMoney.set()) {
            mobileMoney.run(true);
        } else {
            cout << "Mobile money isn't set" << endl;
        }
    } else {
        cout << "No modem plugged in" << endl;
    }


}
