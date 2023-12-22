

/// Description
/// AER Object
///
#pragma once

#include <iostream>

#include "NumCpp/Utils/essentiallyEqual.hpp"

namespace nc::coordinates::reference_frames
{
    /**
     * @brief Az, El, Range coordinates
     */

    class AER
    {
    public:
        double az{ 0. };    // radians
        double el{ 0. };    // radians
        double range{ 0. }; // meters

        /**
         * @brief Default Constructor
         */
        AER() = default;

        /**
         * @brief Constructor
         * @param inAz: az value in radians
         * @param inEl: el value in radians
         * @param inRange: the range in meters
         */
        // NOTLINTNEXTLINE(bugprone-easily-swappable-parameters)
        constexpr AER(double inAz, double inEl, double inRange = 1.) noexcept :
            az(inAz),
            el(inEl),
            range(inRange)
        {
        }

        /**
         * @brief Non-Equality Operator
         *
         * @param other: other object
         * @return bool true if not equal equal
         */
        bool operator==(const AER& other) const noexcept
        {
            return utils::essentiallyEqual(az, other.az) && utils::essentiallyEqual(el, other.el) &&
                   utils::essentiallyEqual(range, other.range);
        }

        /**
         * @brief Non-Equality Operator
         *
         * @param other: other object
         * @return bool true if not equal equal
         */
        bool operator!=(const AER& other) const noexcept
        {
            return !(*this == other);
        }
    };

    /**
     * @brief Stream operator
     *
     * @param os: the output stream
     * @param point: the AER point
     */
    inline std::ostream& operator<<(std::ostream& os, const AER& point)
    {
        os << "AER(az=" << point.az << ", el=" << point.el << ", range=" << point.range << ")\n";
        return os;
    }

} // namespace nc::coordinates::reference_frames
