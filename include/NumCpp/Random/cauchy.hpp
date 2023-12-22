
/// Description
/// "cauchy" distrubution.
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
        /// Single random value sampled from the from the "cauchy" distrubution.
        ///
        /// @param generator: instance of a random number generator
        /// @param inMean: Mean value of the underlying normal distribution. Default is 0.
        /// @param inSigma: Standard deviation of the underlying normal distribution. Should be greater than zero.
        /// Default is 1.
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        dtype cauchy(GeneratorType& generator, dtype inMean = 0, dtype inSigma = 1)
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            if (inSigma <= 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input sigma must be greater than zero.");
            }

            std::cauchy_distribution<dtype> dist(inMean, inSigma);
            return dist(generator);
        }

        //============================================================================
        // Method Description:
        /// Create an array of the given shape and populate it with
        /// random samples from a "cauchy" distrubution.
        ///
        /// @param generator: instance of a random number generator
        /// @param inShape
        /// @param inMean: Mean value of the underlying normal distribution. Default is 0.
        /// @param inSigma: Standard deviation of the underlying normal distribution. Should be greater than zero.
        /// Default is 1.
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype> cauchy(GeneratorType& generator, const Shape& inShape, dtype inMean = 0, dtype inSigma = 1)
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            if (inSigma <= 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input sigma must be greater than zero.");
            }

            NdArray<dtype> returnArray(inShape);

            std::cauchy_distribution<dtype> dist(inMean, inSigma);

            std::for_each(returnArray.begin(),
                          returnArray.end(),
                          [&generator, &dist](dtype& value) -> void { value = dist(generator); });

            return returnArray;
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Single random value sampled from the from the "cauchy" distrubution.
    ///
    /// @param inMean: Mean value of the underlying normal distribution. Default is 0.
    /// @param inSigma: Standard deviation of the underlying normal distribution. Should be greater than zero.
    /// Default is 1.
    /// @return NdArray
    ///
    template<typename dtype>
    dtype cauchy(dtype inMean = 0, dtype inSigma = 1)
    {
        return detail::cauchy(generator_, inMean, inSigma);
    }

    //============================================================================
    // Method Description:
    /// Create an array of the given shape and populate it with
    /// random samples from a "cauchy" distrubution.
    ///
    /// @param inShape
    /// @param inMean: Mean value of the underlying normal distribution. Default is 0.
    /// @param inSigma: Standard deviation of the underlying normal distribution. Should be greater than zero.
    /// Default is 1.
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> cauchy(const Shape& inShape, dtype inMean = 0, dtype inSigma = 1)
    {
        return detail::cauchy(generator_, inShape, inMean, inSigma);
    }
} // namespace nc::random
