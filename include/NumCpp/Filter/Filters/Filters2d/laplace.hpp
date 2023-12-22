
/// Description
/// Calculate the 2D laplace filter.
///
#pragma once

#include "NumCpp/Filter/Filters/Filters2d/convolve.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::filter
{
    //============================================================================
    // Method Description:
    /// Calculate the 2D laplace filter.
    ///
    /// SciPy Reference:
    /// https://docs.scipy.org/doc/scipy/reference/generated/scipy.ndimage.laplace.html#scipy.ndimage.laplace
    ///
    /// @param inImageArray
    /// @param inBoundaryType: boundary mode (default Reflect) options (reflect, constant, nearest, mirror, wrap)
    /// @param inConstantValue: contant value if boundary = 'constant' (default 0)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> laplace(const NdArray<dtype>& inImageArray,
                           Boundary              inBoundaryType  = Boundary::REFLECT,
                           dtype                 inConstantValue = 0)
    {
        NdArray<dtype> kernel = { { 0, 1, 0 }, { 1, -4, 1 }, { 0, 1, 0 } };
        return convolve(inImageArray, 3, kernel, inBoundaryType, inConstantValue);
    }
} // namespace nc::filter
