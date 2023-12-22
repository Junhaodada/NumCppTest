
/// Description
/// "laplace" distrubution.
///
#pragma once

#ifndef NUMCPP_NO_USE_BOOST

#include <algorithm>

#include "boost/random/laplace_distribution.hpp"

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
        /// Single random value sampled from the "laplace" distrubution.
        /// NOTE: Use of this function requires using the Boost includes.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.laplace.html#numpy.random.laplace
        ///
        /// @param generator: instance of a random number generator
        /// @param inLoc: (The position, mu, of the distribution peak. Default is 0)
        /// @param inScale: (float optional the exponential decay. Default is 1)
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        dtype laplace(GeneratorType& generator, dtype inLoc = 0, dtype inScale = 1)
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            boost::random::laplace_distribution<dtype> dist(inLoc, inScale);
            return dist(generator);
        }

        //============================================================================
        // Method Description:
        /// Create an array of the given shape and populate it with
        /// random samples from a "laplace" distrubution.
        /// NOTE: Use of this function requires using the Boost includes.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.laplace.html#numpy.random.laplace
        ///
        /// @param generator: instance of a random number generator
        /// @param inShape
        /// @param inLoc: (The position, mu, of the distribution peak. Default is 0)
        /// @param inScale: (float optional the exponential decay. Default is 1)
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype> laplace(GeneratorType& generator, const Shape& inShape, dtype inLoc = 0, dtype inScale = 1)
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            NdArray<dtype> returnArray(inShape);

            boost::random::laplace_distribution<dtype> dist(inLoc, inScale);

            std::for_each(returnArray.begin(),
                          returnArray.end(),
                          [&generator, &dist](dtype& value) -> void { value = dist(generator); });

            return returnArray;
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Single random value sampled from the "laplace" distrubution.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.laplace.html#numpy.random.laplace
    ///
    /// @param inLoc: (The position, mu, of the distribution peak. Default is 0)
    /// @param inScale: (float optional the exponential decay. Default is 1)
    /// @return NdArray
    ///
    template<typename dtype>
    dtype laplace(dtype inLoc = 0, dtype inScale = 1)
    {
        return detail::laplace(generator_, inLoc, inScale);
    }

    //============================================================================
    // Method Description:
    /// Create an array of the given shape and populate it with
    /// random samples from a "laplace" distrubution.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.laplace.html#numpy.random.laplace
    ///
    /// @param inShape
    /// @param inLoc: (The position, mu, of the distribution peak. Default is 0)
    /// @param inScale: (float optional the exponential decay. Default is 1)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> laplace(const Shape& inShape, dtype inLoc = 0, dtype inScale = 1)
    {
        return detail::laplace(generator_, inShape, inLoc, inScale);
    }
} // namespace nc::random

#endif // #ifndef NUMCPP_NO_USE_BOOST
