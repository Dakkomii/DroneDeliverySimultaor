#ifndef CUSTOMER_H
#define CUSTOMER_H
/**
 * @file customer.h
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "entity_base.h"
#include <vector>
#include <string>
#include "json_helper.h"


namespace csci3081 {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the customer header file
 *
 * 
 */

class Customer : public csci3081::EntityBase {
  
 public:
   /**
   * @brief Constructor: this can do any setup your system necessitates.
   * @param pos is a vector that contains the x,y,z position
   * @param direction is a vector that stores the direction values for the drone
   * @param obj is a an object that contain the drones details
   */
   Customer(std::vector<float> pos, std::vector<float> direction, const picojson::object& obj); //constructor
   
   /**
   *  @brief Customer destructor
   */
   ~Customer(); //destructor

   /**
   *  @brief Returns package location
   */
   std::vector<float> GetLocation();

   /**
   *  @brief virtual fucntion to decorate customer
   */
   virtual void decorate();


 private:
 
  std::vector<float> location;
    
};
}

#endif