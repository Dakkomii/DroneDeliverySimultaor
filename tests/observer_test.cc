// #include "gtest/gtest.h"
// #include "include/customer.h"
// #include "include/delivery_logic.h"
//
// #include <EntityProject/project_settings.h>
// #include "../include/delivery_simulation.h"
// #include <EntityProject/entity.h>
// #include "include/json_helper.h"
//
//
// #include <iostream>
//
// namespace csci3081 {
//
// using entity_project::IEntity;
//
// class ObserverTest : public ::testing::Test {
//     protected:
//   virtual void SetUp() {
//     system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));
//   }
//   virtual void TearDown() {}
//
//   IDeliverySystem* system;
//
// };
//
// /*******************************************************************************
//  * Test Cases
//  ******************************************************************************/
//
// TEST_F(ObserverTest, ObserverConstructorTest){
//
//     picojson::object obj = JsonHelper::CreateJsonObject();
//     JsonHelper::AddStringToJsonObject(obj, "type", "customer");
//     JsonHelper::AddStringToJsonObject(obj, "name", "customer");
//     JsonHelper::AddFloatToJsonObject(obj, "ID", 2);
//     JsonHelper::AddFloatToJsonObject(obj, "version", 0);
//     JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
//     std::vector<float> position_to_add;
//     position_to_add.push_back(498.292);
//     position_to_add.push_back(253.883);
//     position_to_add.push_back(-228.623);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
//     std::vector<float> direction_to_add;
//     direction_to_add.push_back(1);
//     direction_to_add.push_back(0);
//     direction_to_add.push_back(0);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
//     IEntity* entity = system->CreateEntity(obj);
//
//
//     Customer customer1(position_to_add, direction_to_add, obj);
//
//     std::vector<float> position = customer1.GetPosition();
//     std::vector<float> direction = customer1.GetDirection();
//
//     for (int i = 0; i < position_to_add.size(); i++){
//         EXPECT_EQ(position_to_add.at(i), position.at(i));
//     }
//
//     for (int i = 0; i < direction_to_add.size(); i++){
//         EXPECT_EQ(direction_to_add.at(i), direction.at(i));
//     }
//
// }
//
// TEST_F(CustomerTest, ObserverOnEvent){
//   DeliveryLogic* logic = new DeliveryLogic();
//   logic->AddObserver(observer);
//   //ogic->RemoveObserver();
//
//     picojson::object obj = JsonHelper::CreateJsonObject();
//     JsonHelper::AddStringToJsonObject(obj, "type", "customer");
//     JsonHelper::AddStringToJsonObject(obj, "name", "customer");
//     JsonHelper::AddFloatToJsonObject(obj, "ID", 2);
//     JsonHelper::AddFloatToJsonObject(obj, "version", 0);
//     JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
//     std::vector<float> position_to_add;
//     position_to_add.push_back(498.292);
//     position_to_add.push_back(253.883);
//     position_to_add.push_back(-228.623);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
//     std::vector<float> direction_to_add;
//     direction_to_add.push_back(1);
//     direction_to_add.push_back(0);
//     direction_to_add.push_back(0);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
//     IEntity* entity = system->CreateEntity(obj);
//
//
//     Customer customer1(position_to_add, direction_to_add, obj);
//
//     std::string name = JsonHelper::GetString(obj, "name");
//     std::string name2 = customer1.GetName();
//
//     EXPECT_EQ(name, name2) << name << " " << name2;
//
// }
//
// TEST_F(CustomerTest, CustomerGetRadiusTest){
//
//     picojson::object obj = JsonHelper::CreateJsonObject();
//     JsonHelper::AddStringToJsonObject(obj, "type", "customer");
//     JsonHelper::AddStringToJsonObject(obj, "name", "customer");
//     JsonHelper::AddFloatToJsonObject(obj, "ID", 2);
//     JsonHelper::AddFloatToJsonObject(obj, "version", 0);
//     JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
//     std::vector<float> position_to_add;
//     position_to_add.push_back(498.292);
//     position_to_add.push_back(253.883);
//     position_to_add.push_back(-228.623);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
//     std::vector<float> direction_to_add;
//     direction_to_add.push_back(1);
//     direction_to_add.push_back(0);
//     direction_to_add.push_back(0);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
//     IEntity* entity = system->CreateEntity(obj);
//     //JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
//
//     Customer customer1(position_to_add, direction_to_add, obj);
//
//     // JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
//     float radius = JsonHelper::GetDouble(obj, "radius");
//
//     EXPECT_EQ(radius, customer1.GetRadius());
//
// }
//
// TEST_F(CustomerTest, CustomerGetIdTest){
//
//     picojson::object obj = JsonHelper::CreateJsonObject();
//     JsonHelper::AddStringToJsonObject(obj, "type", "customer");
//     // JsonHelper::AddStringToJsonObject(obj, "name", "customer");
//     JsonHelper::AddFloatToJsonObject(obj, "id", 2);
//     // JsonHelper::AddFloatToJsonObject(obj, "version", 0);
//     // JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
//     std::vector<float> position_to_add;
//     position_to_add.push_back(498.292);
//     position_to_add.push_back(253.883);
//     position_to_add.push_back(-228.623);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
//     std::vector<float> direction_to_add;
//     direction_to_add.push_back(1);
//     direction_to_add.push_back(0);
//     direction_to_add.push_back(0);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
//     IEntity* entity = system->CreateEntity(obj);
//     //JsonHelper::AddFloatToJsonObject(obj, "ID", 2);
//
//     Customer customer1(position_to_add, direction_to_add, obj);
//
//     int id = JsonHelper::GetDouble(obj, "id");
//
//     EXPECT_EQ(id, customer1.GetId());
//
// }
//
// TEST_F(CustomerTest, CustomerGetVersionTest){
//
//     picojson::object obj = JsonHelper::CreateJsonObject();
//     JsonHelper::AddStringToJsonObject(obj, "type", "customer");
//     // JsonHelper::AddStringToJsonObject(obj, "name", "customer");
//     // JsonHelper::AddFloatToJsonObject(obj, "ID", 2);
//     JsonHelper::AddFloatToJsonObject(obj, "version", 0);
//     // JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
//     std::vector<float> position_to_add;
//     position_to_add.push_back(498.292);
//     position_to_add.push_back(253.883);
//     position_to_add.push_back(-228.623);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
//     std::vector<float> direction_to_add;
//     direction_to_add.push_back(1);
//     direction_to_add.push_back(0);
//     direction_to_add.push_back(0);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
//     IEntity* entity = system->CreateEntity(obj);
//     //JsonHelper::AddFloatToJsonObject(obj, "version", 0);
//
//     Customer customer1(position_to_add, direction_to_add, obj);
//
//     // JsonHelper::AddFloatToJsonObject(obj, "version", 0);
//
//     int id = JsonHelper::GetDouble(obj, "version");
//
//     EXPECT_EQ(id, customer1.GetVersion());
//
// }
//
// TEST_F(CustomerTest, CustomerGetlocationTest){
//
//     picojson::object obj = JsonHelper::CreateJsonObject();
//     JsonHelper::AddStringToJsonObject(obj, "type", "customer");
//     JsonHelper::AddStringToJsonObject(obj, "name", "customer");
//     JsonHelper::AddFloatToJsonObject(obj, "ID", 2);
//     JsonHelper::AddFloatToJsonObject(obj, "version", 0);
//     JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
//     std::vector<float> position_to_add;
//     position_to_add.push_back(498.292);
//     position_to_add.push_back(253.883);
//     position_to_add.push_back(-228.623);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
//     std::vector<float> direction_to_add;
//     direction_to_add.push_back(1);
//     direction_to_add.push_back(0);
//     direction_to_add.push_back(0);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
//     IEntity* entity = system->CreateEntity(obj);
//
//
//     Customer customer1(position_to_add, direction_to_add, obj);
//
//     std::vector<float> position = customer1.GetLocation();
//
//     for (int i = 0; i < position_to_add.size(); i++){
//         EXPECT_EQ(position_to_add.at(i), position.at(i));
//     }
//
// }
//
//
//
//
// }#include "gtest/gtest.h"
// #include "include/customer.h"
// #include <EntityProject/project_settings.h>
// #include "../include/delivery_simulation.h"
// #include <EntityProject/entity.h>
// #include "include/json_helper.h"
//
//
// #include <iostream>
//
// namespace csci3081 {
//
// using entity_project::IEntity;
//
// class CustomerTest : public ::testing::Test {
//     protected:
//   virtual void SetUp() {
//     system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));
//   }
//   virtual void TearDown() {}
//
//   IDeliverySystem* system;
//
// };
//
// /*******************************************************************************
//  * Test Cases
//  ******************************************************************************/
//
// TEST_F(CustomerTest, CustomerConstructorTest){
//
//     picojson::object obj = JsonHelper::CreateJsonObject();
//     JsonHelper::AddStringToJsonObject(obj, "type", "customer");
//     JsonHelper::AddStringToJsonObject(obj, "name", "customer");
//     JsonHelper::AddFloatToJsonObject(obj, "ID", 2);
//     JsonHelper::AddFloatToJsonObject(obj, "version", 0);
//     JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
//     std::vector<float> position_to_add;
//     position_to_add.push_back(498.292);
//     position_to_add.push_back(253.883);
//     position_to_add.push_back(-228.623);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
//     std::vector<float> direction_to_add;
//     direction_to_add.push_back(1);
//     direction_to_add.push_back(0);
//     direction_to_add.push_back(0);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
//     IEntity* entity = system->CreateEntity(obj);
//
//
//     Customer customer1(position_to_add, direction_to_add, obj);
//
//     std::vector<float> position = customer1.GetPosition();
//     std::vector<float> direction = customer1.GetDirection();
//
//     for (int i = 0; i < position_to_add.size(); i++){
//         EXPECT_EQ(position_to_add.at(i), position.at(i));
//     }
//
//     for (int i = 0; i < direction_to_add.size(); i++){
//         EXPECT_EQ(direction_to_add.at(i), direction.at(i));
//     }
//
// }
//
// TEST_F(CustomerTest, CustomerGetNameTest){
//
//     picojson::object obj = JsonHelper::CreateJsonObject();
//     JsonHelper::AddStringToJsonObject(obj, "type", "customer");
//     JsonHelper::AddStringToJsonObject(obj, "name", "customer");
//     JsonHelper::AddFloatToJsonObject(obj, "ID", 2);
//     JsonHelper::AddFloatToJsonObject(obj, "version", 0);
//     JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
//     std::vector<float> position_to_add;
//     position_to_add.push_back(498.292);
//     position_to_add.push_back(253.883);
//     position_to_add.push_back(-228.623);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
//     std::vector<float> direction_to_add;
//     direction_to_add.push_back(1);
//     direction_to_add.push_back(0);
//     direction_to_add.push_back(0);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
//     IEntity* entity = system->CreateEntity(obj);
//
//
//     Customer customer1(position_to_add, direction_to_add, obj);
//
//     std::string name = JsonHelper::GetString(obj, "name");
//     std::string name2 = customer1.GetName();
//
//     EXPECT_EQ(name, name2) << name << " " << name2;
//
// }
//
// TEST_F(CustomerTest, CustomerGetRadiusTest){
//
//     picojson::object obj = JsonHelper::CreateJsonObject();
//     JsonHelper::AddStringToJsonObject(obj, "type", "customer");
//     JsonHelper::AddStringToJsonObject(obj, "name", "customer");
//     JsonHelper::AddFloatToJsonObject(obj, "ID", 2);
//     JsonHelper::AddFloatToJsonObject(obj, "version", 0);
//     JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
//     std::vector<float> position_to_add;
//     position_to_add.push_back(498.292);
//     position_to_add.push_back(253.883);
//     position_to_add.push_back(-228.623);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
//     std::vector<float> direction_to_add;
//     direction_to_add.push_back(1);
//     direction_to_add.push_back(0);
//     direction_to_add.push_back(0);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
//     IEntity* entity = system->CreateEntity(obj);
//     //JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
//
//     Customer customer1(position_to_add, direction_to_add, obj);
//
//     // JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
//     float radius = JsonHelper::GetDouble(obj, "radius");
//
//     EXPECT_EQ(radius, customer1.GetRadius());
//
// }
//
// TEST_F(CustomerTest, CustomerGetIdTest){
//
//     picojson::object obj = JsonHelper::CreateJsonObject();
//     JsonHelper::AddStringToJsonObject(obj, "type", "customer");
//     // JsonHelper::AddStringToJsonObject(obj, "name", "customer");
//     JsonHelper::AddFloatToJsonObject(obj, "id", 2);
//     // JsonHelper::AddFloatToJsonObject(obj, "version", 0);
//     // JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
//     std::vector<float> position_to_add;
//     position_to_add.push_back(498.292);
//     position_to_add.push_back(253.883);
//     position_to_add.push_back(-228.623);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
//     std::vector<float> direction_to_add;
//     direction_to_add.push_back(1);
//     direction_to_add.push_back(0);
//     direction_to_add.push_back(0);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
//     IEntity* entity = system->CreateEntity(obj);
//     //JsonHelper::AddFloatToJsonObject(obj, "ID", 2);
//
//     Customer customer1(position_to_add, direction_to_add, obj);
//
//     int id = JsonHelper::GetDouble(obj, "id");
//
//     EXPECT_EQ(id, customer1.GetId());
//
// }
//
// TEST_F(CustomerTest, CustomerGetVersionTest){
//
//     picojson::object obj = JsonHelper::CreateJsonObject();
//     JsonHelper::AddStringToJsonObject(obj, "type", "customer");
//     // JsonHelper::AddStringToJsonObject(obj, "name", "customer");
//     // JsonHelper::AddFloatToJsonObject(obj, "ID", 2);
//     JsonHelper::AddFloatToJsonObject(obj, "version", 0);
//     // JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
//     std::vector<float> position_to_add;
//     position_to_add.push_back(498.292);
//     position_to_add.push_back(253.883);
//     position_to_add.push_back(-228.623);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
//     std::vector<float> direction_to_add;
//     direction_to_add.push_back(1);
//     direction_to_add.push_back(0);
//     direction_to_add.push_back(0);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
//     IEntity* entity = system->CreateEntity(obj);
//     //JsonHelper::AddFloatToJsonObject(obj, "version", 0);
//
//     Customer customer1(position_to_add, direction_to_add, obj);
//
//     // JsonHelper::AddFloatToJsonObject(obj, "version", 0);
//
//     int id = JsonHelper::GetDouble(obj, "version");
//
//     EXPECT_EQ(id, customer1.GetVersion());
//
// }
//
// TEST_F(CustomerTest, CustomerGetlocationTest){
//
//     picojson::object obj = JsonHelper::CreateJsonObject();
//     JsonHelper::AddStringToJsonObject(obj, "type", "customer");
//     JsonHelper::AddStringToJsonObject(obj, "name", "customer");
//     JsonHelper::AddFloatToJsonObject(obj, "ID", 2);
//     JsonHelper::AddFloatToJsonObject(obj, "version", 0);
//     JsonHelper::AddFloatToJsonObject(obj, "radius", 1.0);
//     std::vector<float> position_to_add;
//     position_to_add.push_back(498.292);
//     position_to_add.push_back(253.883);
//     position_to_add.push_back(-228.623);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
//     std::vector<float> direction_to_add;
//     direction_to_add.push_back(1);
//     direction_to_add.push_back(0);
//     direction_to_add.push_back(0);
//     JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
//     IEntity* entity = system->CreateEntity(obj);
//
//
//     Customer customer1(position_to_add, direction_to_add, obj);
//
//     std::vector<float> position = customer1.GetLocation();
//
//     for (int i = 0; i < position_to_add.size(); i++){
//         EXPECT_EQ(position_to_add.at(i), position.at(i));
//     }
//
// }
//
//
//
//
// }
