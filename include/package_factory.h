/**
 * @file package_factory.h
 */

#ifndef PACKAGE_FACTORY_H_
#define PACKAGE_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "EntityProject/entity_factory.h"
#include "package.h"


namespace csci3081 {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Creates Package entities
 *
 * 
 */

class PackageFactory : public entity_project::IEntityFactory {
    public:

    /**
   *  @brief PackageFactory constructor
   */
    PackageFactory();

    /**
   *  @brief PackageFactory destructor
   */
    ~PackageFactory();
    /**
   *  @brief Creates an entity if the entity is type package otherwise returns null
   * @param val is a picojson object that contains all object information
   */
    IEntity* CreateEntity(const picojson::object& val);

};

}


#endif