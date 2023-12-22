
/// Description
/// Calculates a one-dimensional percentile filter.
///
#pragma once

#include "NumCpp/Core/Slice.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Filter/Boundaries/Boundaries1d/addBoundary1d.hpp"
#include "NumCpp/Filter/Boundaries/Boundary.hpp"
#include "NumCpp/Functions/percentile.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::filter
{
    //============================================================================
    // Method Description:
    /// Calculates a one-dimensional percentile filter.
    ///
    /// SciPy Reference:
    /// https://docs.scipy.org/doc/scipy/reference/generated/scipy.ndimage.percentile_filter.html#scipy.ndimage.percentile_filter
    ///
    /// @param inImageArray
    /// @param inSize: linear size of the kernel to apply
    /// @param inPercentile: percentile [0, 100]
    /// @param inBoundaryType: boundary mode (default Reflect) options (reflect, constant, nearest, mirror, wrap)
    /// @param inConstantValue: contant value if boundary = 'constant' (default 0)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> percentileFilter1d(const NdArray<dtype>& inImageArray,
                                      uint32                inSize,
                                      double                inPercentile,
                                      Boundary              inBoundaryType  = Boundary::REFLECT,
                                      dtype                 inConstantValue = 0)
    {
        NdArray<dtype> arrayWithBoundary =
            boundary::addBoundary1d(inImageArray, inBoundaryType, inSize, inConstantValue);
        NdArray<dtype> output(1, inImageArray.size());

        const uint32 boundarySize = inSize / 2; // integer division
        const uint32 endPoint     = boundarySize + inImageArray.size();

        for (uint32 i = boundarySize; i < endPoint; ++i)
        {
            NdArray<dtype> window = arrayWithBoundary[Slice(i - boundarySize, i + boundarySize + 1)];

            output[i - boundarySize] = percentile(window, inPercentile).item();
        }

        return output;
    }
} // namespace nc::filter
