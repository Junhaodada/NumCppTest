
/// Description
/// Such a distribution produces random numbers uniformly
/// distributed on the unit sphere of arbitrary dimension dim.
///
#pragma once

#ifndef NUMCPP_NO_USE_BOOST

#include <algorithm>
#include <string>

#include "boost/random/uniform_on_sphere.hpp"

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Random/generator.hpp"

namespace nc::random
{
    namespace detail
    {
        //============================================================================
        // Method Description:
        /// Such a distribution produces random numbers uniformly
        /// distributed on the unit sphere of arbitrary dimension dim.
        /// NOTE: Use of this function requires using the Boost includes.
        ///
        /// @param generator: instance of a random number generator
        /// @param inNumPoints
        /// @param inDims: dimension of the sphere (default 2)
        /// @return NdArray
        ///
        template<typename dtype, typename GeneratorType = std::mt19937>
        NdArray<dtype> uniformOnSphere(GeneratorType& generator, uint32 inNumPoints, uint32 inDims = 2)
        {
            STATIC_ASSERT_FLOAT(dtype);

            if (inNumPoints == 0)
            {
                return {};
            }

            boost::random::uniform_on_sphere<dtype> dist(static_cast<int>(inDims));

            NdArray<dtype> returnArray(inNumPoints, inDims);
            for (uint32 row = 0; row < inNumPoints; ++row)
            {
                const auto& point = dist(generator);
                std::copy(point.begin(), point.end(), returnArray.begin(row));
            }

            return returnArray;
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Such a distribution produces random numbers uniformly
    /// distributed on the unit sphere of arbitrary dimension dim.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param inNumPoints
    /// @param inDims: dimension of the sphere (default 2)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> uniformOnSphere(uint32 inNumPoints, uint32 inDims = 2)
    {
        return detail::uniformOnSphere<dtype>(generator_, inNumPoints, inDims);
    }
} // namespace nc::random

#endif // #ifndef NUMCPP_NO_USE_BOOST
