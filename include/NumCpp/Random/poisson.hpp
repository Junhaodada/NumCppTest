
/// Description
/// "poisson" distribution
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
        /// Single random value sampled from the "poisson" distribution.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.poisson.html#numpy.random.poisson
        ///
        /// @param generator: instance of a random number generator
        /// @param inMean (default 1)
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        dtype poisson(GeneratorType& generator, double inMean = 1)
        {
            STATIC_ASSERT_INTEGER(dtype);

            if (inMean <= 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input mean must be greater than zero.");
            }

            std::poisson_distribution<dtype> dist(inMean);
            return dist(generator);
        }

        //============================================================================
        // Method Description:
        /// Create an array of the given shape and populate it with
        /// random samples from the "poisson" distribution.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.poisson.html#numpy.random.poisson
        ///
        /// @param generator: instance of a random number generator
        /// @param inShape
        /// @param inMean (default 1)
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype> poisson(GeneratorType& generator, const Shape& inShape, double inMean = 1)
        {
            STATIC_ASSERT_INTEGER(dtype);

            if (inMean <= 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input mean must be greater than zero.");
            }

            NdArray<dtype> returnArray(inShape);

            std::poisson_distribution<dtype> dist(inMean);

            std::for_each(returnArray.begin(),
                          returnArray.end(),
                          [&generator, &dist](dtype& value) -> void { value = dist(generator); });

            return returnArray;
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Single random value sampled from the "poisson" distribution.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.poisson.html#numpy.random.poisson
    ///
    /// @param inMean (default 1)
    /// @return NdArray
    ///
    template<typename dtype>
    dtype poisson(double inMean = 1)
    {
        return detail::poisson<dtype>(generator_, inMean);
    }

    //============================================================================
    // Method Description:
    /// Create an array of the given shape and populate it with
    /// random samples from the "poisson" distribution.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.poisson.html#numpy.random.poisson
    ///
    /// @param inShape
    /// @param inMean (default 1)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> poisson(const Shape& inShape, double inMean = 1)
    {
        return detail::poisson<dtype>(generator_, inShape, inMean);
    }
} // namespace nc::random
