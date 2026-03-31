#pragma once

#include <chrono>

namespace PiSubmarine::Motor
{
    class DutyRate
    {
    public:
        double DutyPerSecond = 0;

        template<typename Rep, typename Period>
        DutyRate(double duty, const std::chrono::duration<Rep, Period>& time)
        {
            const double seconds = std::chrono::duration_cast<std::chrono::duration<double>>(time).count();
            if (seconds <= 0.0)
            {
                throw std::invalid_argument("Time must be positive");
            }
            DutyPerSecond = duty / seconds;
        }

        template<typename Rep, typename Period>
        double operator*(const std::chrono::duration<Rep, Period>& time)
        {
            const double seconds = std::chrono::duration_cast<std::chrono::duration<double>>(time).count();
            return DutyPerSecond * seconds;
        }
    };
}
