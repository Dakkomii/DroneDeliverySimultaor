#include "gtest/gtest.h"
#include "include/drone.h"
#include "include/robot.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_simulation.h"
#include <EntityProject/entity.h>
#include "include/json_helper.h"
#include "composite_factory.h"
#include "decorator.h"
//#include "green_entity.h"


#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class GreenDecoratorTest : public ::testing::Test {
    protected:
  virtual void SetUp() {
    system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));
    obj = JsonHelper::CreateJsonObject();
    obj2 = JsonHelper::CreateJsonObject();
    JsonHelper::AddStringToJsonObject(obj, "type", "drone");
    JsonHelper::AddStringToJsonObject(obj, "name", "drone");
    JsonHelper::AddFloatToJsonObject(obj, "id", 1);
    JsonHelper::AddFloatToJsonObject(obj, "version", 0);
    JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
    //std::vector<float> position_to_add;
    position_to_add.push_back(498.292);
    position_to_add.push_back(253.883);
    position_to_add.push_back(-228.623);
    JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
    //std::vector<float> direction_to_add;
    direction_to_add.push_back(1);
    direction_to_add.push_back(0);
    direction_to_add.push_back(0);
    JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
    IEntity* entity = system->CreateEntity(obj);

    drone = new Drone(position_to_add, direction_to_add, obj);

    JsonHelper::AddStringToJsonObject(obj2, "type", "robot");
    JsonHelper::AddStringToJsonObject(obj2, "name", "robot");
    JsonHelper::AddFloatToJsonObject(obj2, "id", 4);
    JsonHelper::AddFloatToJsonObject(obj2, "version", 0);
    JsonHelper::AddFloatToJsonObject(obj2, "radius", 1.0);
    //std::vector<float> position_to_add;
    position_to_add.push_back(498.292);
    position_to_add.push_back(253.883);
    position_to_add.push_back(-228.623);
    JsonHelper::AddStdFloatVectorToJsonObject(obj2, "position", position_to_add);
    //std::vector<float> direction_to_add;
    direction_to_add.push_back(1);
    direction_to_add.push_back(0);
    direction_to_add.push_back(0);
    JsonHelper::AddStdFloatVectorToJsonObject(obj2, "direction", direction_to_add);
    IEntity* entity2 = system->CreateEntity(obj2);

    robot = new Robot(position_to_add, direction_to_add, obj2);
  }
  virtual void TearDown() {}

  IDeliverySystem* system;
  Drone* drone;
  Robot* robot;
  std::vector<float> direction_to_add;
  std::vector<float> position_to_add;
  picojson::object obj;
  picojson::object obj2;


};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
//testing constructor and testing AddFactory methods

TEST_F(GreenDecoratorTest, GreenDecoratorTest){
    drone->decorate();
    EntityBase* greenDrone = new GreenEntity(drone);
    greenDrone->decorate();

    obj = greenDrone->GetDetails();
    EXPECT_EQ(JsonHelper::GetString(obj, "color"), "0x68F04D");


    robot->decorate();
    EntityBase* greenRobot = new GreenEntity(robot);
    greenRobot->decorate();

    obj2 = greenRobot->GetDetails();
    EXPECT_EQ(JsonHelper::GetString(obj2, "color"), "0x68F04D");


}
}
