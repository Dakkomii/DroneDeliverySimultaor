#include "gtest/gtest.h"
#include "vector3d.h"


#include <iostream>

namespace csci3081 {


class Vector3DTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    vec1 = Vector3D();
    vec2 = Vector3D(10.0, 20.0, 15.0);
  }
  virtual void TearDown() {
      
  }

  protected:
  Vector3D vec1;
  Vector3D vec2;
    
  
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(Vector3DTest, Vector3DConstructor) {

    //on this test the constructor and coordinates getters are tested
    //therefore no unique tests are created for coordinates getters

    EXPECT_EQ(vec1.GetX(), 0.0);
    EXPECT_EQ(vec1.GetY(), 0.0);
    EXPECT_EQ(vec1.GetZ(), 0.0);

    EXPECT_EQ(vec2.GetX(), 10.0);
    EXPECT_EQ(vec2.GetY(), 20.0);
    EXPECT_EQ(vec2.GetZ(), 15.0);
}


TEST_F(Vector3DTest, ComputeMagniuteTest) {

    vec1.ComputeMagnitude();
    vec2.ComputeMagnitude();

    EXPECT_FLOAT_EQ(vec1.GetMagnitude(), 0.0);
    EXPECT_FLOAT_EQ(vec2.GetMagnitude() , 26.925824);

}

TEST_F(Vector3DTest, NormalizeTest) {

    vec1.ComputeMagnitude();
    vec1.NormalizeVector();

    EXPECT_EQ(vec1.GetX(), 0.0);
    EXPECT_EQ(vec1.GetY(), 0.0);
    EXPECT_EQ(vec1.GetZ(), 0.0);

    vec2.ComputeMagnitude();
    vec2.NormalizeVector();

    EXPECT_FLOAT_EQ(vec2.GetX(), 0.3713907);
    EXPECT_NEAR(vec2.GetY(), 0.742781,0.00001);
    EXPECT_FLOAT_EQ(vec2.GetZ(), 0.557086);
}

//there is no test for getx, getY and getZ methods becaue is already been tested by being used 
//on the others test fixtures




}  // namespace csci3081