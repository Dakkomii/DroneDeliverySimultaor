#include "gtest/gtest.h"
#include "include/customer.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_simulation.h"
#include <EntityProject/entity.h>
#include "include/json_helper.h"


#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class CustomerTest : public ::testing::Test {
    protected:
  virtual void SetUp() {
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
    customer1 = new Customer(position_to_add, direction_to_add, obj);
  }
  virtual void TearDown() {}

  IDeliverySystem* system;
  Customer* customer1;
  std::vector<float> direction_to_add;
  std::vector<float> position_to_add;
  picojson::object obj;
  
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(CustomerTest, CustomerConstructorTest){

    std::vector<float> position = customer1->GetPosition();
    std::vector<float> direction = customer1->GetDirection();

    for (int i = 0; i < position_to_add.size(); i++){
        EXPECT_EQ(position_to_add.at(i), position.at(i));
    }
    
    for (int i = 0; i < direction_to_add.size(); i++){
        EXPECT_EQ(direction_to_add.at(i), direction.at(i));
    }

}
TEST_F(CustomerTest, CustomerGetNameTest){

    std::string name = JsonHelper::GetString(obj, "name");
    std::string name2 = customer1->GetName();

    EXPECT_EQ(name, name2) << name << " " << name2;
    
}

TEST_F(CustomerTest, CustomerGetRadiusTest){

    float radius = JsonHelper::GetDouble(obj, "radius");

    EXPECT_EQ(radius, customer1->GetRadius());

}

TEST_F(CustomerTest, CustomerGetIdTest){

    int id = JsonHelper::GetDouble(obj, "id");

    EXPECT_EQ(id, customer1->GetId());

}

TEST_F(CustomerTest, CustomerGetVersionTest){

    int id = JsonHelper::GetDouble(obj, "version");

    EXPECT_EQ(id, customer1->GetVersion());

}

TEST_F(CustomerTest, CustomerGetlocationTest){

    std::vector<float> position = customer1->GetLocation();

    for (int i = 0; i < position_to_add.size(); i++){
        EXPECT_EQ(position_to_add.at(i), position.at(i));
    }

}
TEST_F(CustomerTest, CustomerDecorationTest){
    customer1->decorate();
    EntityBase* redCustomer = new RedEntity(customer1);
    redCustomer->decorate();

    obj = redCustomer->GetDetails();
     EXPECT_EQ(JsonHelper::GetString(obj, "color"), "0xFF0000");
}
}