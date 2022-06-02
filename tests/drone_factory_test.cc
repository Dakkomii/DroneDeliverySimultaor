#include "gtest/gtest.h"
#include "include/drone.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_simulation.h"
#include <EntityProject/entity.h>
#include "include/json_helper.h"
#include "composite_factory.h"
#include "drone_factory.h"


#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class DroneFactoryTest : public ::testing::Test {
    protected:
  virtual void SetUp() {
    system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));
    Cfact = new DroneFactory();

  }
  virtual void TearDown() {}

  IDeliverySystem* system;
  DroneFactory* Cfact;

};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
//testing constructor and testing AddFactory methods

TEST_F(DroneFactoryTest, CompositeCreateEntityTest){

    picojson::object obj = JsonHelper::CreateJsonObject();
    JsonHelper::AddStringToJsonObject(obj, "type", "drone");
    JsonHelper::AddStringToJsonObject(obj, "name", "drone");
    JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
    JsonHelper::AddFloatToJsonObject(obj, "ID", 1);
    JsonHelper::AddFloatToJsonObject(obj, "version", 0);
    JsonHelper::AddFloatToJsonObject(obj, "battery", 10000);
    std::vector<float> position_to_add;
    position_to_add.push_back(498.292);
    position_to_add.push_back(253.883);
    position_to_add.push_back(-228.623);
    JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
    std::vector<float> direction_to_add;
    direction_to_add.push_back(1);
    direction_to_add.push_back(0);
    direction_to_add.push_back(0);
    JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
    IEntity* entity = system->CreateEntity(obj);

    Cfact->CreateEntity(obj);

    Drone drone(position_to_add, direction_to_add, obj);
    obj = drone.GetDetails();
	std::string name;
    name = JsonHelper::GetString(obj, "name");
    

    EXPECT_EQ(name, "drone");
}
}