#include "gtest/gtest.h"
#include "include/concrete_beeline.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_simulation.h"
#include <EntityProject/entity.h>
#include "include/json_helper.h"

#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class BeelineTest : public ::testing::Test {
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
    beeline = new ConcreteBeeline();

  }
    Drone* drone;
    Customer* customer;
    Package* package;
    ConcreteBeeline* beeline;

  virtual void TearDown() {
     Drone* drone;
    Customer* customer;
    Package* package;
    ConcreteBeeline* beeline;
  }

  IDeliverySystem* system;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

/*
this test uses:
beeline->getIndex()
beeline->HasPackage()
beeline->GetEndOfRouteOne()
beeline->GetEndOfRouteTwo()
*/
TEST_F(BeelineTest, beelineSetUpTest){
    std::vector<float> Dpos = drone->GetPosition();
    std::vector<float> Ppos = package->GetPosition();
    std::vector<float> Cpos = customer->GetPosition();

    beeline->SetUp(Dpos,Ppos,Cpos);

    int index = 1;
    bool pickedP = false;
    bool endOfOne = false;
    bool endOfTwo = false;
    std::vector<float> dir = {1,1,1};
    std::vector<float> direction = beeline->GetDirection();

    EXPECT_EQ(beeline->getIndex(), index);
    EXPECT_EQ(beeline->HasPackage(), pickedP);
    EXPECT_EQ(beeline->GetEndOfRouteOne(), endOfOne);
    EXPECT_EQ(beeline->GetEndOfRouteTwo(), endOfTwo);

    for (int i = 0; i < dir.size(); i++){
        EXPECT_EQ(dir.at(i), direction.at(i));
    }

}

TEST_F(BeelineTest, beelineSetIndexTest){
    std::vector<float> Dpos = drone->GetPosition();
    std::vector<float> Ppos = package->GetPosition();
    std::vector<float> Cpos = customer->GetPosition();

    beeline->SetUp(Dpos,Ppos,Cpos);

    int index = 3;
    beeline->SetIndex(index);

    EXPECT_EQ(beeline->getIndex(), index);

}

TEST_F(BeelineTest, beelineSetHasPackageTest){
    std::vector<float> Dpos = drone->GetPosition();
    std::vector<float> Ppos = package->GetPosition();
    std::vector<float> Cpos = customer->GetPosition();

    beeline->SetUp(Dpos,Ppos,Cpos);

    bool p = true;
    beeline->SetHasPackage(p);

    EXPECT_EQ(beeline->HasPackage(), p);

}

TEST_F(BeelineTest, beelineSetDirectionTest){
    std::vector<float> Dpos = drone->GetPosition();
    std::vector<float> Ppos = package->GetPosition();
    std::vector<float> Cpos = customer->GetPosition();

    beeline->SetUp(Dpos,Ppos,Cpos);

    std::vector<float> dir = {10,10,10};
    beeline->SetDirection(dir);
    std::vector<float> direction = beeline->GetDirection();
    for (int i = 0; i < dir.size(); i++){
        EXPECT_EQ(dir.at(i), direction.at(i));
    }

}

}
