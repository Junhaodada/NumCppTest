
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <algorithm>
#include <cmath>
#include <complex>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Functions/norm.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Utils/sqr.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Matrix or vector norm.
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<double> normalize(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        switch (inAxis)
        {
            case Axis::NONE:
            {
                return inArray / norm(inArray, Axis::NONE);
            }
            case Axis::COL:
            {
                NdArray<double> returnArray(inArray.shape());
                const auto      cSlice = returnArray.cSlice();
                for (uint32 row = 0; row < inArray.numRows(); ++row)
                {
                    returnArray.put(row, cSlice, normalize(inArray.row(row), Axis::NONE));
                }

                return returnArray;
            }
            case Axis::ROW:
            {
                return normalize(inArray.transpose(), Axis::COL).transpose();
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
    /// Matrix or vector norm.
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<double>> normalize(const NdArray<std::complex<dtype>>& inArray, Axis inAxis = Axis::NONE)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        switch (inAxis)
        {
            case Axis::NONE:
            {
                return inArray / norm(inArray, Axis::NONE);
            }
            case Axis::COL:
            {
                NdArray<std::complex<double>> returnArray(inArray.shape());
                const auto                    cSlice = returnArray.cSlice();
                for (uint32 row = 0; row < inArray.numRows(); ++row)
                {
                    returnArray.put(row, cSlice, normalize(inArray.row(row), Axis::NONE));
                }

                return returnArray;
            }
            case Axis::ROW:
            {
                return normalize(inArray.transpose(), Axis::COL).transpose();
            }
            default:
            {
                THROW_INVALID_ARGUMENT_ERROR("Unimplemented axis type.");
                return {}; // get rid of compiler warning
            }
        }
    }
} // namespace nc
