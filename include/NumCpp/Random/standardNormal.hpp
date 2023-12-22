
/// Description
/// "standard normal" distrubution
///
#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Random/normal.hpp"

namespace nc::random
{
    namespace detail
    {
        //============================================================================
        // Method Description:
        /// Single random value sampled from the "standard normal" distrubution with
        /// mean = 0 and std = 1
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.standard_normal.html#numpy.random.standard_normal
        ///
        /// @param generator: instance of a random number generator
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        dtype standardNormal(GeneratorType& generator)
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            return detail::normal<dtype>(generator, 0, 1);
        }

        //============================================================================
        // Method Description:
        /// Create an array of the given shape and populate it with
        /// random samples from a "standard normal" distrubution with
        /// mean = 0 and std = 1
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.standard_normal.html#numpy.random.standard_normal
        ///
        /// @param generator: instance of a random number generator
        /// @param inShape
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype> standardNormal(GeneratorType& generator, const Shape& inShape)
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            return detail::normal<dtype>(generator, inShape, 0, 1);
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Single random value sampled from the "standard normal" distrubution with
    /// mean = 0 and std = 1
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.standard_normal.html#numpy.random.standard_normal
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    dtype standardNormal()
    {
        return detail::standardNormal<dtype>(generator_);
    }

    //============================================================================
    // Method Description:
    /// Create an array of the given shape and populate it with
    /// random samples from a "standard normal" distrubution with
    /// mean = 0 and std = 1
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.standard_normal.html#numpy.random.standard_normal
    ///
    /// @param inShape
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> standardNormal(const Shape& inShape)
    {
        return detail::standardNormal<dtype>(generator_, inShape);
    }
} // namespace nc::random
