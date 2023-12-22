
/// Description
/// A timer class for timing code execution
///
#pragma once

#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <type_traits>

#include "NumCpp/Core/Enums.hpp"
#include "NumCpp/Core/Types.hpp"

namespace nc
{
    //================================================================================
    /// A timer class for timing code execution
    template<typename TimeUnit = std::chrono::milliseconds>
    class Timer
    {
    public:
        //==============================Typedefs======================================
        using ChronoClock = std::chrono::steady_clock;
        using TimePoint   = std::chrono::time_point<ChronoClock>;

        //============================================================================
        // Method Description:
        /// Constructor
        ///
        Timer() :
            start_(ChronoClock::now())
        {
            setUnits();
        }

        //============================================================================
        // Method Description:
        /// Constructor
        ///
        /// @param inName
        ///
        explicit Timer(const std::string& inName) :
            name_(inName + " "),
            start_(ChronoClock::now())
        {
            setUnits();
        }

        //============================================================================
        // Method Description:
        /// Sets/changes the timer name
        ///
        /// @param inName
        ///
        void setName(const std::string& inName)
        {
            name_ = inName + " ";
        }

        //============================================================================
        // Method Description:
        /// Sleeps the current thread
        ///
        /// @param length: the length of time to sleep
        ///
        void sleep(uint32 length)
        {
            std::this_thread::sleep_for(TimeUnit(length));
        }

        //============================================================================
        // Method Description:
        /// Starts the timer
        ///
        void tic() noexcept
        {
            start_ = ChronoClock::now();
        }

        //============================================================================
        // Method Description:
        /// Stops the timer
        ///
        /// @param printElapsedTime: whether or not to print the elapsed time to
        /// the console
        /// @return ellapsed time in specified time units
        ///
        TimeUnit toc(PrintElapsedTime printElapsedTime = PrintElapsedTime::YES)
        {
            const auto duration = std::chrono::duration_cast<TimeUnit>(ChronoClock::now() - start_);

            if (printElapsedTime == PrintElapsedTime::YES)
            {
                std::cout << name_ << "Elapsed Time = " << duration.count() << unit_ << std::endl;
            }

            return duration;
        }

    private:
        //==============================Attributes====================================
        std::string name_{ "" };
        std::string unit_{ "" };
        TimePoint   start_{};

        void setUnits()
        {
            if constexpr (std::is_same_v<TimeUnit, std::chrono::hours>)
            {
                unit_ = " hours";
            }
            else if constexpr (std::is_same_v<TimeUnit, std::chrono::minutes>)
            {
                unit_ = " minutes";
            }
            else if constexpr (std::is_same_v<TimeUnit, std::chrono::seconds>)
            {
                unit_ = " seconds";
            }
            else if constexpr (std::is_same_v<TimeUnit, std::chrono::milliseconds>)
            {
                unit_ = " milliseconds";
            }
            else if constexpr (std::is_same_v<TimeUnit, std::chrono::microseconds>)
            {
                unit_ = " microseconds";
            }
            else if constexpr (std::is_same_v<TimeUnit, std::chrono::nanoseconds>)
            {
                unit_ = " nanoseconds";
            }
            else
            {
                unit_ = " time units of some sort";
            }
        }
    };
} // namespace nc
