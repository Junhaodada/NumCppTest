
/// Description
/// "exponential" distrubution
///
#pragma once

#include <algorithm>
#include <random>

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
        /// Single random value sampled from the "exponential" distrubution.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.exponential.html#numpy.random.exponential
        ///
        /// @param generator: instance of a random number generator
        /// @param inScaleValue (default 1)
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        dtype exponential(GeneratorType& generator, dtype inScaleValue = 1)
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            std::exponential_distribution<dtype> dist(inScaleValue);
            return dist(generator);
        }

        //============================================================================
        // Method Description:
        /// Create an array of the given shape and populate it with
        /// random samples from a "exponential" distrubution.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.exponential.html#numpy.random.exponential
        ///
        /// @param generator: instance of a random number generator
        /// @param inShape
        /// @param inScaleValue (default 1)
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype> exponential(GeneratorType& generator, const Shape& inShape, dtype inScaleValue = 1)
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            NdArray<dtype> returnArray(inShape);

            std::exponential_distribution<dtype> dist(inScaleValue);

            std::for_each(returnArray.begin(),
                          returnArray.end(),
                          [&generator, &dist](dtype& value) -> void { value = dist(generator); });

            return returnArray;
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Single random value sampled from the "exponential" distrubution.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.exponential.html#numpy.random.exponential
    ///
    /// @param inScaleValue (default 1)
    /// @return NdArray
    ///
    template<typename dtype>
    dtype exponential(dtype inScaleValue = 1)
    {
        return detail::exponential(generator_, inScaleValue);
    }

    //============================================================================
    // Method Description:
    /// Create an array of the given shape and populate it with
    /// random samples from a "exponential" distrubution.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.exponential.html#numpy.random.exponential
    ///
    /// @param inShape
    /// @param inScaleValue (default 1)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> exponential(const Shape& inShape, dtype inScaleValue = 1)
    {
        return detail::exponential(generator_, inShape, inScaleValue);
    }
} // namespace nc::random
