
/// Description
/// Orientation
///
#pragma once

#include <iostream>

#include "NumCpp/Utils/essentiallyEqual.hpp"

namespace nc::coordinates
{
    /**
     * @brief Orientation
     */
    class Orientation
    {
    public:
        double roll{ 0. };
        double pitch{ 0. };
        double yaw{ 0. };

        /**
         * @brief Default Constructor
         */
        Orientation() noexcept = default;

        /**
         * @brief Constructor
         *
         * @param inRoll: the roll component
         * @param inPitch: the pitch component
         * @param inYaw: the yaw component
         */
        constexpr Orientation(double inRoll, double inPitch, double inYaw) noexcept :
            roll(inRoll),
            pitch(inPitch),
            yaw(inYaw)
        {
        }

        /**
         * @brief Copy Constructor
         *
         * @param other: the other Orientation instance
         */
        Orientation(const Orientation& other) noexcept = default;

        /**
         * @brief Move Orientation
         *
         * @param other: the other Orientation instance
         */
        Orientation(Orientation&& other) noexcept = default;

        /**
         * @brief Destructor
         */
        virtual ~Orientation() = default;

        /**
         * @brief Copy Assignement Operator
         *
         * @param other: the other Orientation instance
         */
        Orientation& operator=(const Orientation& other) noexcept = default;

        /**
         * @brief Move Assignement Operator
         *
         * @param other: the other Orientation instance
         */
        Orientation& operator=(Orientation&& other) noexcept = default;

        /**
         * @brief Non-Equality Operator
         *
         * @param other: other object
         * @return bool true if not equal equal
         */
        bool operator==(const Orientation& other) const noexcept
        {
            return utils::essentiallyEqual(roll, other.roll) && utils::essentiallyEqual(pitch, other.pitch) &&
                   utils::essentiallyEqual(yaw, other.yaw);
        }

        /**
         * @brief Non-Equality Operator
         *
         * @param other: other object
         * @return bool true if not equal equal
         */
        bool operator!=(const Orientation& other) const noexcept
        {
            return !(*this == other);
        }
    };

    /**
     * @brief Stream operator
     *
     * @param os: the output stream
     * @param orientation: the roll/pitch/yaw angles
     */
    inline std::ostream& operator<<(std::ostream& os, const Orientation& orientation)
    {
        os << "Orientation(roll=" << orientation.roll << ", pitch=" << orientation.pitch << ", yaw=" << orientation.yaw
           << ")\n";
        return os;
    }
} // namespace nc::coordinates
