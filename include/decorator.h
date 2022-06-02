/**
 *@file entity_base.h
 */
#ifndef DECORATOR_H_
#define DECORATOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "include/entity_base.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The base class for creating decoraters.
 *
 * This class can be used as the base decorater for all entities in the delivery system.
 * This will allow the enttities to be colored whatever the class that inherits off of Decorator colors them. In
 * this project it would be either the color red or green.
 *
 */
class Decorator : public csci3081::EntityBase  {
 public:
   /**
  *  @brief Decorator constructor
  *  @param EntityBase object

  */
    Decorator(EntityBase* obj): object(obj){}

  /**
  *  @brief Decorator destructor
  */
    ~Decorator(){}

    /**
   *  @brief decorates an EntityBase object
   *  @param decorated EntityBase object
   */
    virtual void decorate(){object->decorate();}

 protected:
     EntityBase* object;
};

}
#endif
