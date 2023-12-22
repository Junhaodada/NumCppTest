
/// Description
/// "bernoulli" distribution.
///
#pragma once

#include <algorithm>
#include <random>
#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Random/generator.hpp"

namespace nc::random
{
    namespace detail
    {
        //============================================================================
        // Method Description:
        /// Single random value sampled from the "bernoulli" distribution.
        ///
        /// @param generator: instance of a random number generator
        /// @param inP (probability of success [0, 1]). Default 0.5
        /// @return NdArray
        ///
        template<typename GeneratorType = std::mt19937>
        bool bernoulli(GeneratorType& generator, double inP = 0.5)
        {
            if (inP < 0 || inP > 1)
            {
                THROW_INVALID_ARGUMENT_ERROR("input probability of success must be of the range [0, 1].");
            }

            std::bernoulli_distribution dist(inP);
            return dist(generator);
        }

        //============================================================================
        // Method Description:
        /// Create an array of the given shape and populate it with
        /// random samples from the "bernoulli" distribution.
        ///
        /// @param generator: instance of a random number generator
        /// @param inShape
        /// @param inP (probability of success [0, 1]). Default 0.5
        /// @return NdArray
        ///
        template<typename GeneratorType = std::mt19937>
        NdArray<bool> bernoulli(GeneratorType& generator, const Shape& inShape, double inP = 0.5)
        {
            if (inP < 0 || inP > 1)
            {
                THROW_INVALID_ARGUMENT_ERROR("input probability of success must be of the range [0, 1].");
            }

            NdArray<bool> returnArray(inShape);

            std::bernoulli_distribution dist(inP);

            std::for_each(returnArray.begin(),
                          returnArray.end(),
                          [&generator, &dist](bool& value) -> void { value = dist(generator); });

            return returnArray;
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Single random value sampled from the "bernoulli" distribution.
    ///
    /// @param inP (probability of success [0, 1]). Default 0.5
    /// @return NdArray
    ///
    inline bool bernoulli(double inP = 0.5)
    {
        return detail::bernoulli(generator_, inP);
    }

    //============================================================================
    // Method Description:
    /// Create an array of the given shape and populate it with
    /// random samples from the "bernoulli" distribution.
    ///
    /// @param inShape
    /// @param inP (probability of success [0, 1]). Default 0.5
    /// @return NdArray
    ///
    inline NdArray<bool> bernoulli(const Shape& inShape, double inP = 0.5)
    {
        return detail::bernoulli(generator_, inShape, inP);
    }
} // namespace nc::random
