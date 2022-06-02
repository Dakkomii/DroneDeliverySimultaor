#include "gtest/gtest.h"
#include "include/concrete_parabolic.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_simulation.h"
#include <EntityProject/entity.h>
#include "include/json_helper.h"

#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class ParabolicTest : public ::testing::Test {
    protected:
  virtual void SetUp() {
    system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));

    picojson::object obj = JsonHelper::CreateJsonObject();
    JsonHelper::AddStringToJsonObject(obj, "type", "drone");
    JsonHelper::AddFloatToJsonObject(obj, "speed", 10.0);
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

    drone = new Drone(position_to_add, direction_to_add, obj);
    customer = new Customer(position_to_add, direction_to_add, obj);
    package = new Package(position_to_add, direction_to_add, obj);
    parabolic = new ConcreteParabolic();

  }
    Drone* drone;
    Customer* customer;
    Package* package;
    ConcreteParabolic* parabolic;

  virtual void TearDown() {
     Drone* drone;
    Customer* customer;
    Package* package;
    ConcreteParabolic* parabolic; 
  }

  IDeliverySystem* system;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

/*
this test uses:
getIndex()
HasPackage()
GetEndOfRouteOne()
GetEndOfRouteTwo()
*/
TEST_F(ParabolicTest, parabolicSetUpTest){
    std::vector<float> Dpos = drone->GetPosition();
    std::vector<float> Ppos = package->GetPosition();
    std::vector<float> Cpos = customer->GetPosition();

    parabolic->SetUp(Dpos,Ppos,Cpos);

    int index = 1;
    bool pickedP = false;
    bool endOfOne = false;
    bool endOfTwo = false;
    std::vector<float> dir = {1,1,1};
    std::vector<float> direction = parabolic->GetDirection();

    EXPECT_EQ(parabolic->getIndex(), index);
    EXPECT_EQ(parabolic->HasPackage(), pickedP);
    EXPECT_EQ(parabolic->GetEndOfRouteOne(), endOfOne);
    EXPECT_EQ(parabolic->GetEndOfRouteTwo(), endOfTwo);

    for (int i = 0; i < dir.size(); i++){
        EXPECT_EQ(dir.at(i), direction.at(i));
    }

}

TEST_F(ParabolicTest, parabolicSetIndexTest){
    std::vector<float> Dpos = drone->GetPosition();
    std::vector<float> Ppos = package->GetPosition();
    std::vector<float> Cpos = customer->GetPosition();

    parabolic->SetUp(Dpos,Ppos,Cpos);

    int index = 3;
    parabolic->SetIndex(index);

    EXPECT_EQ(parabolic->getIndex(), index);

}

TEST_F(ParabolicTest, parabolicSetHasPackageTest){
    std::vector<float> Dpos = drone->GetPosition();
    std::vector<float> Ppos = package->GetPosition();
    std::vector<float> Cpos = customer->GetPosition();

    parabolic->SetUp(Dpos,Ppos,Cpos);

    bool p = true;
    parabolic->SetHasPackage(p);

    EXPECT_EQ(parabolic->HasPackage(), p);

}

TEST_F(ParabolicTest, parabolicSetDirectionTest){
    std::vector<float> Dpos = drone->GetPosition();
    std::vector<float> Ppos = package->GetPosition();
    std::vector<float> Cpos = customer->GetPosition();

    parabolic->SetUp(Dpos,Ppos,Cpos);

    std::vector<float> dir = {10,10,10};
    parabolic->SetDirection(dir);
    std::vector<float> direction = parabolic->GetDirection();
    for (int i = 0; i < dir.size(); i++){
        EXPECT_EQ(dir.at(i), direction.at(i));
    }

}

}