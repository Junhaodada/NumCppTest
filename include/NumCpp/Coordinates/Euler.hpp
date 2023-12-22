
/// Description
/// Euler
///
#pragma once

#include <iostream>

#include "NumCpp/Utils/essentiallyEqual.hpp"

namespace nc::coordinates
{
    /**
     * @brief Euler
     */
    class Euler
    {
    public:
        double psi{ 0. };
        double theta{ 0. };
        double phi{ 0. };

        /**
         * @brief Default Constructor
         */
        Euler() noexcept = default;

        /**
         * @brief Constructor
         *
         * @param inPsi: the psi component
         * @param inTheta: the theta component
         * @param inPhi: the phi component
         */
        constexpr Euler(double inPsi, double inTheta, double inPhi) noexcept :
            psi(inPsi),
            theta(inTheta),
            phi(inPhi)
        {
        }

        /**
         * @brief Copy Constructor
         *
         * @param other: the other Euler instance
         */
        Euler(const Euler& other) noexcept = default;

        /**
         * @brief Move Euler
         *
         * @param other: the other Euler instance
         */
        Euler(Euler&& other) noexcept = default;

        /**
         * @brief Destructor
         */
        virtual ~Euler() = default;

        /**
         * @brief Copy Assignement Operator
         *
         * @param other: the other Euler instance
         */
        Euler& operator=(const Euler& other) noexcept = default;

        /**
         * @brief Move Assignement Operator
         *
         * @param other: the other Euler instance
         */
        Euler& operator=(Euler&& other) noexcept = default;

        /**
         * @brief Non-Equality Operator
         *
         * @param other: other object
         * @return bool true if not equal equal
         */
        bool operator==(const Euler& other) const noexcept
        {
            return utils::essentiallyEqual(psi, other.psi) && utils::essentiallyEqual(theta, other.theta) &&
                   utils::essentiallyEqual(phi, other.phi);
        }

        /**
         * @brief Non-Equality Operator
         *
         * @param other: other object
         * @return bool true if not equal equal
         */
        bool operator!=(const Euler& other) const noexcept
        {
            return !(*this == other);
        }
    };

    /**
     * @brief Stream operator
     *
     * @param os: the output stream
     * @param Euler: the euler angles
     */
    inline std::ostream& operator<<(std::ostream& os, const Euler& Euler)
    {
        os << "Euler(psi=" << Euler.psi << ", theta=" << Euler.theta << ", phi=" << Euler.phi << ")\n";
        return os;
    }
} // namespace nc::coordinates
