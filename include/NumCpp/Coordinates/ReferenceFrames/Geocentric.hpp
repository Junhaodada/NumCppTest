
/// Description
/// Geocentric Object
///
#pragma once

#include <iostream>

#include "NumCpp/Utils/essentiallyEqual.hpp"

namespace nc::coordinates::reference_frames
{
    /**
     * @brief Geocentric coordinates
     */
    class Geocentric
    {
    public:
        double latitude{ 0. };  // radians
        double longitude{ 0. }; // radians
        double radius{ 0. };    // meters

        /**
         * @brief Default Constructor
         */
        Geocentric() = default;

        /**
         * @brief Constructor
         * @param inLatitude: latitude value in radians
         * @param inLongitude: longitude value in radians
         * @param inRadius: radius value in meters
         */
        // NOTLINTNEXTLINE(bugprone-easily-swappable-parameters)
        constexpr Geocentric(double inLatitude, double inLongitude, double inRadius = 0.) noexcept :
            latitude(inLatitude),
            longitude(inLongitude),
            radius(inRadius)
        {
        }

        /**
         * @brief Non-Equality Operator
         *
         * @param other: other object
         * @return bool true if not equal equal
         */
        bool operator==(const Geocentric& other) const noexcept
        {
            return utils::essentiallyEqual(latitude, other.latitude) &&
                   utils::essentiallyEqual(longitude, other.longitude) && utils::essentiallyEqual(radius, other.radius);
        }

        /**
         * @brief Non-Equality Operator
         *
         * @param other: other object
         * @return bool true if not equal equal
         */
        bool operator!=(const Geocentric& other) const noexcept
        {
            return !(*this == other);
        }
    };

    /**
     * @brief Stream operator
     *
     * @param os: the output stream
     * @param point: the Geocentric point
     */
    inline std::ostream& operator<<(std::ostream& os, const Geocentric& point)
    {
        os << "Geocentric(latitude=" << point.latitude << ", longitude=" << point.longitude
           << ", radius=" << point.radius << ")\n";
        return os;
    }
} // namespace nc::coordinates::reference_frames
