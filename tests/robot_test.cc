#include "gtest/gtest.h"
#include "include/robot.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_simulation.h"
#include <EntityProject/entity.h>
#include "include/json_helper.h"


#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class RobotTest : public ::testing::Test {
    protected:
  virtual void SetUp() {
    system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));
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
    robot1 = new Robot(position_to_add, direction_to_add, obj);
  }
  virtual void TearDown() {}

  IDeliverySystem* system;
  Robot* robot1;
  std::vector<float> direction_to_add;
  std::vector<float> position_to_add;
  picojson::object obj;
  
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(RobotTest, RobotConstructorTest){
    std::vector<float> position = robot1->GetPosition();
    std::vector<float> direction = robot1->GetDirection();

    for (int i = 0; i < position_to_add.size(); i++){
        EXPECT_EQ(position_to_add.at(i), position.at(i));
    }
    
    for (int i = 0; i < direction_to_add.size(); i++){
        EXPECT_EQ(direction_to_add.at(i), direction.at(i));
    }

}

TEST_F(RobotTest, RobotGetNameTest){

    std::string name = JsonHelper::GetString(obj, "name");
    std::string name2 = robot1->GetName();

    EXPECT_EQ(name, name2) << name << " " << name2;

}

TEST_F(RobotTest, RobotGetRadiusTest){
    float rad = JsonHelper::GetDouble(obj, "radius");

    EXPECT_EQ(rad, robot1->GetRadius());

}

TEST_F(RobotTest, RobotGetIdTest){
    int id = JsonHelper::GetDouble(obj, "id");

    EXPECT_EQ(id, robot1->GetId());

}

TEST_F(RobotTest, RobotGetVersionTest){
    int id = JsonHelper::GetDouble(obj, "version");

    EXPECT_EQ(id, robot1->GetVersion());

}

TEST_F(RobotTest, RobotIsDynamicTest){
    bool x = robot1->IsDynamic();

    EXPECT_EQ(x, true);

}

//testing setIndex and GetIndex
TEST_F(RobotTest, IndexTest){

    robot1->SetIndex(10);
    int x = robot1->GetIndex();

    EXPECT_EQ(x, 10);

}

//testing SetDelivering and IsDelivering
TEST_F(RobotTest, DeliveringTest){
    robot1->SetDelivering(true);
    bool x = robot1->IsDelivering();

    EXPECT_EQ(x, true);

}

TEST_F(RobotTest, hasPackageTest){
    robot1->SetPackage(true);
    bool x = robot1->GetPackage();

    EXPECT_EQ(x, true);

}
TEST_F(RobotTest, RobotDecorationTest){
    robot1->decorate();
    EntityBase* redRobot = new RedEntity(robot1);
    redRobot->decorate();

    obj = redRobot->GetDetails();
     EXPECT_EQ(JsonHelper::GetString(obj, "color"), "0xFF0000");
}
TEST_F(RobotTest, GetSetToPackageTest){
    robot1->SetRobotToPackage(true);
    bool x = robot1->GetRobotToPackage();

    EXPECT_EQ(x, true);
}
TEST_F(RobotTest, GetSetToCustomerTest){
    robot1->SetRobotToCustomer(true);
    bool x = robot1->GetRobotToCustomer();

    EXPECT_EQ(x, true);
}
TEST_F(RobotTest, GetSetHasPackage){
    robot1->SetRobotHasPackage(true);
    bool x = robot1->GetRobotHasPackage();

    EXPECT_EQ(x, true);
}
TEST_F(RobotTest, GetSetDronefinished){
    robot1->SetRobotfinished(true);
    bool x = robot1->GetRobotfinished();

    EXPECT_EQ(x, true);
}
}