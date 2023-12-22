
/// Description
/// "student-T" distribution
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
        // Method Description:
        /// Single random value sampled from the "student-T" distribution.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.standard_t.html#numpy.random.standard_t
        ///
        /// @param generator: instance of a random number generator
        /// @param inDof independent random variables
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        dtype studentT(GeneratorType& generator, dtype inDof)
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            if (inDof <= 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("degrees of freedom must be greater than zero.");
            }

            std::student_t_distribution<dtype> dist(inDof);
            return dist(generator);
        }

        //============================================================================
        // Method Description:
        /// Create an array of the given shape and populate it with
        /// random samples from the "student-T" distribution.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.standard_t.html#numpy.random.standard_t
        ///
        /// @param generator: instance of a random number generator
        /// @param inShape
        /// @param inDof independent random variables
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype> studentT(GeneratorType& generator, const Shape& inShape, dtype inDof)
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            if (inDof <= 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("degrees of freedom must be greater than zero.");
            }

            NdArray<dtype> returnArray(inShape);

            std::student_t_distribution<dtype> dist(inDof);

            std::for_each(returnArray.begin(),
                          returnArray.end(),
                          [&generator, &dist](dtype& value) -> void { value = dist(generator); });

            return returnArray;
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Single random value sampled from the "student-T" distribution.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.standard_t.html#numpy.random.standard_t
    ///
    /// @param inDof independent random variables
    /// @return NdArray
    ///
    template<typename dtype>
    dtype studentT(dtype inDof)
    {
        return detail::studentT(generator_, inDof);
    }

    //============================================================================
    // Method Description:
    /// Create an array of the given shape and populate it with
    /// random samples from the "student-T" distribution.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.standard_t.html#numpy.random.standard_t
    ///
    /// @param inShape
    /// @param inDof independent random variables
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> studentT(const Shape& inShape, dtype inDof)
    {
        return detail::studentT(generator_, inShape, inDof);
    }
} // namespace nc::random
