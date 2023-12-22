
/// Description
/// ECEF Object
///
#pragma once

#include <iostream>

#include "NumCpp/Coordinates/Cartesian.hpp"

namespace nc::coordinates::reference_frames
{
    /**
     * @brief ECEF coordinates
     */
    class ECEF final : public Cartesian
    {
    public:
        using Cartesian::Cartesian;

        /**
         * @brief Constructor
         * @param cartesian: cartesian vector
         */
        constexpr ECEF(const Cartesian& cartesian) noexcept :
            Cartesian(cartesian)
        {
        }
    };
} // namespace nc::coordinates::reference_frames
