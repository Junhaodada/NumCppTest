
/// Description
/// "beta" distribution.
///
#pragma once

#ifndef NUMCPP_NO_USE_BOOST

#include <algorithm>
#include <string>

#include "boost/random/beta_distribution.hpp"

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
        /// Single random value sampled from the from the "beta" distribution.
        /// NOTE: Use of this function requires using the Boost includes.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.beta.html#numpy.random.beta
        ///
        /// @param generator: instance of a random number generator
        /// @param inAlpha
        /// @param inBeta
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        dtype beta(GeneratorType& generator, dtype inAlpha, dtype inBeta)
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            if (inAlpha < 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input alpha must be greater than zero.");
            }

            if (inBeta < 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input beta must be greater than zero.");
            }

            boost::random::beta_distribution<dtype> dist(inAlpha, inBeta);
            return dist(generator);
        }

        //============================================================================
        // Method Description:
        /// Create an array of the given shape and populate it with
        /// random samples from the "beta" distribution.
        /// NOTE: Use of this function requires using the Boost includes.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.beta.html#numpy.random.beta
        ///
        /// @param generator: instance of a random number generator
        /// @param inShape
        /// @param inAlpha
        /// @param inBeta
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype> beta(GeneratorType& generator, const Shape& inShape, dtype inAlpha, dtype inBeta)
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            if (inAlpha < 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input alpha must be greater than zero.");
            }

            if (inBeta < 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input beta must be greater than zero.");
            }

            NdArray<dtype> returnArray(inShape);

            boost::random::beta_distribution<dtype> dist(inAlpha, inBeta);

            std::for_each(returnArray.begin(),
                          returnArray.end(),
                          [&generator, &dist](dtype& value) -> void { value = dist(generator); });

            return returnArray;
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Single random value sampled from the from the "beta" distribution.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.beta.html#numpy.random.beta
    ///
    /// @param inAlpha
    /// @param inBeta
    /// @return NdArray
    ///
    template<typename dtype>
    dtype beta(dtype inAlpha, dtype inBeta)
    {
        return detail::beta(generator_, inAlpha, inBeta);
    }

    //============================================================================
    // Method Description:
    /// Create an array of the given shape and populate it with
    /// random samples from the "beta" distribution.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.beta.html#numpy.random.beta
    ///
    /// @param inShape
    /// @param inAlpha
    /// @param inBeta
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> beta(const Shape& inShape, dtype inAlpha, dtype inBeta)
    {
        return detail::beta(generator_, inShape, inAlpha, inBeta);
    }
} // namespace nc::random

#endif // #ifndef NUMCPP_NO_USE_BOOST
