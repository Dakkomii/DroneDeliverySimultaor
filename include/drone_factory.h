/**
 * @file drone_factory.h
 */

#ifndef DRONE_FACTORY_H_
#define DRONE_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "EntityProject/entity_factory.h"
#include "drone.h"


namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the drone_factory header file. Creates Dron objetcs
 *
 * 
 */

class DroneFactory : public entity_project::IEntityFactory {
    public:
    /**
   *  @brief DroneFactory constructor
   */
    DroneFactory();

    /**
   *  @brief DroneFactory destructor
   */
    ~DroneFactory();
    /**
   *  @brief Creates a drone entity or returns null
   * @param val picojason object that contains all object details
   */
    IEntity* CreateEntity(const picojson::object& val) override;

};

}

#endif