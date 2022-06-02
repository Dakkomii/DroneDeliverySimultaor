/**
 * @file robot.h
 */
#ifndef ROBOT_H_
#define ROBOT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "entity_base.h"
#include <vector>
#include <string>
#include "json_helper.h"
#include "battery.h"
#include "vector2d.h"
#include "vector3d.h"
#include "include/package.h"
#include "IStrategy.h"


namespace csci3081 {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the robot header file
 *
 *
 */

class Robot : public csci3081::EntityBase {
 public:
  /**
   * @brief Constructor: this can do any setup your system necessitates.
   * @param pos is a vector that contains the x,y ,z position
   * @param direction is a vector that stores the direction values for the robot
   * @param obj is a an object that contain the Robots details
   */
  Robot(std::vector<float> pos, std::vector<float> direction, const picojson::object& obj);

   /**
   *  @brief Robot Destructors
   */
  ~Robot();

   /**
   *  @brief This function should make the Robot move by dt.
   * it is called from delivery simulation
   *  @param dt used to know how much moves by each update call
   */
   void update(float dt);

   /**
   *  @brief Set deliver variable to true if Robot is delivering a package or false otherwise
   *  @param b is a bool variable
   */
   void SetDelivering(bool b);

   /**
   *  @brief returns deliver variable
   */
   bool IsDelivering();

   /**
   *  @brief Set route between robot and package
   */
   void SetRouteOne();

   /**
   *  @brief Set route between package and customer
   */
   void SetRouteTwo();

   /**
   *  @brief Get route between robot and package
   */
   std::vector<std::vector<float>> GetRouteOne();

   /**
   *  @brief Get route between package and customer
   */
    std::vector<std::vector<float>> GetRouteTwo();

   /**
   *  @brief updates index everytime the robot get to a point in the path
   */
   void SetIndex(int i);

   /**
   *  @brief gets index for the update function
   */
   int GetIndex();

   /**
    *  @brief This function should set the package into the robot
    */
   void SetPackage(Package* Package);

   /**
    *  @brief Sets hasPackage to true if robot reached the package false otherwise
    */
   void SetPackage(bool b);

   /**
    *  @brief Returns hasPackage value. Used to check if robot picked up package
    */
   bool GetPackage();

   /**
    *  @brief Returns Package object
    */
   Package* GetPackageObject();

   /**
  *  @brief checks if battery is empty
  */
   bool isBaterryDepleted();

   /**
  *  @brief sets strategy pattern
  */
   void SetStrategy(IStrategy* strategy);

   /**
  *  @brief get bool value for robotToPackage
  */
   bool GetRobotToPackage();
   /**
  *  @brief get bool value for robotToCustomer
  */
	bool GetRobotToCustomer();

  /**
 *  @brief get bool value for robotHasPackage
 */
	bool GetRobotHasPackage();

  /**
 *  @brief get bool value for robotfinished
 */
   bool GetRobotfinished();

   /**
   *  @brief set bool value for robotToPackage
   */
   void SetRobotToPackage(bool b);
   /**
  *  @brief sets up bool value for robotToCustomer
  */
	void SetRobotToCustomer(bool b);
  /**
 *  @brief sets up the bool value for robotHasPackage
 */
	void SetRobotHasPackage(bool b);
  /**
 *  @brief sets up bool value for robotfinished
 */
   void SetRobotfinished(bool b);
   /**
  *  @brief resets bool values for robotfinished, robotToPackage, robotToCustomer, bool robotHasPackage to false
  */
   void Reset();
   /**
  *  @brief decorates robot
  */
   virtual void decorate();

  private:
   Battery* battery;
   Package* package;
   IStrategy* strategy;
   bool batteryDepleted;
   bool deliver;
   std::vector<std::vector<float>> routeOne;
   std::vector<std::vector<float>> routeTwo;
   int index;
   bool hasPackage;
   float speed;
   bool robotToPackage;
	bool robotToCustomer;
	bool robotHasPackage;
   bool robotfinished;
};

}

#endif //Robot_H_
