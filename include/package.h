/**
 * @file package.h
 */
#ifndef PACKAGE_H_
#define PACKAGE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "entity_base.h"
#include <vector>
#include <string>
#include "json_helper.h"
#include "include/customer.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the package header file.
 */

class Package : public csci3081::EntityBase {
 public:
   /**
    *  @brief Package constructor
    */
    Package(std::vector<float> pos, std::vector<float> direction, const picojson::object& obj); //constructor

   /**
    *  @brief Package destructor
    */   
   ~Package(); //destructor

   /**
   *  @brief This function should return package's weight
   */
   double GetWeight();

   /**
    *  @brief This function should return package's customer that is linked
    */
   Customer* GetCustomer();

   /**
    *  @brief This function should set the customer into the pachage object
    */
   void SetCustomer(Customer *customer);

   /**
    *  @brief This function should return the destination
    */
   std::vector<float> GetDestination();

   /**
    *  @brief This function should set the posistion of the package
    */
   void SetPosition(std::vector<float> position);

  /**
    *  @brief Sets drone dynamic value to b value
    * @param b bool value that IsDy is set to.
    */
   void SetDynamic(bool b);

  /**
    *  @brief Checks if package has been delivered
    */
   bool GetIsDelivered();

  /**
    *  @brief Sets a variable that indicates if a package has been delivered
      @param b 
    */
  void SetIsDelivered(bool b);

  /**
  *  @brief decorates package 
  */
  virtual void decorate();

 private:
    Customer* customer;
    std::vector<float> destination;
    double weight;
    bool IsDelivered;
  
};
}

#endif //PACKAGE_H_