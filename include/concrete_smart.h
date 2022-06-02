/**
 * @file concrete_smart.h
 */
#ifndef CONCRETE_SMART_H_
#define CONCRETE_SMART_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/facade/delivery_system.h>
#include <vector>
#include <string>
#include "IStrategy.h"
#include "include/vector3d.h"
#include "EntityProject/graph.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the interface for the strategy pattern
 *
 *
 */
class ConcreteSmart : public csci3081::IStrategy {
 public:
  
  /**
  *  @brief Concrete_smart constructor
  */
  ConcreteSmart();

  /**
  *  @brief Concrete_smart destructor
  */
  ~ConcreteSmart();

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
  *  @brief Sets graphs variable to graph which is an IGraph pointer to set up routes
  */
  void SetGraph(const IGraph* graph);

  /**
  *  @brief Get the path from the startegy and set it into the member variable routeOne
  */
  std::vector<std::vector<float>> GetRouteOneSmart();

  /**
  *  @brief Get the path from the startegy and set it into the member variable TwoOne
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
  float speed; 
  int routeIndex;
  bool pickedPackage;
  bool endOfRouteOne;
  bool endOfRouteTwo;
  const IGraph* graphs;

  };
}
#endif