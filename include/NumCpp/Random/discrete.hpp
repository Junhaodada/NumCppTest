
/// Description
/// "discrete" distrubution.
///
#pragma once

#include <algorithm>
#include <random>

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
        /// Single random value sampled from the from the
        /// "discrete" distrubution.  It produces integers in the
        /// range [0, n) with the probability of producing each value
        /// is specified by the parameters of the distribution.
        ///
        /// @param generator: instance of a random number generator
        /// @param inWeights
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        dtype discrete(GeneratorType& generator, const NdArray<double>& inWeights)
        {
            STATIC_ASSERT_INTEGER(dtype);

            std::discrete_distribution<dtype> dist(inWeights.cbegin(), inWeights.cend());
            return dist(generator);
        }

        //============================================================================
        // Method Description:
        /// Create an array of the given shape and populate it with
        /// random samples from a "discrete" distrubution.  It produces
        /// integers in the range [0, n) with the probability of
        /// producing each value is specified by the parameters
        /// of the distribution.
        ///
        /// @param generator: instance of a random number generator
        /// @param inShape
        /// @param inWeights
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype> discrete(GeneratorType& generator, const Shape& inShape, const NdArray<double>& inWeights)
        {
            STATIC_ASSERT_INTEGER(dtype);

            NdArray<dtype> returnArray(inShape);

            std::discrete_distribution<dtype> dist(inWeights.cbegin(), inWeights.cend());

            std::for_each(returnArray.begin(),
                          returnArray.end(),
                          [&generator, &dist](dtype& value) -> void { value = dist(generator); });

            return returnArray;
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Single random value sampled from the from the
    /// "discrete" distrubution.  It produces integers in the
    /// range [0, n) with the probability of producing each value
    /// is specified by the parameters of the distribution.
    ///
    /// @param inWeights
    /// @return NdArray
    ///
    template<typename dtype>
    dtype discrete(const NdArray<double>& inWeights)
    {
        return detail::discrete<dtype>(generator_, inWeights);
    }

    //============================================================================
    // Method Description:
    /// Create an array of the given shape and populate it with
    /// random samples from a "discrete" distrubution.  It produces
    /// integers in the range [0, n) with the probability of
    /// producing each value is specified by the parameters
    /// of the distribution.
    ///
    /// @param inShape
    /// @param inWeights
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> discrete(const Shape& inShape, const NdArray<double>& inWeights)
    {
        return detail::discrete<dtype>(generator_, inShape, inWeights);
    }
} // namespace nc::random
