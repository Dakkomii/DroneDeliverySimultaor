/**
 * @file vector3d.h
 */

#ifndef VECTOR3D_H_
#define VECTOR3D_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "include/entity_base.h"
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Vector3D header file
 *
 *
 */

class Vector3D {

    public:

    /**
    *  @brief Vector3D constructor with no arguments
    *  sets all attributes to 0.0
    */
    Vector3D();

    /**
   *  @brief Vector3D constructor with float arguments
   *  @param x x vector value
   *  @param y y vector value
   *  @param z z vector value
   */
    Vector3D(float x, float y, float z);

    /**
   *  @brief Vector3D constructor with float vector
   */
    Vector3D(std::vector<float> coord);

    /**
   *  @brief Vector3D - overloaded contructor to
   * substract two vectors
   */
    Vector3D operator-(Vector3D A);

    /**
   *  @brief Returns vector
   */
    const std::vector<float>& GetCoord() const;

    /**
   *  @brief Computes the maginute of the vector
   */
    void ComputeMagnitude();

    /**
   *  @brief Returns vector magnitude
   */
    float GetMagnitude();

    /**
   *  @brief Normalize the 3d vector
   */
    void NormalizeVector();

    /**
   *  @brief Returns vector's x value
   */
    float GetX();

    /**
   *  @brief Returns vector's y value
   */
    float GetY();

    /**
   *  @brief Returns vector's Z value
   */
    float GetZ();

    private:

    std::vector<float> coordinates_;
    float mag_;

};

}

#endif
