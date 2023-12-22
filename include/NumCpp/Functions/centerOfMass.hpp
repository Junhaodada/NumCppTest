
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
    /// Returns the center of mass of the array values along an axis.
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE which is a 2d center of mass)
    /// @return NdArray: if axis is NONE then a 1x2 array of the centroid row/col is returned.
    ///
    template<typename dtype>
    NdArray<double> centerOfMass(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        const Shape shape = inArray.shape();

        switch (inAxis)
        {
            case Axis::NONE:
            {
                double inten     = 0.;
                double rowCenter = 0.;
                double colCenter = 0.;

                for (uint32 row = 0; row < shape.rows; ++row)
                {
                    for (uint32 col = 0; col < shape.cols; ++col)
                    {
                        const auto pixelValue = static_cast<double>(inArray(row, col));

                        inten += pixelValue;
                        rowCenter += pixelValue * static_cast<double>(row);
                        colCenter += pixelValue * static_cast<double>(col);
                    }
                }

                rowCenter /= inten;
                colCenter /= inten;

                return { rowCenter, colCenter };
            }
            case Axis::ROW:
            {
                NdArray<double> returnArray(1, shape.cols);
                returnArray.zeros();

                const NdArray<double> inten = inArray.template astype<double>().sum(inAxis);

                for (uint32 colIdx = 0; colIdx < shape.cols; ++colIdx)
                {
                    for (uint32 rowIdx = 0; rowIdx < shape.rows; ++rowIdx)
                    {
                        returnArray(0, colIdx) +=
                            static_cast<double>(inArray(rowIdx, colIdx)) * static_cast<double>(rowIdx);
                    }

                    returnArray(0, colIdx) /= inten[colIdx];
                }

                return returnArray;
            }
            case Axis::COL:
            {
                NdArray<double> returnArray(1, shape.rows);
                returnArray.zeros();

                const NdArray<double> inten = inArray.template astype<double>().sum(inAxis);

                for (uint32 rowIdx = 0; rowIdx < shape.rows; ++rowIdx)
                {
                    for (uint32 colIdx = 0; colIdx < shape.cols; ++colIdx)
                    {
                        returnArray(0, rowIdx) +=
                            static_cast<double>(inArray(rowIdx, colIdx)) * static_cast<double>(colIdx);
                    }

                    returnArray(0, rowIdx) /= inten[rowIdx];
                }

                return returnArray;
            }
            default:
            {
                THROW_INVALID_ARGUMENT_ERROR("Unimplemented axis type.");
                return {}; // get rid of compiler warning
            }
        }
    }
} // namespace nc
