
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Utils/interp.hpp"

namespace nc
{
    //============================================================================
    /// Returns the linear interpolation between two points
    ///
    /// @param inValue1
    /// @param inValue2
    /// @param inPercent
    ///
    /// @return linear interpolated point
    ///
    template<typename dtype>
    constexpr double interp(dtype inValue1, dtype inValue2, double inPercent) noexcept
    {
        return utils::interp(inValue1, inValue2, inPercent);
    }

    //============================================================================
    // Method Description:
    /// One-dimensional linear interpolation.
    ///
    /// Returns the one - dimensional piecewise linear interpolant
    /// to a function with given values at discrete data - points.
    /// If input arrays are not one dimensional they will be
    /// internally flattened.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.interp.html
    ///
    /// @param inX: The x-coordinates at which to evaluate the interpolated values.
    /// @param inXp: The x-coordinates of the data points, must be increasing. Otherwise, xp is internally sorted.
    /// @param inFp: The y-coordinates of the data points, same length as inXp.
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> interp(const NdArray<dtype>& inX, const NdArray<dtype>& inXp, const NdArray<dtype>& inFp)
    {
        // do some error checking first
        if (inXp.size() != inFp.size())
        {
            THROW_INVALID_ARGUMENT_ERROR("inXp and inFp need to be the same size().");
        }

        if (inX.min().item() < inXp.min().item() || inX.max().item() > inXp.max().item())
        {
            THROW_INVALID_ARGUMENT_ERROR("endpoints of inX should be contained within inXp.");
        }

        // sort the input inXp and inFp data
        NdArray<uint32> sortedXpIdxs = argsort(inXp);
        NdArray<dtype>  sortedXp(1, inFp.size());
        NdArray<dtype>  sortedFp(1, inFp.size());
        uint32          counter = 0;
        for (auto sortedXpIdx : sortedXpIdxs)
        {
            sortedXp[counter]   = inXp[sortedXpIdx];
            sortedFp[counter++] = inFp[sortedXpIdx];
        }

        // get the sorted input inX array indices
        NdArray<uint32> sortedXIdxs = argsort(inX);

        NdArray<dtype> returnArray(1, inX.size());

        uint32 currXpIdx = 0;
        uint32 currXidx  = 0;
        while (currXidx < inX.size())
        {
            const auto sortedXIdx = sortedXIdxs[currXidx];
            const auto x          = inX[sortedXIdx];
            const auto xPLow      = sortedXp[currXpIdx];
            const auto xPHigh     = sortedXp[currXpIdx + 1];
            const auto fPLow      = sortedFp[currXpIdx];
            const auto fPHigh     = sortedFp[currXpIdx + 1];

            if (xPLow <= x && x <= xPHigh)
            {
                const double percent    = static_cast<double>(x - xPLow) / static_cast<double>(xPHigh - xPLow);
                returnArray[sortedXIdx] = utils::interp(fPLow, fPHigh, percent);
                ++currXidx;
            }
            else
            {
                ++currXpIdx;
            }
        }

        return returnArray;
    }
} // namespace nc
