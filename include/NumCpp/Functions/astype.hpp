
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <complex>

#include "NumCpp/Core/Internal/TypeTraits.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Returns a copy of the array, cast to a specified type.
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtypeOut = double, typename dtype>
    NdArray<dtypeOut> astype(const NdArray<dtype> inArray)
    {
        return inArray.template astype<dtypeOut>();
    }
} // namespace nc
