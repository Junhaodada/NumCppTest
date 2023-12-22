
/// Description
/// Chooses a random sample from an input array.
///
#pragma once

#include <algorithm>

#include "NumCpp/Core/Enums.hpp"
#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Random/permutation.hpp"
#include "NumCpp/Random/randInt.hpp"

namespace nc::random
{
    namespace detail
    {
        //============================================================================
        // Method Description:
        /// Chooses a random sample from an input array.
        ///
        /// @param generator: instance of a random number generator
        /// @param inArray
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        dtype choice(GeneratorType& generator, const NdArray<dtype>& inArray)
        {
            uint32 randIdx = detail::randInt<uint32>(generator, inArray.size());
            return inArray[randIdx];
        }

        //============================================================================
        // Method Description:
        /// Chooses inNum random samples from an input array.
        ///
        /// @param generator: instance of a random number generator
        /// @param inArray
        /// @param inNum
        /// @param replace: Whether the sample is with or without replacement
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype> choice(GeneratorType&        generator,
                              const NdArray<dtype>& inArray,
                              uint32                inNum,
                              Replace               replace = Replace::YES)
        {
            if (replace == Replace::NO && inNum > inArray.size())
            {
                THROW_INVALID_ARGUMENT_ERROR("when Replace::NO 'inNum' must be <= inArray.size()");
            }

            if (replace == Replace::YES)
            {
                NdArray<dtype> outArray(1, inNum);
                std::for_each(outArray.begin(),
                              outArray.end(),
                              [&generator, &inArray](dtype& value) -> void { value = choice(generator, inArray); });

                return outArray;
            }

            return detail::permutation(generator, inArray)[Slice(inNum)];
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Chooses a random sample from an input array.
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    dtype choice(const NdArray<dtype>& inArray)
    {
        return detail::choice(generator_, inArray);
    }

    //============================================================================
    // Method Description:
    /// Chooses inNum random samples from an input array.
    ///
    /// @param inArray
    /// @param inNum
    /// @param replace: Whether the sample is with or without replacement
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> choice(const NdArray<dtype>& inArray, uint32 inNum, Replace replace = Replace::YES)
    {
        return detail::choice(generator_, inArray, inNum, replace);
    }
} // namespace nc::random
