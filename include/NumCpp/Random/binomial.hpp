
/// Description
/// "binomial" distribution.
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
        /// Single random value sampled from the from the "binomial" distribution.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.binomial.html#numpy.random.binomial
        ///
        /// @param generator: instance of a random number generator
        /// @param inN (number of trials)
        /// @param inP (probablity of success [0, 1])
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        dtype binomial(GeneratorType& generator, dtype inN, double inP = 0.5)
        {
            STATIC_ASSERT_INTEGER(dtype);

            if (inN < 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input number of trials must be greater than or equal to zero.");
            }

            if (inP < 0 || inP > 1)
            {
                THROW_INVALID_ARGUMENT_ERROR("input probability of sucess must be of the range [0, 1].");
            }

            std::binomial_distribution<dtype> dist(inN, inP);
            return dist(generator);
        }

        //============================================================================
        // Method Description:
        /// Create an array of the given shape and populate it with
        /// random samples from the "binomial" distribution.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.binomial.html#numpy.random.binomial
        ///
        /// @param generator: instance of a random number generator
        /// @param inShape
        /// @param inN (number of trials)
        /// @param inP (probablity of success [0, 1])
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype> binomial(GeneratorType& generator, const Shape& inShape, dtype inN, double inP = 0.5)
        {
            STATIC_ASSERT_INTEGER(dtype);

            if (inN < 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input number of trials must be greater than or equal to zero.");
            }

            if (inP < 0 || inP > 1)
            {
                THROW_INVALID_ARGUMENT_ERROR("input probability of sucess must be of the range [0, 1].");
            }

            NdArray<dtype> returnArray(inShape);

            std::binomial_distribution<dtype> dist(inN, inP);

            std::for_each(returnArray.begin(),
                          returnArray.end(),
                          [&generator, &dist](dtype& value) -> void { value = dist(generator); });

            return returnArray;
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Single random value sampled from the from the "binomial" distribution.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.binomial.html#numpy.random.binomial
    ///
    /// @param inN (number of trials)
    /// @param inP (probablity of success [0, 1])
    /// @return NdArray
    ///
    template<typename dtype>
    dtype binomial(dtype inN, double inP = 0.5)
    {
        return detail::binomial(generator_, inN, inP);
    }

    //============================================================================
    // Method Description:
    /// Create an array of the given shape and populate it with
    /// random samples from the "binomial" distribution.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.binomial.html#numpy.random.binomial
    ///
    /// @param inShape
    /// @param inN (number of trials)
    /// @param inP (probablity of success [0, 1])
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> binomial(const Shape& inShape, dtype inN, double inP = 0.5)
    {
        return detail::binomial(generator_, inShape, inN, inP);
    }
} // namespace nc::random
