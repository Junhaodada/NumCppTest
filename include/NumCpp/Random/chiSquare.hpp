
/// Description
/// "chi square" distribution.
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
        /// Single random value sampled from the from the "chi square" distribution.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.chisquare.html#numpy.random.chisquare
        ///
        /// @param generator: instance of a random number generator
        /// @param inDof (independent random variables)
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        dtype chiSquare(GeneratorType& generator, dtype inDof)
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            if (inDof <= 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("numerator degrees of freedom must be greater than zero.");
            }

            std::chi_squared_distribution<dtype> dist(inDof);
            return dist(generator);
        }

        //============================================================================
        // Method Description:
        /// Create an array of the given shape and populate it with
        /// random samples from the "chi square" distribution.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.chisquare.html#numpy.random.chisquare
        ///
        /// @param generator: instance of a random number generator
        /// @param inShape
        /// @param inDof (independent random variables)
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype> chiSquare(GeneratorType& generator, const Shape& inShape, dtype inDof)
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            if (inDof <= 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("numerator degrees of freedom must be greater than zero.");
            }

            NdArray<dtype> returnArray(inShape);

            std::chi_squared_distribution<dtype> dist(inDof);

            std::for_each(returnArray.begin(),
                          returnArray.end(),
                          [&generator, &dist](dtype& value) -> void { value = dist(generator); });

            return returnArray;
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Single random value sampled from the from the "chi square" distribution.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.chisquare.html#numpy.random.chisquare
    ///
    /// @param inDof (independent random variables)
    /// @return NdArray
    ///
    template<typename dtype>
    dtype chiSquare(dtype inDof)
    {
        return detail::chiSquare(generator_, inDof);
    }

    //============================================================================
    // Method Description:
    /// Create an array of the given shape and populate it with
    /// random samples from the "chi square" distribution.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.chisquare.html#numpy.random.chisquare
    ///
    /// @param inShape
    /// @param inDof (independent random variables)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> chiSquare(const Shape& inShape, dtype inDof)
    {
        return detail::chiSquare(generator_, inShape, inDof);
    }
} // namespace nc::random
