
/// Description
/// Calculates a multidimensional uniform filter.
///
#pragma once

#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Slice.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Filter/Boundaries/Boundaries2d/addBoundary2d.hpp"
#include "NumCpp/Functions/mean.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::filter
{
    //============================================================================
    // Method Description:
    /// Calculates a multidimensional uniform filter.
    ///
    /// SciPy Reference:
    /// https://docs.scipy.org/doc/scipy/reference/generated/scipy.ndimage.uniform_filter.html#scipy.ndimage.uniform_filter
    ///
    /// @param inImageArray
    /// @param inSize: square size of the kernel to apply
    /// @param inBoundaryType: boundary mode (default Reflect) options (reflect, constant, nearest, mirror, wrap)
    /// @param inConstantValue: contant value if boundary = 'constant' (default 0)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> uniformFilter(const NdArray<dtype>& inImageArray,
                                 uint32                inSize,
                                 Boundary              inBoundaryType  = Boundary::REFLECT,
                                 dtype                 inConstantValue = 0)
    {
        NdArray<dtype> arrayWithBoundary =
            boundary::addBoundary2d(inImageArray, inBoundaryType, inSize, inConstantValue);
        NdArray<dtype> output(inImageArray.shape());

        const Shape  inShape      = inImageArray.shape();
        const uint32 boundarySize = inSize / 2; // integer division
        const uint32 endPointRow  = boundarySize + inShape.rows;
        const uint32 endPointCol  = boundarySize + inShape.cols;

        for (uint32 row = boundarySize; row < endPointRow; ++row)
        {
            for (uint32 col = boundarySize; col < endPointCol; ++col)
            {
                NdArray<dtype> window = arrayWithBoundary(Slice(row - boundarySize, row + boundarySize + 1),
                                                          Slice(col - boundarySize, col + boundarySize + 1));

                output(row - boundarySize, col - boundarySize) = mean(window).item();
            }
        }

        return output;
    }
} // namespace nc::filter
