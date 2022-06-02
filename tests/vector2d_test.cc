#include "gtest/gtest.h"
#include "vector2d.h"


#include <iostream>

namespace csci3081 {


class Vector2DTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    vec1 = Vector2D();
    vec2 = Vector2D(10.0, 0.0, 15.0);
  }
  virtual void TearDown() {
      
  }

  protected:
  Vector2D vec1;
  Vector2D vec2;
    
  
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(Vector2DTest, Vector2DConstructor) {

    //on this test the constructor and coordinates getters are tested
    //therefore no unique tests are created for coordinates getters

    EXPECT_EQ(vec1.GetX(), 0.0);
    EXPECT_EQ(vec1.GetY(), 0.0);
    EXPECT_EQ(vec1.GetZ(), 0.0);

    EXPECT_EQ(vec2.GetX(), 10.0);
    EXPECT_EQ(vec2.GetY(), 0.0);
    EXPECT_EQ(vec2.GetZ(), 15.0);
}


TEST_F(Vector2DTest, Vector2DComputeMagniuteTest) {

    vec1.ComputeMagnitude();
    vec2.ComputeMagnitude();

    EXPECT_FLOAT_EQ(vec1.GetMagnitude(), 0.0);
    EXPECT_FLOAT_EQ(vec2.GetMagnitude() , 18.027756);

}

TEST_F(Vector2DTest, Vector2DNormalizeTest) {

    vec1.ComputeMagnitude();
    vec1.NormalizeVector();

    EXPECT_EQ(vec1.GetX(), 0);
    EXPECT_EQ(vec1.GetY(), 0);
    EXPECT_EQ(vec1.GetZ(), 0);

    vec2.ComputeMagnitude();
    vec2.NormalizeVector();

    EXPECT_FLOAT_EQ(vec2.GetX(), 0.5547);
    EXPECT_FLOAT_EQ(vec2.GetY(), 0.0);
    EXPECT_NEAR(vec2.GetZ(), 0.83205031175, 0.00001);
}

//there is no test for getx, getY and getZ methods becaue is already been tested by being used 
//on the others test fixtures




}  // namespace csci3081