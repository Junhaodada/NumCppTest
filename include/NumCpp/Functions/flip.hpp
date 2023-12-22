
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Reverse the order of elements in an array along the given axis.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.flip.html
    ///
    /// @param inArray
    /// @param inAxis
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> flip(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        switch (inAxis)
        {
            case Axis::NONE:
            {
                NdArray<dtype> returnArray(inArray);
                stl_algorithms::reverse(returnArray.begin(), returnArray.end());
                return returnArray;
            }
            case Axis::COL:
            {
                NdArray<dtype> returnArray(inArray);
                for (uint32 row = 0; row < inArray.shape().rows; ++row)
                {
                    stl_algorithms::reverse(returnArray.begin(row), returnArray.end(row));
                }
                return returnArray;
            }
            case Axis::ROW:
            {
                return flip(inArray.transpose(), Axis::COL).transpose();
            }
            default:
            {
                THROW_INVALID_ARGUMENT_ERROR("Unimplemented axis type.");
                return {}; // get rid of compiler warning
            }
        }
    }
} // namespace nc
