
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Functions/applyFunction.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Polynomial/Poly1d.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Apply polynomial elemnt wise to the input values.
    ///
    /// @param inArray
    /// @param inPoly
    ///
    template<typename dtype>
    void applyPoly1d(NdArray<dtype>& inArray, const polynomial::Poly1d<dtype>& inPoly)
    {
        applyFunction<dtype>(inArray, inPoly);
    }
} // namespace nc
