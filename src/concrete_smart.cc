#include "concrete_smart.h"

namespace csci3081 {

ConcreteSmart::ConcreteSmart(){}


ConcreteSmart::~ConcreteSmart(){}

int ConcreteSmart::getIndex(){
  return routeIndex;
}

void ConcreteSmart::SetIndex(int i){
  routeIndex = i;
}

void ConcreteSmart::SetHasPackage(bool b){
  pickedPackage = b;
  if(pickedPackage){
    SetIndex(0); //changed to 1 it was 0
  }
}

bool ConcreteSmart::HasPackage(){
  return pickedPackage;
}

bool ConcreteSmart::GetEndOfRouteOne(){
  return endOfRouteOne;
}

bool ConcreteSmart::GetEndOfRouteTwo(){
  return endOfRouteTwo;
}

std::vector<std::vector<float>> ConcreteSmart::GetRouteOneSmart(){
  return routeOne;
}

std::vector<std::vector<float>> ConcreteSmart::GetRouteTwoSmart(){
  return routeTwo;
}

void ConcreteSmart::SetGraph(const IGraph* graph){
  graphs = graph;
}

std::vector<float> ConcreteSmart::GetDirection(){
  return direction;
}

void ConcreteSmart::SetDirection(std::vector<float> dir){
  for (int i = 0; i < dir.size(); i++)
  {
    direction.at(i) = dir.at(i);
  }

}

//sets up all values needed to move drone/robot in a smart path
void ConcreteSmart::SetUp(std::vector<float> Dpos, std::vector<float> Ppos, std::vector<float> Cpos){
  routeOne = graphs->GetPath(Dpos, Ppos);  //from starting point to midpoint(ie.package)
  routeTwo = graphs->GetPath(Ppos,Cpos);  // midpoint(ie.package) to final destination (ie. customer)
  routeIndex = 1;
  pickedPackage = false;
  endOfRouteOne = false;
  endOfRouteTwo = false;
  dronePos = Dpos;
  packagePos = Ppos;
  customerPos = Cpos;
  direction = {1,1,1};
}

//moves drone/robot in a smart path
std::vector<float> ConcreteSmart::move(float dt, float speed, float radius){


  if (routeOne.size() == 0){
    return dronePos;
  }

  if (routeTwo.size() == 0){
    return dronePos;
  }

  this->speed = speed;

//if package is not picked up calculate distance to package
  if(!pickedPackage){

    int index = getIndex();
    std::vector<float> pointToMove = routeOne[index];

    for (int i = 0; i < dronePos.size(); i++){
      direction[i] = (pointToMove[i] - dronePos[i]);
    }

    Vector3D vec(direction);
    vec.ComputeMagnitude();
    vec.NormalizeVector();
    direction = vec.GetCoord();

    for (int k = 0; k < direction.size(); k++){
      dronePos.at(k) = dronePos.at(k) + (direction[k]* speed * dt);
    }

    std::vector<float> distance;
    for (int i = 0; i < pointToMove.size() ; i++){
      distance.push_back(routeOne[index][i] - dronePos[i]);
    }

    Vector3D distVec(distance);
    distVec.ComputeMagnitude();
    float dist = distVec.GetMagnitude();

    if(dist <= radius){
      index++;
      SetIndex(index);
    }

    if(index == routeOne.size()){
      SetHasPackage(true);
      endOfRouteOne = true;
    }

    return dronePos;
  }
  //if package is  picked up calculate distance to customer
  if(pickedPackage){
    int index = getIndex();
    std::vector<float> pointToMove = routeTwo[index];

    for (int i = 0; i < dronePos.size(); i++){
      direction[i] = (pointToMove[i] - dronePos[i]);
    }

    Vector3D vec(direction);
    vec.ComputeMagnitude();
    vec.NormalizeVector();
    direction = vec.GetCoord();

    for (int k = 0; k < direction.size(); k++){
      dronePos.at(k) = dronePos.at(k) + (direction[k]* speed * dt);
    }

    std::vector<float> distance;
    for (int i = 0; i < pointToMove.size() ; i++){
      distance.push_back(routeTwo[index][i] - dronePos[i]);
    }

    Vector3D distVec(distance);
    distVec.ComputeMagnitude();
    float dist = distVec.GetMagnitude();

    if(dist <= radius){
      index++;
      SetIndex(index);
    }

    if(routeIndex == routeTwo.size()){
      pickedPackage = false;
      endOfRouteTwo = true;
      routeTwo.clear();
      routeOne.clear();
    }

    return dronePos;

  }
  return dronePos;
}

}
