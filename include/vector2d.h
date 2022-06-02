/**
 * @file vector2d.h
 */
#ifndef VECTOR2D_H_
#define VECTOR2D_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "include/entity_base.h"
#include <vector>
#include <string>
#include <cmath>


namespace csci3081 {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Vector2D class header file
 *
 *
 */

class Vector2D {

    public:
    /**
   *  @brief Vector2D constructor with no arguments
    *  sets all attributes to 0.0
   */
    Vector2D();

    /**
   *  @brief Vector2D destructor
   */
    ~Vector2D();

    /**
   *  @brief Vector2D constructor with float arguments
   *  @param x x vector value
   *  @param y y vector value
   *  @param z z vector value
   */
    Vector2D(float x, float y, float z);

    /**
   *  @brief Vector2D constructor with float vector
   */
    Vector2D(std::vector<float> coord);

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
   *  @brief Normalize the 2d vector
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
   *  @brief Returns vector's z value
   */
    float GetZ();

    private:
        std::vector<float> coordinates_;
        float mag_;

};



}

#endif
