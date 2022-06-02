/**
 *@file entity_base.h
 */
#ifndef RED_ENTITY_H_
#define RED_ENTITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "decorator.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
  * @brief The base class for creating red entities.
  *
  * This class can be used as a red decorator/color for all entities in the delivery system.
  * This will allow the enttities to be colored red
  *
  */
class RedEntity : public csci3081::Decorator  {
 public:
   /**
  *  @brief RedEntity constructor
  *  @param EntityBase object

  */
    RedEntity(EntityBase* obj): Decorator(obj){}
    /**
    *  @brief RedEntity destructor
    */
    ~RedEntity(){}

    /**
   *  @brief decorates an EntityBase object with the color red by putting red hex value for color value in picojson object

   */
    virtual void decorate(){
        Decorator::decorate();
        details_["color"] = picojson::value("0xFF0000");
        }




};

}
#endif
