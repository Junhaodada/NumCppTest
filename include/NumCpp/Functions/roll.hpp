
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>

#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Roll array elements along a given axis.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.roll.html
    ///
    /// @param inArray
    /// @param inShift: (elements to shift, positive means forward, negative means backwards)
    /// @param inAxis (Optional, default NONE)
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> roll(const NdArray<dtype>& inArray, int32 inShift, Axis inAxis = Axis::NONE)
    {
        switch (inAxis)
        {
            case Axis::NONE:
            {
                uint32 shift = std::abs(inShift) % inArray.size();
                if (inShift > 0)
                {
                    shift = inArray.size() - shift;
                }

                NdArray<dtype> returnArray(inArray);
                stl_algorithms::rotate(returnArray.begin(), returnArray.begin() + shift, returnArray.end());

                return returnArray;
            }
            case Axis::COL:
            {
                const Shape inShape = inArray.shape();

                uint32 shift = std::abs(inShift) % inShape.cols;
                if (inShift > 0)
                {
                    shift = inShape.cols - shift;
                }

                NdArray<dtype> returnArray(inArray);
                for (uint32 row = 0; row < inShape.rows; ++row)
                {
                    stl_algorithms::rotate(returnArray.begin(row),
                                           returnArray.begin(row) + shift,
                                           returnArray.end(row));
                }

                return returnArray;
            }
            case Axis::ROW:
            {
                return roll(inArray.transpose(), inShift, Axis::COL).transpose();
            }
            default:
            {
                THROW_INVALID_ARGUMENT_ERROR("Unimplemented axis type.");
                return {}; // get rid of compiler warning
            }
        }
    }
} // namespace nc
