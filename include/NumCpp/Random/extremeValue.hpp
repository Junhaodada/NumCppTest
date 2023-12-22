
/// Description
/// "extreme value" distrubution.
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
        /// Single random value sampled from the "extreme value" distrubution.
        ///
        /// @param generator: instance of a random number generator
        /// @param inA (default 1)
        /// @param inB (default 1)
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        dtype extremeValue(GeneratorType& generator, dtype inA = 1, dtype inB = 1)
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            if (inA <= 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input a must be greater than zero.");
            }

            if (inB <= 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input b must be greater than zero.");
            }

            std::extreme_value_distribution<dtype> dist(inA, inB);
            return dist(generator);
        }

        //============================================================================
        // Method Description:
        /// Create an array of the given shape and populate it with
        /// random samples from a "extreme value" distrubution.
        ///
        /// @param generator: instance of a random number generator
        /// @param inShape
        /// @param inA (default 1)
        /// @param inB (default 1)
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype> extremeValue(GeneratorType& generator, const Shape& inShape, dtype inA = 1, dtype inB = 1)
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            if (inA <= 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input a must be greater than zero.");
            }

            if (inB <= 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input b must be greater than zero.");
            }

            NdArray<dtype> returnArray(inShape);

            std::extreme_value_distribution<dtype> dist(inA, inB);

            std::for_each(returnArray.begin(),
                          returnArray.end(),
                          [&generator, &dist](dtype& value) -> void { value = dist(generator); });

            return returnArray;
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Single random value sampled from the "extreme value" distrubution.
    ///
    /// @param inA (default 1)
    /// @param inB (default 1)
    /// @return NdArray
    ///
    template<typename dtype>
    dtype extremeValue(dtype inA = 1, dtype inB = 1)
    {
        return detail::extremeValue<dtype>(generator_, inA, inB);
    }

    //============================================================================
    // Method Description:
    /// Create an array of the given shape and populate it with
    /// random samples from a "extreme value" distrubution.
    ///
    /// @param inShape
    /// @param inA (default 1)
    /// @param inB (default 1)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> extremeValue(const Shape& inShape, dtype inA = 1, dtype inB = 1)
    {
        return detail::extremeValue<dtype>(generator_, inShape, inA, inB);
    }
} // namespace nc::random
