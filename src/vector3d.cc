#include "vector3d.h"

namespace csci3081 {

Vector3D::Vector3D(){
    mag_ = 0.0;
    coordinates_.push_back(0.0);
    coordinates_.push_back(0.0);
    coordinates_.push_back(0.0);
    
}

Vector3D::Vector3D(float x, float y, float z){
    mag_ = 0.0;
    coordinates_.push_back(x);
    coordinates_.push_back(y);
    coordinates_.push_back(z);
    
}

Vector3D::Vector3D(std::vector<float> coord){
    for (int i = 0; i < coord.size(); i++)
    {
        coordinates_.push_back(coord.at(i));
    }
    
}

Vector3D Vector3D::operator-(Vector3D A){
    
    this->coordinates_.at(0) -= A.GetX();
    this->coordinates_.at(1) -= A.GetY();
    this->coordinates_.at(2) -= A.GetZ();
    
    return coordinates_;
}

const std::vector<float>& Vector3D::GetCoord() const{

    return coordinates_;

}

void Vector3D::ComputeMagnitude(){

    float x = coordinates_.at(0);
    float y = coordinates_.at(1);
    float z = coordinates_.at(2);

    mag_ = sqrt(pow(x,2) + pow(y,2) + pow(z, 2));
}

float Vector3D::GetMagnitude(){
    return mag_;
}

void Vector3D::NormalizeVector(){

    //add compute magnitude

    for (int i = 0; i < coordinates_.size(); i++){
        if(coordinates_.at(i) == 0)
            continue;
        else
            coordinates_.at(i) /= mag_;     
    }
}

float Vector3D::GetX(){
    return coordinates_.at(0);
}

float Vector3D::GetY(){
    return coordinates_.at(1);
}

float Vector3D::GetZ(){
    return coordinates_.at(2);
}

}