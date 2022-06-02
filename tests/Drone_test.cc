#include "gtest/gtest.h"
#include "include/drone.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_simulation.h"
#include <EntityProject/entity.h>
#include "include/json_helper.h"


#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class DroneTest : public ::testing::Test {
    protected:
  virtual void SetUp() {
    system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));
    system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));
    obj = JsonHelper::CreateJsonObject();
    JsonHelper::AddStringToJsonObject(obj, "type", "customer");
    JsonHelper::AddStringToJsonObject(obj, "name", "customer");
    JsonHelper::AddFloatToJsonObject(obj, "id", 2);
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
    drone1 = new Drone(position_to_add, direction_to_add, obj);
  }
  virtual void TearDown() {}

  IDeliverySystem* system;
  Drone* drone1;
  std::vector<float> direction_to_add;
  std::vector<float> position_to_add;
  picojson::object obj;
  
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(DroneTest, DroneConstructorTest){

    std::vector<float> position = drone1->GetPosition();
    std::vector<float> direction = drone1->GetDirection();

    for (int i = 0; i < position_to_add.size(); i++){
        EXPECT_EQ(position_to_add.at(i), position.at(i));
    }
    
    for (int i = 0; i < direction_to_add.size(); i++){
        EXPECT_EQ(direction_to_add.at(i), direction.at(i));
    }

}

TEST_F(DroneTest, DroneGetNameTest){
    std::string name = JsonHelper::GetString(obj, "name");
    std::string name2 = drone1->GetName();

    EXPECT_EQ(name, name2) << name << " " << name2;
}

TEST_F(DroneTest, DroneGetRadiusTest){  
    float rad = JsonHelper::GetDouble(obj, "radius");

    EXPECT_EQ(rad, drone1->GetRadius());
}

TEST_F(DroneTest, DroneGetIdTest){
    int id = JsonHelper::GetDouble(obj, "id");

    EXPECT_EQ(id, drone1->GetId());
}

TEST_F(DroneTest, DroneGetVersionTest){
    int id = JsonHelper::GetDouble(obj, "version");

    EXPECT_EQ(id, drone1->GetVersion());
}

TEST_F(DroneTest, DroneIsDynamicTest){
    bool x = drone1->IsDynamic();
    EXPECT_EQ(x, true);
}

//testing setIndex and GetIndex
TEST_F(DroneTest, IndexTest){
    drone1->SetIndex(10);
    int x = drone1->GetIndex();

    EXPECT_EQ(x, 10);
}

//testing SetDelivering and IsDelivering
TEST_F(DroneTest, DeliveringTest){

    drone1->SetDelivering(true);
    bool x = drone1->IsDelivering();

    EXPECT_EQ(x, true);
}

TEST_F(DroneTest, hasPackageTest){
    drone1->SetPackage(true);
    bool x = drone1->GetPackage();

    EXPECT_EQ(x, true);
}
TEST_F(DroneTest, DroneDecorationTest){
    drone1->decorate();
    EntityBase* redCustomer = new RedEntity(drone1);
    redCustomer->decorate();

    obj = redCustomer->GetDetails();
     EXPECT_EQ(JsonHelper::GetString(obj, "color"), "0xFF0000");
}

TEST_F(DroneTest, GetSetToPackageTest){
    drone1->SetDroneToPackage(true);
    bool x = drone1->GetDroneToPackage();

    EXPECT_EQ(x, true);
}
TEST_F(DroneTest, GetSetToCustomerTest){
    drone1->SetDroneToCustomer(true);
    bool x = drone1->GetDroneToCustomer();

    EXPECT_EQ(x, true);
}
TEST_F(DroneTest, GetSetHasPackage){
    drone1->SetDroneHasPackage(true);
    bool x = drone1->GetDroneHasPackage();

    EXPECT_EQ(x, true);
}
TEST_F(DroneTest, GetSetDronefinished){
    drone1->SetDronefinished(true);
    bool x = drone1->GetDronefinished();

    EXPECT_EQ(x, true);
}
}