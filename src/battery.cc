#include "include/battery.h"

namespace csci3081 {

Battery::Battery(){
    this->max_charge = 10000;
    this->remaining_battery = max_charge;
    this->no_charge = false;
}

Battery::Battery(int b){
    this->max_charge = b;
    this->remaining_battery = max_charge;

    if(b == 0)
        this->no_charge = true;
    else
        this->no_charge = false;
}

Battery::~Battery(){

}

bool Battery::IsEmpty(){

    if(remaining_battery <= 0){
        remaining_battery = 0;
        no_charge = true;
        return true;
    }
    else{
        no_charge = false; 
        return false;
    }
}

int Battery::checkBattery(){
    return remaining_battery;
}

void Battery::DepletingBattery(float dt){

    if (remaining_battery <= 0){

        remaining_battery = 0;
        no_charge = true;
        return;
    }
    else{
        remaining_battery -= dt;
    }
}


}