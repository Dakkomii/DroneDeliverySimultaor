/**
 *@file entity_base.h
 */
#ifndef ENTITY_BASE_H_
#define ENTITY_BASE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/facade/delivery_system.h>

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The base class for creating entities. This is a pure abstract class as
 * contains a pure virtual function.
 *
 * This class can be used as the base for all entities in the delivery system.
 * The overall design is up to you (the student), but all entities must implement
 * the IEntity interface.
 *
 * See the documentation for IEntity for more information
 */
class EntityBase : public IEntity {
 public:
  virtual ~EntityBase() {}

 /**
  *  @brief return the details information associated with the entity
  */
  const picojson::object& GetDetails() { return details_; }

  /**
  *  @brief sets a unique Id number for the entity
  */
  void SetId(int id){
    id_ = id;
  }

  /**
  *  @brief Returns objects's ID
  */
  int GetId() const{return id_;}

  /**
  *  @brief This function returns objets name
  */
  const std::string& GetName(){return name;}

  /**
  *  @brief Returns the position of the object
  */
  const std::vector<float>& GetPosition() const{return pos;}

  /**
  *  @brief Returns the direction of the customer
  */
  const std::vector<float>& GetDirection() const{return direction;}

  /**
  *  @brief This function should return the package's radius
  */
  float GetRadius() const{ return radius;}

  /**
  *  @brief Returns the customer's version
  */
  int GetVersion() const{return version;}

  /**
  *  @brief Return a bool value to indicate if dynamic or static
  */
  bool IsDynamic() const{return IsDy;}

  /**
  *  @brief a pure virtual method to decorate an entity
  */
  virtual void decorate() = 0;

 protected:
  picojson::object details_;
  int id_;
  std::string name;
  std::vector<float> pos;
  std::vector<float> direction;
  float radius;
  int version;
  bool IsDy;
};

}  // namespace csci3081


#endif  // ENTITY_BASE_H_
