
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Functions/flip.hpp"
#include "NumCpp/Functions/fliplr.hpp"
#include "NumCpp/Functions/flipud.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Rotate an array by 90 degrees counter clockwise in the plane.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.rot90.html
    ///
    /// @param inArray
    /// @param inK: the number of times to rotate 90 degrees
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> rot90(const NdArray<dtype>& inArray, uint8 inK = 1)
    {
        inK %= 4;
        switch (inK)
        {
            case 0:
            {
                return inArray;
            }
            case 1:
            {
                return flipud(inArray.transpose());
            }
            case 2:
            {
                return flip(inArray, Axis::NONE);
            }
            case 3:
            {
                return fliplr(inArray.transpose());
            }
            default:
            {
                // this isn't actually possible, just putting this here to get rid
                // of the compiler warning.
                return {};
            }
        }
    }
} // namespace nc
