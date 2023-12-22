
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <string>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Calculate the n-th discrete difference along given axis.
    /// Unsigned dtypes will give you weird results...obviously.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.diff.html
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> diff(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        const Shape inShape = inArray.shape();

        switch (inAxis)
        {
            case Axis::NONE:
            {
                if (inArray.size() < 2)
                {
                    return NdArray<dtype>(0);
                }

                NdArray<dtype> returnArray(1, inArray.size() - 1);
                stl_algorithms::transform(inArray.cbegin(),
                                          inArray.cend() - 1,
                                          inArray.cbegin() + 1,
                                          returnArray.begin(),
                                          [](dtype inValue1, dtype inValue2) noexcept -> dtype
                                          { return inValue2 - inValue1; });

                return returnArray;
            }
            case Axis::COL:
            {
                if (inShape.cols < 2)
                {
                    return NdArray<dtype>(0);
                }

                NdArray<dtype> returnArray(inShape.rows, inShape.cols - 1);
                for (uint32 row = 0; row < inShape.rows; ++row)
                {
                    stl_algorithms::transform(inArray.cbegin(row),
                                              inArray.cend(row) - 1,
                                              inArray.cbegin(row) + 1,
                                              returnArray.begin(row),
                                              [](dtype inValue1, dtype inValue2) noexcept -> dtype
                                              { return inValue2 - inValue1; });
                }

                return returnArray;
            }
            case Axis::ROW:
            {
                return diff(inArray.transpose(), Axis::COL).transpose();
            }
            default:
            {
                THROW_INVALID_ARGUMENT_ERROR("Unimplemented axis type.");
                return {}; // get rid of compiler warning
            }
        }
    }
} // namespace nc
