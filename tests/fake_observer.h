/**
 *@file entity_base.h
 */
#ifndef FAKE_OBSERVER_H_
#define FAKE_OBSERVER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "EntityProject/entity_observer.h"
#include "EntityProject/entity.h"


namespace entity_project {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The base class for creating entities.
 *
 * This class can be used as the base for all entities in the delivery system.
 * The overall design is up to you (the student), but all entities must implement
 * the IEntity interface.
 *
 * See the documentation for IEntity for more information
 */
class FakeObserver : public entity_project::IEntityObserver  {
 public:
    FakeObserver(){}
    virtual ~FakeObserver(){}

    virtual void OnEvent(const picojson::value& event, const IEntity& entity){
      thisevent = event;
      thisentity = entity;
    }

 private:
   const picojson::value& thisevent;
   const IEntity& thisentity;

};

}
#endif
