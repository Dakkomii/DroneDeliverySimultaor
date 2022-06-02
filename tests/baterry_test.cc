#include "gtest/gtest.h"
#include "battery.h"


#include <iostream>

namespace csci3081 {


class BatteryTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    bat1 = Battery();
    bat2 = Battery(5000);
    bat3 = Battery(0);
  }
  virtual void TearDown() {
      
  }

  protected:
  Battery bat1;
  Battery bat2;
  Battery bat3;
    
  
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(BatteryTest, BatteryConstructor) {

    int expected_out_1 = 10000;
    int expected_out_2 = 5000;

    int output1 =  bat1.checkBattery();
    int output2 =  bat2.checkBattery();

    EXPECT_EQ(output1, expected_out_1);
    EXPECT_EQ(output2, expected_out_2);
}


TEST_F(BatteryTest, IsEmptyTest) {

    EXPECT_EQ(bat1.IsEmpty(), false);
    EXPECT_EQ(bat2.IsEmpty(), false);
    EXPECT_EQ(bat3.IsEmpty(), true);
}

TEST_F(BatteryTest, DepleteBatteryTest) {

    bat1.DepletingBattery(100.0);
    bat2.DepletingBattery(450.0);
    bat3.DepletingBattery(100.0);

  EXPECT_EQ(bat1.checkBattery(), 9900.0);
  EXPECT_EQ(bat2.checkBattery(), 4550.0);
  EXPECT_EQ(bat3.checkBattery(), 0.0);
}

//checkBattery method is already been tested by being used 
//on the others test fixtures

}  // namespace csci3081
