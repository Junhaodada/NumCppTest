
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Counts the number of non-zero values in the array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.count_nonzero.html
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<uint32> count_nonzero(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        switch (inAxis)
        {
            case Axis::NONE:
            {
                NdArray<uint32> count = { inArray.size() -
                                          static_cast<uint32>(
                                              stl_algorithms::count(inArray.cbegin(), inArray.cend(), dtype{ 0 })) };
                return count;
            }
            case Axis::COL:
            {
                Shape inShape = inArray.shape();

                NdArray<uint32> returnArray(1, inShape.rows);
                for (uint32 row = 0; row < inShape.rows; ++row)
                {
                    returnArray(0, row) =
                        inShape.cols -
                        static_cast<uint32>(stl_algorithms::count(inArray.cbegin(row), inArray.cend(row), dtype{ 0 }));
                }

                return returnArray;
            }
            case Axis::ROW:
            {
                return count_nonzero(inArray.transpose(), Axis::COL);
            }
            default:
            {
                THROW_INVALID_ARGUMENT_ERROR("Unimplemented axis type.");
                return {}; // get rid of compiler warning
            }
        }
    }
} // namespace nc
