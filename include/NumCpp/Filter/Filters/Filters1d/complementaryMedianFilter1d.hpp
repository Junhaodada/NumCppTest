
/// Description
/// Calculate a one-dimensional complemenatry median filter.
///
#pragma once

#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Filter/Boundaries/Boundary.hpp"
#include "NumCpp/Filter/Filters/Filters1d/medianFilter1d.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::filter
{
    //============================================================================
    // Method Description:
    /// Calculate a one-dimensional complemenatry median filter.
    ///
    /// @param inImageArray
    /// @param inSize: square size of the kernel to apply
    /// @param inBoundaryType: boundary mode (default Reflect) options (reflect, constant, nearest, mirror, wrap)
    /// @param inConstantValue: contant value if boundary = 'constant' (default 0)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> complementaryMedianFilter1d(const NdArray<dtype>& inImageArray,
                                               uint32                inSize,
                                               Boundary              inBoundaryType  = Boundary::REFLECT,
                                               dtype                 inConstantValue = 0)
    {
        NdArray<dtype> inImageArrayCopy(inImageArray);
        inImageArrayCopy -= medianFilter1d(inImageArray, inSize, inBoundaryType, inConstantValue);

        return inImageArrayCopy;
    }
} // namespace nc::filter
