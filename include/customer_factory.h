/**
 * @file customer_factory.h
 */

#ifndef CUSTOMER_FACTORY_H_
#define CUSTOMER_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "EntityProject/entity_factory.h"
#include "customer.h"


namespace csci3081 {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the customer_factory header file
 * this factory creates customer objects or return null
 *
 * 
 */

class CustomerFactory : public entity_project::IEntityFactory {
    public:
    /**
   *  @brief CustomerFactory constructor
   */
    CustomerFactory();

    /**
   *  @brief CustomerFactory destructor
   */
    ~CustomerFactory();
    /**
   *  @brief Creates a customer object if type is customer otherwise returns null
   * @param val is a picojson object that contains all object information
   */
    IEntity* CreateEntity(const picojson::object& val);

};

}


#endif