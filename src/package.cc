#include "include/package.h"
//#include "drone.h"

namespace csci3081 {

Package::Package(std::vector<float> position, std::vector<float> direction, const picojson::object& details) {

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
  IsDelivered = false;

  //set name
  if(JsonHelper::ContainsKey(details_, "name")){
    name = JsonHelper::GetString(details_, "name");
  }
  else{
    JsonHelper::AddStringToJsonObject(details_, "name", "package");
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
    JsonHelper::AddFloatToJsonObject(details_, "id", 3);
  }

  //set version
  if(JsonHelper::ContainsKey(details_, "version")){
    version = JsonHelper::GetDouble(details_, "version");
  }
  else{
    JsonHelper::AddFloatToJsonObject(details_, "version", 0);
    version = JsonHelper::GetDouble(details_, "version");
  }

  //set weight
  if(JsonHelper::ContainsKey(details_, "weight")){
    weight = JsonHelper::GetDouble(details_, "weight");
  }
  else{
    JsonHelper::AddFloatToJsonObject(details_, "weight", 0.0);
    weight = JsonHelper::GetDouble(details_, "weight");
  }
}

//Destructor: no memory in heap allocated so no necessary delete
Package::~Package(){}

//returns weight
double Package::GetWeight(){return weight;}

//returns destination
std::vector<float> Package::GetDestination(){
  destination = customer->GetPosition() ;
  return destination;
}

//set customer
void Package::SetCustomer(Customer *customer){
  this->customer = customer;
}

//returns Customer object
Customer* Package::GetCustomer(){
  return customer;
}

void Package::SetPosition(std::vector<float> position){
  pos = position;
}

void Package::SetDynamic(bool b){
  IsDy = b;
}


bool Package::GetIsDelivered(){
  return IsDelivered;
}

void Package::SetIsDelivered(bool b){
  IsDelivered = b;
}

void Package::decorate(){
  JsonHelper::AddStringToJsonObject(details_, "color" , "0xFFFFFF"); //0xff5733
}

}
