
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <functional>

#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Apply the input function element wise to the input
    /// array in place.
    ///
    /// @param inArray
    /// @param inFunc
    ///
    template<typename dtype>
    void applyFunction(NdArray<dtype>& inArray, const std::function<dtype(dtype)>& inFunc)
    {
        stl_algorithms::transform(inArray.begin(), inArray.end(), inArray.begin(), inFunc);
    }
} // namespace nc
