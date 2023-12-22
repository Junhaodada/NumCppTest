
/// Description
/// "F" distrubution.
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
        /// Single random value sampled from the "F" distrubution.
        ///
        /// NumPy Reference: https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.f.html#numpy.random.f
        ///
        /// @param generator: instance of a random number generator
        /// @param inDofN: Degrees of freedom in numerator. Should be greater than zero.
        /// @param inDofD: Degrees of freedom in denominator. Should be greater than zero.
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        dtype f(GeneratorType& generator, dtype inDofN, dtype inDofD)
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            if (inDofN <= 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("numerator degrees of freedom should be greater than zero.");
            }

            if (inDofD <= 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("denominator degrees of freedom should be greater than zero.");
            }

            std::fisher_f_distribution<dtype> dist(inDofN, inDofD);
            return dist(generator);
        }

        //============================================================================
        // Method Description:
        /// Create an array of the given shape and populate it with
        /// random samples from a "F" distrubution.
        ///
        /// NumPy Reference: https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.f.html#numpy.random.f
        ///
        /// @param generator: instance of a random number generator
        /// @param inShape
        /// @param inDofN: Degrees of freedom in numerator. Should be greater than zero.
        /// @param inDofD: Degrees of freedom in denominator. Should be greater than zero.
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype> f(GeneratorType& generator, const Shape& inShape, dtype inDofN, dtype inDofD)
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            if (inDofN <= 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("numerator degrees of freedom should be greater than zero.");
            }

            if (inDofD <= 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("denominator degrees of freedom should be greater than zero.");
            }

            NdArray<dtype> returnArray(inShape);

            std::fisher_f_distribution<dtype> dist(inDofN, inDofD);

            std::for_each(returnArray.begin(),
                          returnArray.end(),
                          [&generator, &dist](dtype& value) -> void { value = dist(generator); });

            return returnArray;
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Single random value sampled from the "F" distrubution.
    ///
    /// NumPy Reference: https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.f.html#numpy.random.f
    ///
    /// @param inDofN: Degrees of freedom in numerator. Should be greater than zero.
    /// @param inDofD: Degrees of freedom in denominator. Should be greater than zero.
    /// @return NdArray
    ///
    template<typename dtype>
    dtype f(dtype inDofN, dtype inDofD)
    {
        return detail::f(generator_, inDofN, inDofD);
    }

    //============================================================================
    // Method Description:
    /// Create an array of the given shape and populate it with
    /// random samples from a "F" distrubution.
    ///
    /// NumPy Reference: https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.f.html#numpy.random.f
    ///
    /// @param inShape
    /// @param inDofN: Degrees of freedom in numerator. Should be greater than zero.
    /// @param inDofD: Degrees of freedom in denominator. Should be greater than zero.
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> f(const Shape& inShape, dtype inDofN, dtype inDofD)
    {
        return detail::f(generator_, inShape, inDofN, inDofD);
    }
} // namespace nc::random
