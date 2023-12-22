
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Integrate along the given axis using the composite trapezoidal rule.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.trapz.html
    ///
    /// @param inArray
    /// @param dx: (Optional defaults to 1.)
    /// @param inAxis (Optional, default NONE)
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<double> trapz(const NdArray<dtype>& inArray, double dx = 1., Axis inAxis = Axis::NONE)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        const Shape inShape = inArray.shape();
        switch (inAxis)
        {
            case Axis::NONE:
            {
                double sum = 0.;
                for (uint32 i = 0; i < inArray.size() - 1; ++i)
                {
                    sum += static_cast<double>(inArray[i + 1] - inArray[i]) / 2. + static_cast<double>(inArray[i]);
                }

                NdArray<double> returnArray = { sum * dx };
                return returnArray;
            }
            case Axis::COL:
            {
                NdArray<double> returnArray(inShape.rows, 1);
                for (uint32 row = 0; row < inShape.rows; ++row)
                {
                    double sum = 0;
                    for (uint32 col = 0; col < inShape.cols - 1; ++col)
                    {
                        sum += static_cast<double>(inArray(row, col + 1) - inArray(row, col)) / 2. +
                               static_cast<double>(inArray(row, col));
                    }

                    returnArray[row] = sum * dx;
                }

                return returnArray;
            }
            case Axis::ROW:
            {
                return trapz(inArray.transpose(), dx, Axis::COL);
            }
            default:
            {
                THROW_INVALID_ARGUMENT_ERROR("Unimplemented axis type.");
                return {}; // get rid of compiler warning
            }
        }
    }

    //============================================================================
    // Method Description:
    /// Integrate along the given axis using the composite trapezoidal rule.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.trapz.html
    ///
    /// @param inArrayY
    /// @param inArrayX
    /// @param inAxis (Optional, default NONE)
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<double> trapz(const NdArray<dtype>& inArrayY, const NdArray<dtype>& inArrayX, Axis inAxis = Axis::NONE)
    {
        const Shape inShapeY = inArrayY.shape();
        const Shape inShapeX = inArrayX.shape();

        if (inShapeY != inShapeX)
        {
            THROW_INVALID_ARGUMENT_ERROR("input x and y arrays should be the same shape.");
        }

        switch (inAxis)
        {
            case Axis::NONE:
            {
                double sum = 0.;
                for (uint32 i = 0; i < inArrayY.size() - 1; ++i)
                {
                    const auto dx = static_cast<double>(inArrayX[i + 1] - inArrayX[i]);
                    sum += dx *
                           (static_cast<double>(inArrayY[i + 1] - inArrayY[i]) / 2. + static_cast<double>(inArrayY[i]));
                }

                NdArray<double> returnArray = { sum };
                return returnArray;
            }
            case Axis::COL:
            {
                NdArray<double> returnArray(inShapeY.rows, 1);
                for (uint32 row = 0; row < inShapeY.rows; ++row)
                {
                    double sum = 0;
                    for (uint32 col = 0; col < inShapeY.cols - 1; ++col)
                    {
                        const auto dx = static_cast<double>(inArrayX(row, col + 1) - inArrayX(row, col));
                        sum += dx * (static_cast<double>(inArrayY(row, col + 1) - inArrayY(row, col)) / 2. +
                                     static_cast<double>(inArrayY(row, col)));
                    }

                    returnArray[row] = sum;
                }

                return returnArray;
            }
            case Axis::ROW:
            {
                return trapz(inArrayY.transpose(), inArrayX.transpose(), Axis::COL);
            }
            default:
            {
                THROW_INVALID_ARGUMENT_ERROR("Unimplemented axis type.");
                return {}; // get rid of compiler warning
            }
        }
    }
} // namespace nc
