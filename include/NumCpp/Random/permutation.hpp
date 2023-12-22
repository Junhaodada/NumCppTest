
/// Description
/// Randomly permute a sequence, or return a permuted range
///
#pragma once

#include <algorithm>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Functions/arange.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Random/generator.hpp"

namespace nc::random
{
    namespace detail
    {
        //============================================================================
        // Method Description:
        /// Randomly permute a sequence, or return a permuted range.
        /// If x is an integer, randomly permute np.arange(x).
        /// If x is an array, make a copy and shuffle the elements randomly.
        ///
        /// @param generator: instance of a random number generator
        /// @param inValue
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype> permutation(GeneratorType& generator, dtype inValue)
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            NdArray<dtype> returnArray = arange(inValue);
            std::shuffle(returnArray.begin(), returnArray.end(), generator);
            return returnArray;
        }

        //============================================================================
        // Method Description:
        /// Randomly permute a sequence, or return a permuted range.
        /// If x is an integer, randomly permute np.arange(x).
        /// If x is an array, make a copy and shuffle the elements randomly.
        ///
        /// @param generator: instance of a random number generator
        /// @param inArray
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype> permutation(GeneratorType& generator, const NdArray<dtype>& inArray)
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            NdArray<dtype> returnArray(inArray);
            std::shuffle(returnArray.begin(), returnArray.end(), generator);
            return returnArray;
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Randomly permute a sequence, or return a permuted range.
    /// If x is an integer, randomly permute np.arange(x).
    /// If x is an array, make a copy and shuffle the elements randomly.
    ///
    /// @param inValue
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> permutation(dtype inValue)
    {
        return detail::permutation(generator_, inValue);
    }

    //============================================================================
    // Method Description:
    /// Randomly permute a sequence, or return a permuted range.
    /// If x is an integer, randomly permute np.arange(x).
    /// If x is an array, make a copy and shuffle the elements randomly.
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> permutation(const NdArray<dtype>& inArray)
    {
        return detail::permutation(generator_, inArray);
    }
} // namespace nc::random
