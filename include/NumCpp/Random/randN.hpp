
/// Description
/// "standard normal" distribution.
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
        /// Returns a single random value sampled from the "standard normal" distribution.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.randn.html#numpy.random.randn
        ///
        /// @param generator: instance of a random number generator
        /// @return dtype
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        dtype randN(GeneratorType& generator)
        {
            STATIC_ASSERT_FLOAT(dtype);

            std::normal_distribution<dtype> dist;
            return dist(generator);
        }

        //============================================================================
        // Method Description:
        /// Create an array of the given shape and populate it with
        /// random samples from the "standard normal" distribution.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.randn.html#numpy.random.randn
        ///
        /// @param generator: instance of a random number generator
        /// @param inShape
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype> randN(GeneratorType& generator, const Shape& inShape)
        {
            STATIC_ASSERT_FLOAT(dtype);

            NdArray<dtype> returnArray(inShape);

            std::normal_distribution<dtype> dist;

            std::for_each(returnArray.begin(),
                          returnArray.end(),
                          [&generator, &dist](dtype& value) -> void { value = dist(generator); });

            return returnArray;
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Returns a single random value sampled from the "standard normal" distribution.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.randn.html#numpy.random.randn
    ///
    /// @return dtype
    ///
    template<typename dtype>
    dtype randN()
    {
        return detail::randN<dtype>(generator_);
    }

    //============================================================================
    // Method Description:
    /// Create an array of the given shape and populate it with
    /// random samples from the "standard normal" distribution.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.randn.html#numpy.random.randn
    ///
    /// @param inShape
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> randN(const Shape& inShape)
    {
        return detail::randN<dtype>(generator_, inShape);
    }
} // namespace nc::random
