/**
 * @file battery.h
 */
#ifndef BATTERY_H_
#define BATTERY_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <vector>
#include <string>



namespace csci3081 {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Battery header file. Creates Battery objects for drone
 * 
 * 
 */

class Battery{

    public:
    /**
   *  @brief Battery constructor with 0 arguments
   * sets max_charge to 10000, remaining_battery to 10000 and no_charge to false
   */
    Battery();

    /**
   *  @brief Battery constructor with int argument.
   * @param b int value to initialize battery max_charge
   * sets max_charge to b, remaining_battery to max_charge and no_charge to false if
   * b is greater that 0
   */
    Battery(int b);

    /**
   *  @brief Battery class destructor
   */
    ~Battery();
    
    /**
   *  @brief checks if the battery is empty
   * returns true if remaining_battery is 0 otherwise return false
   */
    bool IsEmpty(); //checks if the battery has no charge

    /**
   *  @brief return the battery charge
   */
    int checkBattery(); //checks the battery

    /**
   *  @brief deplets battery charge by the value dt
   *  @param dt float used to reduce battery charge
   */
    void DepletingBattery(float dt); //deplestes battery per seconds

    private:

    int max_charge;
    float remaining_battery;
    bool no_charge;

};

}

#endif //BATTERY_H_

