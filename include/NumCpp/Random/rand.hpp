
/// Description
/// Create an array of the given shape and populate it with
/// random samples from a uniform distribution over [0, 1).
///
#pragma once

#include <algorithm>
#include <random>

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
        /// Single random value sampled from the uniform distribution over [0, 1).
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.rand.html#numpy.random.rand
        ///
        /// @param generator: instance of a random number generator
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        dtype rand(GeneratorType& generator)
        {
            STATIC_ASSERT_FLOAT(dtype);

            std::uniform_real_distribution<dtype> dist(static_cast<dtype>(0.),
                                                       static_cast<dtype>(1.) - DtypeInfo<dtype>::epsilon());
            return dist(generator);
        }

        //============================================================================
        // Method Description:
        /// Create an array of the given shape and populate it with
        /// random samples from a uniform distribution over [0, 1).
        ///
        /// NumPy Reference:
        /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.rand.html#numpy.random.rand
        ///
        /// @param generator: instance of a random number generator
        /// @param inShape
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype> rand(GeneratorType& generator, const Shape& inShape)
        {
            STATIC_ASSERT_FLOAT(dtype);

            NdArray<dtype> returnArray(inShape);

            std::uniform_real_distribution<dtype> dist(static_cast<dtype>(0.),
                                                       static_cast<dtype>(1.) - DtypeInfo<dtype>::epsilon());

            std::for_each(returnArray.begin(),
                          returnArray.end(),
                          [&generator, &dist](dtype& value) -> void { value = dist(generator); });

            return returnArray;
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Single random value sampled from the uniform distribution over [0, 1).
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.rand.html#numpy.random.rand
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    dtype rand()
    {
        return detail::rand<dtype>(generator_);
    }

    //============================================================================
    // Method Description:
    /// Create an array of the given shape and populate it with
    /// random samples from a uniform distribution over [0, 1).
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.rand.html#numpy.random.rand
    ///
    /// @param inShape
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> rand(const Shape& inShape)
    {
        return detail::rand<dtype>(generator_, inShape);
    }
} // namespace nc::random
