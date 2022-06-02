/**
 * @file IStrategy.h
 */
#ifndef ISTRATEGY_H_
#define ISTRATEGY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/facade/delivery_system.h>
#include <vector>
#include <string>

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the interface for the strategy pattern
 *
 *
 */
class IStrategy {
 public:

    /**
  *  @brief IStrategy destructor
  */
    virtual ~IStrategy() {}

    /**
  *  @brief Sets up all the member variables that are necessary for the strategy
  * @param DLocation float vector of drone position
  * @param PLocation Package position
  * @param CLocation Customer position
  */
    virtual void SetUp(std::vector<float> DLocation, std::vector<float> PLocation, std::vector<float> CLocation) = 0;

    /**
  *  @brief This method perform the strategy and moves the drone
  */
    virtual std::vector<float> move(float dt, float speed, float radius) = 0;

    /**
  *  @brief Return true if the end of route from drone to package is reached false otherwise
  */
    virtual bool GetEndOfRouteOne() = 0;

    /**
  *  @brief Return true if the end of route from package/drone to customer is reached false otherwise
  */
    virtual bool GetEndOfRouteTwo() = 0;

    /**
  *  @brief Return true if the drone got the package
  */
    virtual bool HasPackage() = 0;

    /**
  *  @brief Returns drone direction vector
  */
    virtual std::vector<float> GetDirection() = 0;

  /**
  *  @brief Get the path from the startegy and set it into the member variable routeOne
  */
    virtual std::vector<std::vector<float>> GetRouteOneSmart() = 0;

  /**
  *  @brief Get the path from the startegy and set it into the member variable routeTwo
  */
    virtual std::vector<std::vector<float>> GetRouteTwoSmart() = 0;


};
}
#endif  //ISTRATEGY_H_