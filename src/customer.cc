#include "include/customer.h"

namespace csci3081 {

Customer::Customer(std::vector<float> position, std::vector<float> direction, const picojson::object& details) {

  for (int i = 0; i < position.size(); i++){
    this->pos.push_back(position.at(i));
  }

  for (int i = 0; i < direction.size(); i++){
    this->direction.push_back(direction.at(i));
  }
  
  // The following line saves the json object in the details_ member variable
  // from the EntityBase class, in order to return it later in GetDetails()
  details_ = details;
  IsDy = false;

  //set name
  if(JsonHelper::ContainsKey(details_, "name")){
    name = JsonHelper::GetString(details_, "name");
  }
  else{
    JsonHelper::AddStringToJsonObject(details_, "name", "customer");
    name = JsonHelper::GetString(details_, "name");
  }

  //set radius
  if(JsonHelper::ContainsKey(details_, "radius")){
    radius = JsonHelper::GetDouble(details_, "radius");
  }
  else{
    JsonHelper::AddFloatToJsonObject(details_, "radius", 1.0);
    radius = JsonHelper::GetDouble(details_, "radius");
  }

  //set id
  
  if(JsonHelper::ContainsKey(details_, "id")){
    id_ = JsonHelper::GetDouble(details_, "id");
  }
  else{
    JsonHelper::AddFloatToJsonObject(details_, "id", 2);
    id_ = JsonHelper::GetDouble(details_, "id");
  }

//  JsonHelper::AddFloatToJsonObject(details_, "id", 2);
//  id_ = JsonHelper::GetDouble(details_, "id");

  //set version
  if(JsonHelper::ContainsKey(details_, "version")){
    version = JsonHelper::GetDouble(details_, "version");
  }
  else{
    JsonHelper::AddFloatToJsonObject(details_, "version", 0);
    version = JsonHelper::GetDouble(details_, "version");
  }
}

//No memory in heap allocated so no necessary delete
Customer::~Customer(){}

//return location
std::vector<float> Customer::GetLocation(){

  for (int i = 0; i < pos.size(); i++){
    location.push_back(pos.at(i));
  }
  
  return location;
}

void Customer::decorate(){
  JsonHelper::AddStringToJsonObject(details_, "color" , "0xFFFFFF"); //0xff5733
}
}