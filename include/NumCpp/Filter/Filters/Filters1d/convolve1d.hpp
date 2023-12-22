
/// Description
/// Calculates a one-dimensional kernel convolution.
///
#pragma once

#include "NumCpp/Core/Slice.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Filter/Boundaries/Boundaries1d/addBoundary1d.hpp"
#include "NumCpp/Filter/Boundaries/Boundary.hpp"
#include "NumCpp/Functions/dot.hpp"
#include "NumCpp/Functions/fliplr.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::filter
{
    //============================================================================
    // Method Description:
    /// Calculates a one-dimensional kernel convolution.
    ///
    /// SciPy Reference:
    /// https://docs.scipy.org/doc/scipy/reference/generated/scipy.ndimage.convolve1d.html#scipy.ndimage.convolve1d
    ///
    /// @param inImageArray
    /// @param inWeights
    /// @param inBoundaryType: boundary mode (default Reflect) options (reflect, constant, nearest, mirror, wrap)
    /// @param inConstantValue: contant value if boundary = 'constant' (default 0)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> convolve1d(const NdArray<dtype>& inImageArray,
                              const NdArray<dtype>& inWeights,
                              Boundary              inBoundaryType  = Boundary::REFLECT,
                              dtype                 inConstantValue = 0)
    {
        const uint32   boundarySize = inWeights.size() / 2; // integer division
        NdArray<dtype> arrayWithBoundary =
            boundary::addBoundary1d(inImageArray, inBoundaryType, inWeights.size(), inConstantValue);
        NdArray<dtype> output(1, inImageArray.size());

        NdArray<dtype> weightsFlat = fliplr(inWeights.flatten());

        const uint32 endPointRow = boundarySize + inImageArray.size();

        for (uint32 i = boundarySize; i < endPointRow; ++i)
        {
            NdArray<dtype> window = arrayWithBoundary[Slice(i - boundarySize, i + boundarySize + 1)].flatten();

            output[i - boundarySize] = dot(window, weightsFlat).item();
        }

        return output;
    }
} // namespace nc::filter
