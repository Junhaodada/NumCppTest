
/// Description
/// Draw samples from a uniform distribution.
///
#pragma once

#include "NumCpp/Core/DtypeInfo.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Random/randFloat.hpp"

namespace nc::random
{
    namespace detail
    {
        //============================================================================
        // Method Description:
        /// Draw sample from a uniform distribution.
        ///
        /// Samples are uniformly distributed over the half -
        /// open interval[low, high) (includes low, but excludes high)
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.uniform.html#numpy.random.uniform
        ///
        /// @param generator: instance of a random number generator
        /// @param inLow
        /// @param inHigh
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        dtype uniform(GeneratorType& generator, dtype inLow, dtype inHigh)
        {
            STATIC_ASSERT_FLOAT(dtype);

            return detail::randFloat(generator, inLow, inHigh);
        }

        //============================================================================
        // Method Description:
        /// Draw samples from a uniform distribution.
        ///
        /// Samples are uniformly distributed over the half -
        /// open interval[low, high) (includes low, but excludes high)
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.uniform.html#numpy.random.uniform
        ///
        /// @param generator: instance of a random number generator
        /// @param inShape
        /// @param inLow
        /// @param inHigh
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype> uniform(GeneratorType& generator, const Shape& inShape, dtype inLow, dtype inHigh)
        {
            STATIC_ASSERT_FLOAT(dtype);

            return detail::randFloat(generator, inShape, inLow, inHigh);
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Draw sample from a uniform distribution.
    ///
    /// Samples are uniformly distributed over the half -
    /// open interval[low, high) (includes low, but excludes high)
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.uniform.html#numpy.random.uniform
    ///
    /// @param inLow
    /// @param inHigh
    /// @return NdArray
    ///
    template<typename dtype>
    dtype uniform(dtype inLow, dtype inHigh)
    {
        return detail::uniform(generator_, inLow, inHigh);
    }

    //============================================================================
    // Method Description:
    /// Draw samples from a uniform distribution.
    ///
    /// Samples are uniformly distributed over the half -
    /// open interval[low, high) (includes low, but excludes high)
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.uniform.html#numpy.random.uniform
    ///
    /// @param inShape
    /// @param inLow
    /// @param inHigh
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> uniform(const Shape& inShape, dtype inLow, dtype inHigh)
    {
        return detail::uniform(generator_, inShape, inLow, inHigh);
    }
} // namespace nc::random
