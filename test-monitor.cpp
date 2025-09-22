#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, VitalChecks) {
  VitalStatus status1 = checkVitals(99, 102, 70);
  EXPECT_FALSE(status1.pulseOk);
  EXPECT_FALSE(status1.spo2Ok);
  EXPECT_TRUE(status1.temperatureOk);

  VitalStatus status2 = checkVitals(98.1, 70, 98);
  EXPECT_TRUE(status2.temperatureOk);
  EXPECT_TRUE(status2.pulseOk);
  EXPECT_TRUE(status2.spo2Ok);

  VitalStatus status3 = checkVitals(88, 50, 85);
  EXPECT_FALSE(status3.temperatureOk);
  EXPECT_FALSE(status3.pulseOk);
  EXPECT_FALSE(status3.spo2Ok);
}
