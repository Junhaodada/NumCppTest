
/// Description
/// Create an array of the given shape and populate it with
/// random samples from the "triangle" distribution.
///
#pragma once

#ifndef NUMCPP_NO_USE_BOOST

#include <algorithm>
#include <string>

#include "boost/random/triangle_distribution.hpp"

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
        /// Single random value sampled from the "triangle" distribution.
        /// NOTE: Use of this function requires using the Boost includes.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.triangular.html#numpy.random.triangular
        ///
        /// @param generator: instance of a random number generator
        /// @param inA
        /// @param inB
        /// @param inC
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        dtype triangle(GeneratorType& generator, dtype inA = 0, dtype inB = 0.5, dtype inC = 1)
        {
            STATIC_ASSERT_FLOAT(dtype);

            if (inA < 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input A must be greater than or equal to zero.");
            }

            if (inB < 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input B must be greater than or equal to zero.");
            }

            if (inC < 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input C must be greater than or equal to zero.");
            }

            const bool aLessB = inA <= inB;
            const bool bLessC = inB <= inC;
            if (!(aLessB && bLessC))
            {
                THROW_INVALID_ARGUMENT_ERROR("inputs must be a <= b <= c.");
            }

            boost::random::triangle_distribution<dtype> dist(inA, inB, inC);
            return dist(generator);
        }

        //============================================================================
        // Method Description:
        /// Create an array of the given shape and populate it with
        /// random samples from the "triangle" distribution.
        /// NOTE: Use of this function requires using the Boost includes.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.triangular.html#numpy.random.triangular
        ///
        /// @param generator: instance of a random number generator
        /// @param inShape
        /// @param inA
        /// @param inB
        /// @param inC
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype>
            triangle(GeneratorType& generator, const Shape& inShape, dtype inA = 0, dtype inB = 0.5, dtype inC = 1)
        {
            STATIC_ASSERT_FLOAT(dtype);

            if (inA < 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input A must be greater than or equal to zero.");
            }

            if (inB < 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input B must be greater than or equal to zero.");
            }

            if (inC < 0)
            {
                THROW_INVALID_ARGUMENT_ERROR("input C must be greater than or equal to zero.");
            }

            const bool aLessB = inA <= inB;
            const bool bLessC = inB <= inC;
            if (!(aLessB && bLessC))
            {
                THROW_INVALID_ARGUMENT_ERROR("inputs must be a <= b <= c.");
            }

            NdArray<dtype> returnArray(inShape);

            boost::random::triangle_distribution<dtype> dist(inA, inB, inC);

            std::for_each(returnArray.begin(),
                          returnArray.end(),
                          [&generator, &dist](dtype& value) -> void { value = dist(generator); });

            return returnArray;
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Single random value sampled from the "triangle" distribution.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.triangular.html#numpy.random.triangular
    ///
    /// @param inA
    /// @param inB
    /// @param inC
    /// @return NdArray
    ///
    template<typename dtype>
    dtype triangle(dtype inA = 0, dtype inB = 0.5, dtype inC = 1)
    {
        return detail::triangle(generator_, inA, inB, inC);
    }

    //============================================================================
    // Method Description:
    /// Create an array of the given shape and populate it with
    /// random samples from the "triangle" distribution.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.triangular.html#numpy.random.triangular
    ///
    /// @param inShape
    /// @param inA
    /// @param inB
    /// @param inC
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> triangle(const Shape& inShape, dtype inA = 0, dtype inB = 0.5, dtype inC = 1)
    {
        return detail::triangle(generator_, inShape, inA, inB, inC);
    }
} // namespace nc::random

#endif // #ifndef NUMCPP_NO_USE_BOOST
