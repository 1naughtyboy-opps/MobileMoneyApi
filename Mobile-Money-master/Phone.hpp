#ifndef Phone_H_INCLUDED_
#define Phone_H_INCLUDED_

#include "Simcard.hpp"
using namespace std;


class PHONE {
    public:
    PHONE() {
        this->command = "mmcli -L";
    }

    void bind(SIMCARD), log(string);
};

void PHONE::bind(SIMCARD card) {

}

void PHONE::log(string file) {

}

#endif