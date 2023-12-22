
/// Description
/// "gamma" distrubution.
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
        /// Single random value sampled from the "gamma" distrubution.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.gamma.html#numpy.random.gamma
        ///
        /// @param generator: instance of a random number generator
        /// @param inGammaShape
        /// @param inScaleValue (default 1)
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        dtype gamma(GeneratorType& generator, dtype inGammaShape, dtype inScaleValue = 1)
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            if (inGammaShape <= 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input gamma shape should be greater than zero.");
            }

            if (inScaleValue <= 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input scale should be greater than zero.");
            }

            std::gamma_distribution<dtype> dist(inGammaShape, inScaleValue);
            return dist(generator);
        }

        //============================================================================
        // Method Description:
        /// Create an array of the given shape and populate it with
        /// random samples from a "gamma" distrubution.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.gamma.html#numpy.random.gamma
        ///
        /// @param generator: instance of a random number generator
        /// @param inShape
        /// @param inGammaShape
        /// @param inScaleValue (default 1)
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype> gamma(GeneratorType& generator, const Shape& inShape, dtype inGammaShape, dtype inScaleValue = 1)
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            if (inGammaShape <= 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input gamma shape should be greater than zero.");
            }

            if (inScaleValue <= 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input scale should be greater than zero.");
            }

            NdArray<dtype> returnArray(inShape);

            std::gamma_distribution<dtype> dist(inGammaShape, inScaleValue);

            std::for_each(returnArray.begin(),
                          returnArray.end(),
                          [&generator, &dist](dtype& value) -> void { value = dist(generator); });

            return returnArray;
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Single random value sampled from the "gamma" distrubution.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.gamma.html#numpy.random.gamma
    ///
    /// @param inGammaShape
    /// @param inScaleValue (default 1)
    /// @return NdArray
    ///
    template<typename dtype>
    dtype gamma(dtype inGammaShape, dtype inScaleValue = 1)
    {
        return detail::gamma(generator_, inGammaShape, inScaleValue);
    }

    //============================================================================
    // Method Description:
    /// Create an array of the given shape and populate it with
    /// random samples from a "gamma" distrubution.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.gamma.html#numpy.random.gamma
    ///
    /// @param inShape
    /// @param inGammaShape
    /// @param inScaleValue (default 1)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> gamma(const Shape& inShape, dtype inGammaShape, dtype inScaleValue = 1)
    {
        return detail::gamma(generator_, inShape, inGammaShape, inScaleValue);
    }
} // namespace nc::random
