/**
 *@file entity_base.h
 */
#ifndef GREEN_ENTITY_H_
#define GREEND_ENTITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "decorator.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
  * @brief The base class for creating green entities.
  *
  * This class can be used as a green decorator/color for all entities in the delivery system.
  * This will allow the enttities to be colored green
  *
  */
class GreenEntity : public csci3081::Decorator  {
 public:
   /**
  *  @brief GreenEntity constructor
  *  @param EntityBase object

  */
    GreenEntity(EntityBase* obj): Decorator(obj){}
  /**
  *  @brief GreenEntity destructor
  */
    ~GreenEntity(){}

    /**
   *  @brief decorates an EntityBase object with the color green by putting green hex value for color value in picojson object

   */
    virtual void decorate(){
        Decorator::decorate();
        details_["color"] = picojson::value("0x68F04D");
        }



};

}
#endif
