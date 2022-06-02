#include "concrete_beeline.h"

namespace csci3081 {

ConcreteBeeline::ConcreteBeeline(){}


ConcreteBeeline::~ConcreteBeeline(){}

int ConcreteBeeline::getIndex(){
  return routeIndex;
}

void ConcreteBeeline::SetIndex(int i){
  routeIndex = i;
}

void ConcreteBeeline::SetHasPackage(bool b){
  pickedPackage = b;
  if(pickedPackage){
    SetIndex(0); //changed to 1 it was 0
  }
}

std::vector<float> ConcreteBeeline::GetDirection(){
  return direction;
}

void ConcreteBeeline::SetDirection(std::vector<float> dir){
  for (int i = 0; i < dir.size(); i++)
  {
    direction.at(i) = dir.at(i);
  }
}

bool ConcreteBeeline::HasPackage(){
  return pickedPackage;
}

bool ConcreteBeeline::GetEndOfRouteOne(){
  return endOfRouteOne;
}

bool ConcreteBeeline::GetEndOfRouteTwo(){
  return endOfRouteTwo;
}

std::vector<std::vector<float>> ConcreteBeeline::GetRouteOneSmart(){
  return routeOne;
}

std::vector<std::vector<float>> ConcreteBeeline::GetRouteTwoSmart(){
  return routeTwo;
}

//sets up all values needed to move drone/robot in a beeline path
void ConcreteBeeline::SetUp(std::vector<float> Dpos, std::vector<float> Ppos, std::vector<float> Cpos){
    std::vector<float> upVector = Dpos;
    upVector[1] = 300;                          // updating drone y val to 300
    std::vector<float> upVectorP = Ppos;
    upVectorP[1] = 300;
    routeOne.push_back(Dpos);
    routeOne.push_back(upVector);
    routeOne.push_back(upVectorP);
    routeOne.push_back(Ppos);

    std::vector<float> upVectorPack = Ppos;
    upVectorPack[1] = 300;
    std::vector<float> upVectorCust = Cpos;
    upVectorCust[1] = 300;
    routeTwo.push_back(Ppos);
    routeTwo.push_back(upVectorPack);
    routeTwo.push_back(upVectorCust);
    routeTwo.push_back(Cpos);

    routeIndex = 1;
    pickedPackage = false;
    endOfRouteOne = false;
    endOfRouteTwo = false;
    dronePos = Dpos;
    packagePos = Ppos;
    customerPos = Cpos;
    direction = {1,1,1};
}

//moves drone/robot in a beeline path
std::vector<float> ConcreteBeeline::move(float dt, float speed, float radius){
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
