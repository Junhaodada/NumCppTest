
/// Description
/// NED Object
///
#pragma once

#include <iostream>

#include "NumCpp/Coordinates/Cartesian.hpp"

namespace nc::coordinates::reference_frames
{
    /**
     * @brief North east down coordinates
     */
    class NED final : public Cartesian
    {
    public:
        using Cartesian::Cartesian;

        /**
         * @brief Constructor
         * @param cartesian: cartesian vector
         */
        constexpr NED(const Cartesian& cartesian) noexcept :
            Cartesian(cartesian)
        {
        }

        /**
         * @brief Constructor
         * @param north: north value
         * @param east: east value
         * @param down: down value
         */
        // NOTLINTNEXTLINE(bugprone-easily-swappable-parameters)
        constexpr NED(double north, double east, double down) noexcept :
            Cartesian(north, east, down)
        {
        }

        /**
         * @brief north getter
         *
         * @return north
         */
        [[nodiscard]] double north() const noexcept
        {
            return x;
        }

        /**
         * @brief north setter
         *
         * @param north: north value
         */
        void setNorth(double north) noexcept
        {
            x = north;
        }

        /**
         * @brief east getter
         *
         * @return double
         */
        [[nodiscard]] double east() const noexcept
        {
            return y;
        }

        /**
         * @brief east setter
         *
         * @param east: east value
         */
        void setEast(double east) noexcept
        {
            y = east;
        }

        /**
         * @brief down getter
         *
         * @return down
         */
        [[nodiscard]] double down() const noexcept
        {
            return z;
        }

        /**
         * @brief down setter
         *
         * @param down: down value
         */
        void setDown(double down) noexcept
        {
            z = down;
        }
    };
} // namespace nc::coordinates::reference_frames
