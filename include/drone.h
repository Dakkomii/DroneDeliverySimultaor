/**
 * @file drone.h
 */
#ifndef DRONE_H_
#define DRONE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "include/entity_base.h"
#include <vector>
#include <string>
#include "json_helper.h"
#include "battery.h"
#include "vector3d.h"
#include "include/package.h"
#include "IStrategy.h"
//#include "include/package.h"


namespace csci3081 {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the drone header file
 *
 *
 */

class Drone : public csci3081::EntityBase {
 public:
  /**
   * @brief Constructor: this can do any setup your system necessitates.
   * @param pos is a vector that contains the x,y ,z position
   * @param direction is a vector that stores the direction values for the drone
   * @param obj is a an object that contain the drones details
   */
  Drone(std::vector<float> pos, std::vector<float> direction, const picojson::object& obj);

   /**
   *  @brief Drones Destructors
   */
  ~Drone();

   /**
   *  @brief This function should make the drone move by dt.
   * it is called from delivery simulation
   *  @param dt used to know how much moves by each update call
   */
   void update(float dt);

   /**
   *  @brief Set deliver variable to true if drone is delivering a package or false otherwise
   *  @param b is a bool variable
   */
   void SetDelivering(bool b);

   /**
   *  @brief returns deliver variable
   */
   bool IsDelivering();

   /**
   *  @brief Set route between drone and package
   */
   void SetRouteOne();

   /**
   *  @brief Set route between package and customer
   */
   void SetRouteTwo();

   /**
  *  @brief Get route between drone and package
  */
  std::vector<std::vector<float>> GetRouteOne();

  /**
  *  @brief Get route between package and customer
  */
   std::vector<std::vector<float>> GetRouteTwo();

   /**
   *  @brief updates index everytime the drone get to a point in the path
   */
   void SetIndex(int i);

   /**
   *  @brief sets index for the update function
   */
   int GetIndex();

   /**
    *  @brief This function should set the package into the drone
    */
   void SetPackage(Package* Package);

   /**
    *  @brief Sets hasPackage to true if drone reached the package false otherwise
    */
   void SetPackage(bool b);

   /**
    *  @brief Returns hasPackage value. Used to check if drone picked up package
    */
   bool GetPackage();

   /**
  *  @brief returns the package object pointer
  */
   Package* GetPackageObject();

   /**
  *  @brief checks if the battery is empty
  * */
   bool isBaterryDepleted();

   /**
  *  @brief sets strategy
  */
   void SetStrategy(IStrategy* strategy);

   /**
  *  @brief sets up the startegy
  */
   void setUpStrategy(std::vector<float> d, std::vector<float> p, std::vector<float> c);

   /**
  *  @brief get bool value for droneToPackage
  */
  bool GetDroneToPackage();

  /**
 *  @brief get bool value for droneToCustomer
 */
	bool GetDroneToCustomer();
  /**
 *  @brief get bool value for droneHasPackage
 */
	bool GetDroneHasPackage();
  /**
 *  @brief get bool value for dronefinished
 */
   bool GetDronefinished();
   /**
   *  @brief set bool value for droneToPackage
   */
   void SetDroneToPackage(bool b);
   /**
  *  @brief sets up bool value for droneToCustomer
  */
	void SetDroneToCustomer(bool b);

  /**
 *  @brief sets up the bool value for droneHasPackage
 */
	void SetDroneHasPackage(bool b);

  /**
 *  @brief sets up bool value for dronefinished
 */
   void SetDronefinished(bool b);

   /**
  *  @brief resets bool values for dronefinished, droneToPackage, droneToCustomer, bool droneHasPackage to false
  */
   void Reset();

   /**
  *  @brief decorates drone
  */
   virtual void decorate();

  private:
   Battery* battery;
   bool batteryDepleted;
   bool deliver;
   std::vector<std::vector<float>> routeOne;
   std::vector<std::vector<float>> routeTwo;
   int index;
   Package* package;
   bool hasPackage;

   //strategy code
   IStrategy* strategy;
   std::vector<float> Ppos;
   std::vector<float> Cpos;
   float speed;

   bool droneToPackage;
	 bool droneToCustomer;
	 bool droneHasPackage;
   bool dronefinished;

};

}

#endif //DRONE_H_
