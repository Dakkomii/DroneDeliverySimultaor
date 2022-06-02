/**
 * @file concrete_parabolic.h
 */
#ifndef CONCRETE_PARABOLIC_H_
#define CONCRETE_PARABOLIC_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/facade/delivery_system.h>
#include <vector>
#include <string>
#include <cmath>
#include "IStrategy.h"
#include "include/vector3d.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the concrete header file for the parabolic route
 *
 *
 */
class ConcreteParabolic : public csci3081::IStrategy {
 public:

   /**
  *  @brief Concrete_parabolic constructor
  */ 
   ConcreteParabolic();

   /**
  *  @brief Concrete_parabolic destructor
  */
   ~ConcreteParabolic();

   /**
  *  @brief Gets the index that goes through the routeOne or RouteTwo
  */
   int getIndex();

   /**
  *  @brief Sets the index that goes through the routeOne or RouteTwo
  * @param i is an int to set index
  */
   void SetIndex(int i);

   /**
  *  @brief Sets the index that goes through the routeOne or RouteTwo
  * @param b a bool variable to set pickedPackage variable
  */
   void SetHasPackage(bool b);

   /**
  *  @brief Return pickedPackage variable that hols a bool that is true when 
  * the drone has reached the package
  */
   bool HasPackage();

   /**
  *  @brief Return true if the end of route from drone to package is reached false otherwise
  */
   bool GetEndOfRouteOne();

   /**
  *  @brief Return true if the end of route from package/drone to customer is reached false otherwise
  */
   bool GetEndOfRouteTwo();

   /**
  *  @brief Sets direction vector
  * @param dir is a vector of floats
  */
   void SetDirection(std::vector<float> dir);

   /**
  *  @brief returns direction vector
  */
   std::vector<float> GetDirection();

   /**
  *  @brief subracts two vectors
  */
   float distance(std::vector<float> vector1, std::vector<float> vector2);
  
  /**
  *  @brief Get the path from the startegy and set it into the member variable routeOne
  */
  std::vector<std::vector<float>> GetRouteOneSmart();

  /**
  *  @brief Get the path from the startegy and set it into the member variable routeTwo
  */
  std::vector<std::vector<float>> GetRouteTwoSmart();

   /**
  *  @brief Sets up all the member variables that are necessary for the strategy
  * @param DLocation float vector of drone position
  * @param PLocation Package position
  * @param CLocation Customer position
  */
   void SetUp(std::vector<float> DLocation, std::vector<float> PLocation, std::vector<float> CLocation);

   /**
  *  @brief This method perform the strategy and moves the drone
  * @param dt is the time fram
  * @param speed drone's speed that comes from the details_ that is passed in CreateEntity()
  * @param radius drone's radius that comes from the details_ that is passed in CreateEntity()
  */
   std::vector<float> move(float dt, float speed, float radius);


 private:
    std::vector<std::vector<float>> routeOne;
    std::vector<std::vector<float>> routeTwo;
    std::vector<float> dronePos;
    std::vector<float> packagePos;
    std::vector<float> customerPos;
    std::vector<float> direction;
    std::vector<float> v;
    std::vector<float> vt;
    std::vector<float> Vm;
    std::vector<float> distanceV0Vm;
    std::vector<float> distanceVVm;
    float speed;
    float y; 
    int routeIndex;
    int T;
    int j;
    bool pickedPackage;
    bool endOfRouteOne;
    bool endOfRouteTwo;

};
}
#endif