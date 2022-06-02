#include "concrete_parabolic.h"

namespace csci3081 {

ConcreteParabolic::ConcreteParabolic(){}


ConcreteParabolic::~ConcreteParabolic(){}

int ConcreteParabolic::getIndex(){
  return routeIndex;
}

void ConcreteParabolic::SetIndex(int i){
  routeIndex = i;
}

void ConcreteParabolic::SetHasPackage(bool b){
  pickedPackage = b;
  if(pickedPackage){
    SetIndex(0); //changed to 1 it was 0
  }
}

bool ConcreteParabolic::HasPackage(){
  return pickedPackage;
}

bool ConcreteParabolic::GetEndOfRouteOne(){
  return endOfRouteOne;
}

bool ConcreteParabolic::GetEndOfRouteTwo(){
  return endOfRouteTwo;
}

std::vector<std::vector<float>> ConcreteParabolic::GetRouteOneSmart(){
  return routeOne;
}

std::vector<std::vector<float>> ConcreteParabolic::GetRouteTwoSmart(){
  return routeTwo;
}

std::vector<float> ConcreteParabolic::GetDirection(){
  return direction;
}

void ConcreteParabolic::SetDirection(std::vector<float> dir){
  for (int i = 0; i < dir.size(); i++)
  {
    direction.at(i) = dir.at(i);
  }

}

float ConcreteParabolic::distance(std::vector<float> vector1, std::vector<float> vector2){
  float x1 = vector1[0];
  float x2 = vector2[0];
  float y1 = vector1[1];
  float y2 = vector2[1];
  float z1 = vector1[2];
  float z2 = vector2[2];
  int d;
  d = sqrt(pow(x2 - x1,2) + pow(y2 - y1, 2) + pow(z2 - z1,2));
  return d;
}

void ConcreteParabolic::SetUp(std::vector<float> Dpos, std::vector<float> Ppos, std::vector<float> Cpos){
  // The calculations for the parabolic path follows the logic explained in the
  T = 50;                                   // T is the number of points
  j = 150;                                  // j is the max height
  //int t = 50;

  routeIndex = 1;
  pickedPackage = false;
  endOfRouteOne = false;
  endOfRouteTwo = false;
  dronePos = Dpos;
  packagePos = Ppos;
  customerPos = Cpos;
  direction = {1,1,1};

  std::vector<float> start = Dpos;
  std::vector<float> end = Ppos;
  std::vector<float> mid_point = {1,1,1};

  std::vector<float> vt = {1, 1, 1};
  std::vector<float> V = {1 , 1, 1};
  std::vector<float> final = {1, 1, 1};

  //route one setup
  for (int k = 0; k < dronePos.size(); k++){
      vt[k] = (Ppos[k] - Dpos[k])/T;
      mid_point[k] = start[k] + (Ppos[k] - Dpos[k])/2;
    }


  for (int i = 0; i < T; i++){

    V[0] = Dpos[0] + (vt[0] * i);
    V[1] = Dpos[1] + (vt[1] * i);
    V[2] = Dpos[2] + (vt[2] * i);

    y = (1 - pow(distance(V, mid_point),2) / pow(distance(Dpos, mid_point),2))* j;

    final[0] = V[0];
    final[1] = V[1] + y;
    final[2] = V[2];

    routeOne.push_back(final);
  }

  start = Ppos;
  end = Cpos;
  //route two setup
  for (int k = 0; k < dronePos.size(); k++){
      vt[k] = (Cpos[k] - Ppos[k])/T;
      mid_point[k] = start[k] + (Cpos[k] - Ppos[k])/2;
    }


  for (int i = 0; i < T; i++){

    V[0] = Ppos[0] + (vt[0] * i);
    V[1] = Ppos[1] + (vt[1] * i);
    V[2] = Ppos[2] + (vt[2] * i);

    y = (1 - pow(distance(V, mid_point),2) / pow(distance(Cpos, mid_point),2))* j;

    final[0] = V[0];
    final[1] = V[1] + y;
    final[2] = V[2];

    routeTwo.push_back(final);
  }
}

std::vector<float> ConcreteParabolic::move(float dt, float speed, float radius){
  if (routeOne.size() == 0){
    return dronePos;
  }

  if (routeTwo.size() == 0){
    return dronePos;
  }

  this->speed = speed;

  //if package is not picked up calculate path to package
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

  //if package is picked up calculate path to customer
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
