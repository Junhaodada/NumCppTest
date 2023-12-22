
/// Description
/// "geometric" distrubution.
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
        /// Single random value sampled from the "geometric" distrubution.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.geometric.html#numpy.random.geometric
        ///
        /// @param generator: instance of a random number generator
        /// @param inP (probablity of success [0, 1])
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        dtype geometric(GeneratorType& generator, double inP = 0.5)
        {
            STATIC_ASSERT_INTEGER(dtype);

            if (inP < 0 || inP > 1)
            {
                THROW_INVALID_ARGUMENT_ERROR("input probability of sucess must be of the range [0, 1].");
            }

            std::geometric_distribution<dtype> dist(inP);
            return dist(generator);
        }

        //============================================================================
        // Method Description:
        /// Create an array of the given shape and populate it with
        /// random samples from a "geometric" distrubution.
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.geometric.html#numpy.random.geometric
        ///
        /// @param generator: instance of a random number generator
        /// @param inShape
        /// @param inP (probablity of success [0, 1])
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype> geometric(GeneratorType& generator, const Shape& inShape, double inP = 0.5)
        {
            STATIC_ASSERT_INTEGER(dtype);

            if (inP < 0 || inP > 1)
            {
                THROW_INVALID_ARGUMENT_ERROR("input probability of sucess must be of the range [0, 1].");
            }

            NdArray<dtype> returnArray(inShape);

            std::geometric_distribution<dtype> dist(inP);

            std::for_each(returnArray.begin(),
                          returnArray.end(),
                          [&generator, &dist](dtype& value) -> void { value = dist(generator); });

            return returnArray;
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Single random value sampled from the "geometric" distrubution.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.geometric.html#numpy.random.geometric
    ///
    /// @param inP (probablity of success [0, 1])
    /// @return NdArray
    ///
    template<typename dtype>
    dtype geometric(double inP = 0.5)
    {
        return detail::geometric<dtype>(generator_, inP);
    }

    //============================================================================
    // Method Description:
    /// Create an array of the given shape and populate it with
    /// random samples from a "geometric" distrubution.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.geometric.html#numpy.random.geometric
    ///
    /// @param inShape
    /// @param inP (probablity of success [0, 1])
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> geometric(const Shape& inShape, double inP = 0.5)
    {
        return detail::geometric<dtype>(generator_, inShape, inP);
    }
} // namespace nc::random
