
/// Description
/// "negative Binomial" distribution.
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
        /// Single random value sampled from the "negative Binomial" distribution.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.negative_binomial.html#numpy.random.negative_binomial
        ///
        /// @param generator: instance of a random number generator
        /// @param inN: number of trials
        /// @param inP: probablity of success [0, 1]
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        dtype negativeBinomial(GeneratorType& generator, dtype inN, double inP = 0.5)
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

            std::negative_binomial_distribution<dtype> dist(inN, inP);
            return dist(generator);
        }

        //============================================================================
        // Method Description:
        /// Create an array of the given shape and populate it with
        /// random samples from the "negative Binomial" distribution.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.negative_binomial.html#numpy.random.negative_binomial
        ///
        /// @param generator: instance of a random number generator
        /// @param inShape
        /// @param inN: number of trials
        /// @param inP: probablity of success [0, 1]
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype> negativeBinomial(GeneratorType& generator, const Shape& inShape, dtype inN, double inP = 0.5)
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

            std::negative_binomial_distribution<dtype> dist(inN, inP);

            std::for_each(returnArray.begin(),
                          returnArray.end(),
                          [&generator, &dist](dtype& value) -> void { value = dist(generator); });

            return returnArray;
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Single random value sampled from the "negative Binomial" distribution.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.negative_binomial.html#numpy.random.negative_binomial
    ///
    /// @param inN: number of trials
    /// @param inP: probablity of success [0, 1]
    /// @return NdArray
    ///
    template<typename dtype>
    dtype negativeBinomial(dtype inN, double inP = 0.5)
    {
        return detail::negativeBinomial(generator_, inN, inP);
    }

    //============================================================================
    // Method Description:
    /// Create an array of the given shape and populate it with
    /// random samples from the "negative Binomial" distribution.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.negative_binomial.html#numpy.random.negative_binomial
    ///
    /// @param inShape
    /// @param inN: number of trials
    /// @param inP: probablity of success [0, 1]
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> negativeBinomial(const Shape& inShape, dtype inN, double inP = 0.5)
    {
        return detail::negativeBinomial(generator_, inShape, inN, inP);
    }
} // namespace nc::random
