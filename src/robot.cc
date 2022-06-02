#include "include/robot.h"
#include "package.h"

namespace csci3081 {

Robot::Robot(std::vector<float> position, std::vector<float> direction, const picojson::object& details) {

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

  //set name
  if(JsonHelper::ContainsKey(details_, "name")){
    name = JsonHelper::GetString(details_, "name");
  }
  else{
    JsonHelper::AddStringToJsonObject(details_, "name", "robot");
  }

  //set radius
  if(JsonHelper::ContainsKey(details_, "radius")){
    radius = JsonHelper::GetDouble(details_, "radius");
  }
  else{
    JsonHelper::AddFloatToJsonObject(details_, "radius", 1.0);
  }

  //set id

  if(JsonHelper::ContainsKey(details_, "id")){
    id_ = JsonHelper::GetDouble(details_, "id");
  }
  else{
    JsonHelper::AddFloatToJsonObject(details_, "id", 4);
    id_ = JsonHelper::GetDouble(details_, "id");
  }

  //set version
  if(JsonHelper::ContainsKey(details_, "version")){
    version = JsonHelper::GetDouble(details_, "version");
  }
  else{
    JsonHelper::AddFloatToJsonObject(details_, "version", 0);
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
Robot::~Robot(){}

//set to true if is already delivering a package
void Robot::SetDelivering(bool b){
  deliver = b;
}

bool Robot::IsDelivering(){
  return deliver;
}

void Robot::SetRouteOne(){
  this->routeOne = strategy->GetRouteOneSmart();
}

void Robot::SetRouteTwo(){
  this->routeTwo = strategy->GetRouteTwoSmart();
}

std::vector<std::vector<float>> Robot::GetRouteOne(){
  return routeOne;
}

std::vector<std::vector<float>> Robot::GetRouteTwo(){
  return routeTwo;
}

Package* Robot::GetPackageObject(){
  return package;
}

void Robot::SetIndex(int i){
  index = i;
}

int Robot::GetIndex(){
  return index;
}

//links Robot to a package
void Robot::SetPackage(Package *package){
  this->package = package;
}

//get a bool value. true if delivering a package otherwise false
void Robot::SetPackage(bool b){
  hasPackage = b;
  if(hasPackage){
    SetIndex(0); //changed to 1. was 0
  }
}

bool Robot::GetPackage(){
  return hasPackage;
}

void Robot::SetStrategy(IStrategy* strategy){
  this->strategy = strategy;
}

void Robot::Reset(){
  robotToPackage = false;
  robotToCustomer = false;
  robotHasPackage = false;
}

bool Robot::GetRobotToPackage(){
  return robotToPackage;
}
bool Robot::GetRobotToCustomer(){
  return robotToCustomer;
}
bool Robot::GetRobotHasPackage(){
  return robotHasPackage;
}

bool Robot::GetRobotfinished(){
  return robotfinished;
}

void Robot::SetRobotToPackage(bool b){
  robotToPackage = b;
}
void Robot::SetRobotToCustomer(bool b){
  robotToCustomer = b;
}
void Robot::SetRobotHasPackage(bool b){
  robotHasPackage = b;
}

void Robot::SetRobotfinished(bool b){
  robotfinished = b;
}

bool Robot::isBaterryDepleted(){
  return batteryDepleted;
}

void Robot::decorate(){
  JsonHelper::AddStringToJsonObject(details_, "color" , "0xFFFFFF"); //0xff5733
}

//moves tthe Robot
void Robot::update(float dt){

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
    std::cout << "check end route 2" << "\n";
    std::vector<float> endpos = {1000, 1000, 1000}; //random position to make package dissapear from sim.
    package->SetPosition(endpos);
    hasPackage = false;
    package->SetIsDelivered(true); //package its been delivered
    deliver = false; //set delivering to false so Robot can make other deliveries
    return;
  }

}


}
