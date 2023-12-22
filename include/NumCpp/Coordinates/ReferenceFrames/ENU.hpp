
/// Description
/// ENU Object
///
#pragma once

#include <iostream>

#include "NumCpp/Coordinates/Cartesian.hpp"

namespace nc::coordinates::reference_frames
{
    /**
     * @brief East North Up coordinates
     */
    class ENU final : public Cartesian
    {
    public:
        using Cartesian::Cartesian;

        /**
         * @brief Constructor
         * @param cartesian: cartesian vector
         */
        constexpr ENU(const Cartesian& cartesian) noexcept :
            Cartesian(cartesian)
        {
        }

        /**
         * @brief Constructor
         * @param east: east value
         * @param north: north value
         * @param up: up value
         */
        // NOTLINTNEXTLINE(bugprone-easily-swappable-parameters)
        constexpr ENU(double east, double north, double up) noexcept :
            Cartesian(east, north, up)
        {
        }

        /**
         * @brief east getter
         *
         * @return east
         */
        [[nodiscard]] double east() const noexcept
        {
            return x;
        }

        /**
         * @brief east setter
         *
         * @param east: east value
         */
        void setEast(double east) noexcept
        {
            x = east;
        }

        /**
         * @brief north getter
         *
         * @return double
         */
        [[nodiscard]] double north() const noexcept
        {
            return y;
        }

        /**
         * @brief north setter
         *
         * @param north: north value
         */
        void setNorth(double north) noexcept
        {
            y = north;
        }

        /**
         * @brief up getter
         *
         * @return up
         */
        [[nodiscard]] double up() const noexcept
        {
            return z;
        }

        /**
         * @brief up setter
         *
         * @param up: up value
         */
        void setUp(double up) noexcept
        {
            z = up;
        }
    };

    /**
     * @brief Stream operator
     *
     * @param os: the output stream
     * @param point: the ENU point
     */
    inline std::ostream& operator<<(std::ostream& os, const ENU& point)
    {
        os << "ENU(east=" << point.east() << ", north=" << point.north() << ", up=" << point.up() << ")\n";
        return os;
    }
} // namespace nc::coordinates::reference_frames
