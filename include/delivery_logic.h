/**
 * @file delivery_logic.h
 */
#ifndef DELIVERY_LOGIC_H_
#define DELIVERY_LOGIC_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <vector>
#include <string>
#include "composite_factory.h"
#include "EntityProject/graph.h"
#include "IStrategy.h"
#include "concrete_smart.h"
#include "concrete_beeline.h"
#include "concrete_parabolic.h"
#include "red_entity.h"
#include "decorator.h"
#include "green_entity.h"



namespace csci3081 {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the delivery_logic header file. The delivery_logic is in aid of the deliverysimulation.cc file as the
 * functions that are called in their, directly call the functions here to perform the bulk of the simulation.
 *
 *
 */

class DeliveryLogic{
 public:
    /**
   *  @brief   DeliveryLogic constructor
   */
    DeliveryLogic();
     /**
    *  @brief   DeliveryLogic destructor
    */
    ~DeliveryLogic();
    /**
   *  @brief schedules a delivery for an entity to pick up a package and delivery it to the customer
   *  @param package to be deliveried
   *  @param customer that has to have the package delivered to
   */
    void schedule(IEntity* package, IEntity* customer);

    /**
   *  @brief moves the drone or robot to pick up packages and make deliveries to customers. It will move in either a smart,
   * beeline or parabolic way.
   *  @param dt is amount of time the update call should advance the simulation by
   */

    void move(float dt);

    /**
   *  @brief a method that aids in sending notfications to the observers regarding the entities deliviered,moving,picked up
   *  status. In this method the onEvent() method from the IEntityObserver class is called on the observers.
   *  @param value is the notification string value
   *  @param entity is the Entity that is observer needs to be notified about
   *  @param path is used to print out path lines for the drone/robot when they are moving from one point to another

   */

    void SendNotification(std::string value,  IEntity* entity, std::vector<std::vector<float>> path);

    /**
   *  @brief initilizes all the entities, packages and graphs .
   *  @param entities are either drone, robot, package, or customer
   *  @param observers are the web scene viewers also known as the users viewing the simulation
   *  @param graph is the graph for the smart path.

   */
    void setUp(std::vector<IEntity*> entities, std::vector<IEntityObserver*> observers, const IGraph* graph);

 private:
    std::vector<IEntity*> entities_;
    std::vector<Package*> packages;

    IStrategy* strategy;
    std::vector<IEntityObserver*> observers;
    const IGraph* graphs;


};
}

#endif
