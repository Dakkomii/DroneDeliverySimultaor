#include "include/drone.h"

namespace csci3081 {

Drone::Drone(std::vector<float> position, std::vector<float> direction, const picojson::object& details) {

  for (int i = 0; i < position.size(); i++){
    this->pos.push_back(position.at(i));
  }

  for (int i = 0; i < direction.size(); i++){
    this->direction.push_back(direction.at(i));
  }

  // The following line saves the json object in the details_ member variable
  // from the EntityBase class, in order to return it later in GetDetails()
  details_ = details;
  IsDy = true;
  index = 1;
  hasPackage = false;
  deliver = false;
  batteryDepleted = false;

  droneToPackage = false;
  droneToCustomer = false;
  droneHasPackage = false;
  dronefinished = false;

  //set name
  if(JsonHelper::ContainsKey(details_, "name")){
    name = JsonHelper::GetString(details_, "name");
  }
  else{
    JsonHelper::AddStringToJsonObject(details_, "name", "drone");
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
    JsonHelper::AddFloatToJsonObject(details_, "id", 1);
    id_ = JsonHelper::GetDouble(details_, "id");
  }

  //set version
  if(JsonHelper::ContainsKey(details_, "version")){
    version = JsonHelper::GetDouble(details_, "version");
  }
  else{
    JsonHelper::AddFloatToJsonObject(details_, "version", 0);
    version = JsonHelper::GetDouble(details_, "version");
  }

  if(JsonHelper::ContainsKey(details_, "battery_capacity")){
    battery = new Battery(JsonHelper::GetDouble(details_, "battery_capacity"));
  }
  else{
    JsonHelper::AddFloatToJsonObject(details_, "battery_capacity", 10000);
    battery = new Battery();
  }

  //set speed
  if(JsonHelper::ContainsKey(details_, "speed")){
    speed = JsonHelper::GetDouble(details_,"speed");
  }
  else{
    JsonHelper::AddFloatToJsonObject(details_, "speed", 10.0);
    speed = JsonHelper::GetDouble(details_,"speed");
  }
}

//Destructor: No memory in heap allocated so no necessary delete
Drone::~Drone(){}

//set to true if is already delivering a package
void Drone::SetDelivering(bool b){
  deliver = b;
}

bool Drone::IsDelivering(){
  return deliver;
}

void Drone::Reset(){
  droneToPackage = false;
  droneToCustomer = false;
  droneHasPackage = false;
}

bool Drone::GetDroneToPackage(){
  return droneToPackage;
}
bool Drone::GetDroneToCustomer(){
  return droneToCustomer;
}
bool Drone::GetDroneHasPackage(){
  return droneHasPackage;
}

bool Drone::GetDronefinished(){
  return dronefinished;
} 

void Drone::SetDroneToPackage(bool b){
  droneToPackage = b;
}
void Drone::SetDroneToCustomer(bool b){
  droneToCustomer = b;
}
void Drone::SetDroneHasPackage(bool b){
  droneHasPackage = b;
}

void Drone::SetDronefinished(bool b){
  dronefinished = b;
}

void Drone::SetRouteOne(){
  this->routeOne = strategy->GetRouteOneSmart();
}

void Drone::SetRouteTwo(){
  this->routeTwo = strategy->GetRouteTwoSmart();
}

std::vector<std::vector<float>> Drone::GetRouteOne(){
  return routeOne;
}

std::vector<std::vector<float>> Drone::GetRouteTwo(){
  return routeTwo;
}

Package* Drone::GetPackageObject(){
  return package;
}

void Drone::SetIndex(int i){
  index = i;
}

int Drone::GetIndex(){
  return index;
}

//links drone to a package
void Drone::SetPackage(Package *package){
  this->package = package;
}

//get a bool value. true if delivering a package otherwise false
void Drone::SetPackage(bool b){
  hasPackage = b;
  if(hasPackage){
    SetIndex(0); //changed to 1 it was 0
  }
}

bool Drone::GetPackage(){
  return hasPackage;
}

void Drone::SetStrategy(IStrategy* strategy){
  this->strategy = strategy;
}

void Drone::setUpStrategy(std::vector<float> d, std::vector<float> p, std::vector<float> c){
  strategy->SetUp(d, p, c);
}

bool Drone::isBaterryDepleted(){
  return batteryDepleted;
}

void Drone::decorate(){
  JsonHelper::AddStringToJsonObject(details_, "color" , "0xFFFFFF"); //0xff5733
}

//moves tthe drone
void Drone::update(float dt){

  pos = strategy->move(dt, speed, radius);
  direction = strategy->GetDirection();

  battery->DepletingBattery(dt);
  if(battery->IsEmpty()){
    batteryDepleted = true;
    if(hasPackage){
    hasPackage = false;
    //package->SetDynamic(false);
    //deliver = false;
    std::vector<float> p = pos;
    p[1] = 287;
    package->SetPosition(p);
    }
    hasPackage = false;
    return;
  }

  if(strategy->GetEndOfRouteOne()){
    SetPackage(true);
  }

  if(strategy->HasPackage()){
    package->SetDynamic(true);
    package->SetPosition(pos);
  }

  if(strategy->GetEndOfRouteTwo()){
    std::cout << "check final route 2" << "\n";
    std::vector<float> endpos = {1000, 1000, 1000}; //random position to make package dissapear from sim.
    package->SetPosition(endpos);
    hasPackage = false;
    package->SetIsDelivered(true); //package its been delivered
    deliver = false; //set delivering to false so drone can make other deliveries
    return;
  }


}

}
