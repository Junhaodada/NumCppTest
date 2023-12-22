
/// Description
/// Calculates a multidimensional kernel convolution.
///
#pragma once

#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Slice.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Filter/Boundaries/Boundaries2d/addBoundary2d.hpp"
#include "NumCpp/Filter/Boundaries/Boundary.hpp"
#include "NumCpp/Functions/dot.hpp"
#include "NumCpp/Functions/rot90.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Utils/sqr.hpp"

namespace nc::filter
{
    //============================================================================
    // Method Description:
    /// Calculates a multidimensional kernel convolution.
    ///
    /// SciPy Reference:
    /// https://docs.scipy.org/doc/scipy/reference/generated/scipy.ndimage.convolve.html#scipy.ndimage.convolve
    ///
    /// @param inImageArray
    /// @param inSize: square size of the kernel to apply
    /// @param inWeights
    /// @param inBoundaryType: boundary mode (default Reflect) options (reflect, constant, nearest, mirror, wrap)
    /// @param inConstantValue: contant value if boundary = 'constant' (default 0)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> convolve(const NdArray<dtype>& inImageArray,
                            uint32                inSize,
                            const NdArray<dtype>& inWeights,
                            Boundary              inBoundaryType  = Boundary::REFLECT,
                            dtype                 inConstantValue = 0)
    {
        if (inWeights.size() != utils::sqr(inSize))
        {
            THROW_INVALID_ARGUMENT_ERROR("input weights do no match input kernal size.");
        }

        NdArray<dtype> arrayWithBoundary =
            boundary::addBoundary2d(inImageArray, inBoundaryType, inSize, inConstantValue);
        NdArray<dtype> output(inImageArray.shape());

        NdArray<dtype> weightsFlat  = rot90(inWeights, 2).flatten();
        const Shape    inShape      = inImageArray.shape();
        const uint32   boundarySize = inSize / 2; // integer division
        const uint32   endPointRow  = boundarySize + inShape.rows;
        const uint32   endPointCol  = boundarySize + inShape.cols;

        for (uint32 row = boundarySize; row < endPointRow; ++row)
        {
            for (uint32 col = boundarySize; col < endPointCol; ++col)
            {
                NdArray<dtype> window = arrayWithBoundary(Slice(row - boundarySize, row + boundarySize + 1),
                                                          Slice(col - boundarySize, col + boundarySize + 1))
                                            .flatten();

                output(row - boundarySize, col - boundarySize) = dot(window, weightsFlat).item();
            }
        }

        return output;
    }
} // namespace nc::filter
