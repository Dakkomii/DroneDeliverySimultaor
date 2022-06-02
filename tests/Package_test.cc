#include "gtest/gtest.h"
#include "include/package.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_simulation.h"
#include <EntityProject/entity.h>
#include "include/json_helper.h"
#include "include/customer.h"


#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class PackageTest : public ::testing::Test {
    protected:
  virtual void SetUp() {
    system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));
  }
  virtual void TearDown() {}

  IDeliverySystem* system;
  
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(PackageTest, PackageConstructorTest){

    picojson::object obj = JsonHelper::CreateJsonObject();
    JsonHelper::AddStringToJsonObject(obj, "type", "package");
    JsonHelper::AddStringToJsonObject(obj, "name", "package");
    JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
    JsonHelper::AddFloatToJsonObject(obj, "ID", 3);
    JsonHelper::AddFloatToJsonObject(obj, "version", 0);
    JsonHelper::AddFloatToJsonObject(obj, "weight", 100.0);
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

    
    Package package1(position_to_add, direction_to_add, obj);

    std::vector<float> position = package1.GetPosition();
    std::vector<float> direction = package1.GetDirection();

    for (int i = 0; i < position_to_add.size(); i++){
        EXPECT_EQ(position_to_add.at(i), position.at(i));
    }
    
    for (int i = 0; i < direction_to_add.size(); i++){
        EXPECT_EQ(direction_to_add.at(i), direction.at(i));
    }

}

TEST_F(PackageTest, PackageGetNameTest){

    picojson::object obj = JsonHelper::CreateJsonObject();
    JsonHelper::AddStringToJsonObject(obj, "type", "package");
    JsonHelper::AddStringToJsonObject(obj, "name", "package");
    JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
    JsonHelper::AddFloatToJsonObject(obj, "ID", 3);
    JsonHelper::AddFloatToJsonObject(obj, "version", 0);
    JsonHelper::AddFloatToJsonObject(obj, "weight", 100.0);
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

    
    Package package1(position_to_add, direction_to_add, obj);

    std::string name = JsonHelper::GetString(obj, "name");
    std::string name2 = package1.GetName();

    EXPECT_EQ(name, name2) << name << " " << name2;

}

TEST_F(PackageTest, PackageGetRadiusTest){

    picojson::object obj = JsonHelper::CreateJsonObject();
    JsonHelper::AddStringToJsonObject(obj, "type", "package");
    // JsonHelper::AddStringToJsonObject(obj, "name", "package");
    JsonHelper::AddFloatToJsonObject(obj, "radius", 1);
    // JsonHelper::AddFloatToJsonObject(obj, "ID", 3);
    // JsonHelper::AddFloatToJsonObject(obj, "version", 0);
    // JsonHelper::AddFloatToJsonObject(obj, "weight", 100.0);
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

    
    Package package1(position_to_add, direction_to_add, obj);

    //JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
    float radius = JsonHelper::GetDouble(obj, "radius");

    EXPECT_EQ(radius, package1.GetRadius());

}

TEST_F(PackageTest, PackageGetIdTest){

    picojson::object obj = JsonHelper::CreateJsonObject();
    JsonHelper::AddStringToJsonObject(obj, "type", "package");
    // JsonHelper::AddStringToJsonObject(obj, "name", "package");
    // JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
    JsonHelper::AddFloatToJsonObject(obj, "id", 3);
    // JsonHelper::AddFloatToJsonObject(obj, "version", 0);
    // JsonHelper::AddFloatToJsonObject(obj, "weight", 100.0);
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

    
    Package package1(position_to_add, direction_to_add, obj);

    //JsonHelper::AddFloatToJsonObject(obj, "ID", 3);

    int id = JsonHelper::GetDouble(obj, "id");

    EXPECT_EQ(id, package1.GetId());

}

TEST_F(PackageTest, PackageGetVersionTest){

    picojson::object obj = JsonHelper::CreateJsonObject();
    JsonHelper::AddStringToJsonObject(obj, "type", "package");
    JsonHelper::AddStringToJsonObject(obj, "name", "package");
    JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
    JsonHelper::AddFloatToJsonObject(obj, "ID", 3);
    JsonHelper::AddFloatToJsonObject(obj, "version", 0);
    JsonHelper::AddFloatToJsonObject(obj, "weight", 100.0);
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

    
    Package package1(position_to_add, direction_to_add, obj);

    //JsonHelper::AddFloatToJsonObject(obj, "version", 0);

    int id = JsonHelper::GetDouble(obj, "version");

    EXPECT_EQ(id, package1.GetVersion());

}

TEST_F(PackageTest, PackageIsDynamicTest){

    picojson::object obj = JsonHelper::CreateJsonObject();
    JsonHelper::AddStringToJsonObject(obj, "type", "package");
    JsonHelper::AddStringToJsonObject(obj, "name", "package");
    JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
    JsonHelper::AddFloatToJsonObject(obj, "ID", 3);
    JsonHelper::AddFloatToJsonObject(obj, "version", 0);
    JsonHelper::AddFloatToJsonObject(obj, "weight", 100.0);
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

    
    Package package1(position_to_add, direction_to_add, obj);

    bool x = package1.IsDynamic();

    EXPECT_EQ(x, false);
}

TEST_F(PackageTest, PackageGetWeightTest){

    picojson::object obj = JsonHelper::CreateJsonObject();
    JsonHelper::AddStringToJsonObject(obj, "type", "package");
    // JsonHelper::AddStringToJsonObject(obj, "name", "package");
    // JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
    // JsonHelper::AddFloatToJsonObject(obj, "ID", 3);
    // JsonHelper::AddFloatToJsonObject(obj, "version", 0);
    JsonHelper::AddFloatToJsonObject(obj, "weight", 100);
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

    
    
    Package package1(position_to_add, direction_to_add, obj);

    //JsonHelper::AddFloatToJsonObject(obj, "weight", 100.0);

    int w = JsonHelper::GetDouble(obj, "weight");

    EXPECT_EQ(w, package1.GetWeight());

}

TEST_F(PackageTest, PackageCustomerTest){

    picojson::object obj = JsonHelper::CreateJsonObject();
    JsonHelper::AddStringToJsonObject(obj, "type", "package");
    JsonHelper::AddStringToJsonObject(obj, "name", "package");
    JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
    //JsonHelper::AddFloatToJsonObject(obj, "ID", 3);
    JsonHelper::AddFloatToJsonObject(obj, "version", 0);
    JsonHelper::AddFloatToJsonObject(obj, "weight", 100.0);
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

    Customer *customer = new Customer(position_to_add, direction_to_add, obj);
    Package package1(position_to_add, direction_to_add, obj);

    package1.SetCustomer(customer);

    EXPECT_EQ(package1.GetCustomer(), customer);

}


}