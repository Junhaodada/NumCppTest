
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <algorithm>
#include <cmath>
#include <complex>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Utils/sqr.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Compute the root mean square (RMS) along the specified axis.
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<double> rms(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        double     squareSum = 0.;
        const auto function  = [&squareSum](dtype value) -> void
        { squareSum += utils::sqr(static_cast<double>(value)); };

        switch (inAxis)
        {
            case Axis::NONE:
            {
                std::for_each(inArray.cbegin(), inArray.cend(), function);
                NdArray<double> returnArray = { std::sqrt(squareSum / static_cast<double>(inArray.size())) };
                return returnArray;
            }
            case Axis::COL:
            {
                NdArray<double> returnArray(1, inArray.numRows());
                for (uint32 row = 0; row < inArray.numRows(); ++row)
                {
                    squareSum = 0.;
                    std::for_each(inArray.cbegin(row), inArray.cend(row), function);
                    returnArray(0, row) = std::sqrt(squareSum / static_cast<double>(inArray.numCols()));
                }

                return returnArray;
            }
            case Axis::ROW:
            {
                return rms(inArray.transpose(), Axis::COL);
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
    /// Compute the root mean square (RMS) along the specified axis.
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<double>> rms(const NdArray<std::complex<dtype>>& inArray, Axis inAxis = Axis::NONE)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        std::complex<double> squareSum = 0.;
        const auto           function  = [&squareSum](std::complex<dtype> value) -> void
        { squareSum += utils::sqr(complex_cast<double>(value)); };

        switch (inAxis)
        {
            case Axis::NONE:
            {
                std::for_each(inArray.cbegin(), inArray.cend(), function);
                NdArray<std::complex<double>> returnArray = { std::sqrt(squareSum /
                                                                        static_cast<double>(inArray.size())) };
                return returnArray;
            }
            case Axis::COL:
            {
                NdArray<std::complex<double>> returnArray(1, inArray.numRows());
                for (uint32 row = 0; row < inArray.numRows(); ++row)
                {
                    squareSum = std::complex<double>(0., 0.);
                    std::for_each(inArray.cbegin(row), inArray.cend(row), function);
                    returnArray(0, row) = std::sqrt(squareSum / static_cast<double>(inArray.numCols()));
                }

                return returnArray;
            }
            case Axis::ROW:
            {
                return rms(inArray.transpose(), Axis::COL);
            }
            default:
            {
                THROW_INVALID_ARGUMENT_ERROR("Unimplemented axis type.");
                return {}; // get rid of compiler warning
            }
        }
    }
} // namespace nc
