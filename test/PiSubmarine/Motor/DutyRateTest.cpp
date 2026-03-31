#include <gtest/gtest.h>
#include "PiSubmarine/Motor/DutyRate.h"
#include <chrono>

using namespace std::chrono_literals;

namespace PiSubmarine::Motor
{
    TEST(DutyRateTest, Constructor)
    {
        DutyRate dutyRate(0.1, 100ms);
        ASSERT_EQ(dutyRate.DutyPerSecond, 1);

        double dutyPerMinute = dutyRate * 1min;
        ASSERT_EQ(dutyPerMinute, 60);
    }
}