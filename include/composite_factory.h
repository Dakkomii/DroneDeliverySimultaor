/**
 * @file composite_factory.h
 */

#ifndef COMPOSITE_FACTORY_H_
#define COMPOSITE_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "EntityProject/entity_factory.h"
#include "entity_base.h"
#include "json_helper.h"
#include "drone_factory.h"
#include "customer_factory.h"
#include "package_factory.h"
#include "robot_factory.h"


namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief composite_factory. Delegates creation of objects to Dron, 
 * Package and Customer factories
 *
 * 
 */

class CompositeFactory : public entity_project::IEntityFactory {
    public:
    
    /**
   *  @brief CompositeFactory construcor
   * 
   */
    CompositeFactory();
    
    /**
   *  @brief CompositeFactory destructor
   * 
   */
    ~CompositeFactory();

    /**
   *  @brief Add the correct component (i.e. entity) factory 
   * to a list of factories(use std::vector) that the Composite factory holds.
   */
    void AddFactory(entity_project::IEntityFactory*);

    /**
   *  @brief Loop through each of the factories until the correct factory 
   * successfully creates and returns a new Entity based on the parameters.
   * @param val is a picojson object that contains all object information
   */
    IEntity* CreateEntity(const picojson::object& val);

    /**
   *  @brief Return the factories vector. Used for testing.
   */
    std::vector<IEntityFactory*> GetFactories();
    
    private:
    
    std::vector<IEntityFactory*> factories;
};

}


#endif