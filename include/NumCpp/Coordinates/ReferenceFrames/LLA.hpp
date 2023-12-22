
/// Description
/// LLA Object
///
#pragma once

#include <iostream>

#include "NumCpp/Utils/essentiallyEqual.hpp"

namespace nc::coordinates::reference_frames
{
    /**
     * @brief Geodetic coordinates
     */
    class LLA
    {
    public:
        double latitude{ 0. };  // radians
        double longitude{ 0. }; // radians
        double altitude{ 0. };  // meters

        /**
         * @brief Default Constructor
         */
        LLA() = default;

        /**
         * @brief Constructor
         * @param inLatitude: latitude value in radians
         * @param inLongitude: longitude value in radians
         * @param inAltitude: altitude value in meters
         */
        // NOTLINTNEXTLINE(bugprone-easily-swappable-parameters)
        constexpr LLA(double inLatitude, double inLongitude, double inAltitude = 0.) noexcept :
            latitude(inLatitude),
            longitude(inLongitude),
            altitude(inAltitude)
        {
        }

        /**
         * @brief Non-Equality Operator
         *
         * @param other: other object
         * @return bool true if not equal equal
         */
        bool operator==(const LLA& other) const noexcept
        {
            return utils::essentiallyEqual(latitude, other.latitude) &&
                   utils::essentiallyEqual(longitude, other.longitude) &&
                   utils::essentiallyEqual(altitude, other.altitude);
        }

        /**
         * @brief Non-Equality Operator
         *
         * @param other: other object
         * @return bool true if not equal equal
         */
        bool operator!=(const LLA& other) const noexcept
        {
            return !(*this == other);
        }
    };

    /**
     * @brief Stream operator
     *
     * @param os: the output stream
     * @param point: the LLA point
     */
    inline std::ostream& operator<<(std::ostream& os, const LLA& point)
    {
        os << "LLA(latitude=" << point.latitude << ", longitude=" << point.longitude << ", altitude=" << point.altitude
           << ")\n";
        return os;
    }
} // namespace nc::coordinates::reference_frames
