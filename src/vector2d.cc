#include "vector2d.h"

namespace csci3081 {

Vector2D::Vector2D(){
    mag_ = 0.0;
    coordinates_.push_back(0.0);
    coordinates_.push_back(0.0);
    coordinates_.push_back(0.0); 
}

Vector2D::Vector2D(float x, float y, float z){
    mag_ = 0.0;
    coordinates_.push_back(x);
    coordinates_.push_back(y);
    coordinates_.push_back(z);
    
}

Vector2D::Vector2D(std::vector<float> coord){
    for (int i = 0; i < coord.size(); i++)
    {
        coordinates_.push_back(coord.at(i));
    }
    
}

Vector2D::~Vector2D(){}

const std::vector<float>& Vector2D::GetCoord() const{

    return coordinates_;

}

void Vector2D::ComputeMagnitude(){

    float x = coordinates_.at(0);
    float y = coordinates_.at(1);
    float z = coordinates_.at(2);

    mag_ = sqrt(pow(x,2) + pow(y,2) + pow(z, 2));
}

float Vector2D::GetMagnitude(){
    return mag_;
}

void Vector2D::NormalizeVector(){

    for (int i = 0; i < coordinates_.size(); i++){

        if(coordinates_.at(i) != 0){
        coordinates_.at(i) /= mag_;
        } 
    }
}

float Vector2D::GetX(){
    return coordinates_.at(0);
}

float Vector2D::GetY(){
    return coordinates_.at(1);
}

float Vector2D::GetZ(){
    return coordinates_.at(2);
}

}