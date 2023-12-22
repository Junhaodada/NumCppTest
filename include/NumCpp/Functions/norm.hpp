
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
    /// Matrix or vector norm.
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<double> norm(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        double     sumOfSquares = 0.;
        const auto function     = [&sumOfSquares](dtype value) -> void
        { sumOfSquares += utils::sqr(static_cast<double>(value)); };

        switch (inAxis)
        {
            case Axis::NONE:
            {
                std::for_each(inArray.cbegin(), inArray.cend(), function);

                NdArray<double> returnArray = { std::sqrt(sumOfSquares) };
                return returnArray;
            }
            case Axis::COL:
            {
                NdArray<double> returnArray(1, inArray.numRows());
                for (uint32 row = 0; row < inArray.numRows(); ++row)
                {
                    sumOfSquares = 0.;
                    std::for_each(inArray.cbegin(row), inArray.cend(row), function);
                    returnArray(0, row) = std::sqrt(sumOfSquares);
                }

                return returnArray;
            }
            case Axis::ROW:
            {
                return norm(inArray.transpose(), Axis::COL);
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
    NdArray<std::complex<double>> norm(const NdArray<std::complex<dtype>>& inArray, Axis inAxis = Axis::NONE)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        std::complex<double> sumOfSquares(0., 0.);
        const auto           function = [&sumOfSquares](const std::complex<dtype>& value) -> void
        { sumOfSquares += utils::sqr(complex_cast<double>(value)); };

        switch (inAxis)
        {
            case Axis::NONE:
            {
                std::for_each(inArray.cbegin(), inArray.cend(), function);

                NdArray<std::complex<double>> returnArray = { std::sqrt(sumOfSquares) };
                return returnArray;
            }
            case Axis::COL:
            {
                NdArray<std::complex<double>> returnArray(1, inArray.numRows());
                for (uint32 row = 0; row < inArray.numRows(); ++row)
                {
                    sumOfSquares = std::complex<double>(0., 0.);
                    std::for_each(inArray.cbegin(row), inArray.cend(row), function);
                    returnArray(0, row) = std::sqrt(sumOfSquares);
                }

                return returnArray;
            }
            case Axis::ROW:
            {
                return norm(inArray.transpose(), Axis::COL);
            }
            default:
            {
                THROW_INVALID_ARGUMENT_ERROR("Unimplemented axis type.");
                return {}; // get rid of compiler warning
            }
        }
    }
} // namespace nc
