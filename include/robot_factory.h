/**
 * @file robot_factory.h
 */

#ifndef ROBOT_FACTORY_H_
#define ROBOT_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "EntityProject/entity_factory.h"
#include "robot.h"


namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the robot_factory header file. Creates robot objetcs
 *
 * 
 */

class RobotFactory : public entity_project::IEntityFactory {
    public:
    /**
   *  @brief Robot Factory constructor
   */
    RobotFactory();

    /**
   *  @brief Robot Factory destructor
   */
    ~RobotFactory();
    /**
   *  @brief Creates a robot entity or returns null
   * @param val picojason object that contains all object details
   */
    IEntity* CreateEntity(const picojson::object& val) override;

};
}


#endif