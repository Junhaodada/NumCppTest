
/// Description
/// Window expand around exceedance pixels
///

#pragma once

#include <cmath>

#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::imageProcessing
{
    //============================================================================
    // Method Description:
    /// Window expand around exceedance pixels
    ///
    /// @param inExceedances
    /// @param inBorderWidth
    /// @return NdArray<bool>
    ///
    inline NdArray<bool> windowExceedances(const NdArray<bool>& inExceedances, uint8 inBorderWidth) noexcept
    {
        // not the most efficient way to do things, but the easist...
        NdArray<bool> xcds(inExceedances);
        const Shape   inShape = xcds.shape();
        for (uint8 border = 0; border < inBorderWidth; ++border)
        {
            for (int32 row = 0; row < static_cast<int32>(inShape.rows); ++row)
            {
                for (int32 col = 0; col < static_cast<int32>(inShape.cols); ++col)
                {
                    if (inExceedances(row, col))
                    {
                        xcds(std::max(row - 1, 0), std::max(col - 1, 0))                       = true;
                        xcds(std::max(row - 1, 0), col)                                        = true;
                        xcds(std::max(row - 1, 0), std::min<int32>(col + 1, inShape.cols - 1)) = true;

                        xcds(row, std::max<int32>(col - 1, 0))                = true;
                        xcds(row, std::min<int32>(col + 1, inShape.cols - 1)) = true;

                        xcds(std::min<int32>(row + 1, inShape.rows - 1), std::max(col - 1, 0)) = true;
                        xcds(std::min<int32>(row + 1, inShape.rows - 1), col)                  = true;
                        xcds(std::min<int32>(row + 1, inShape.rows - 1), std::min<int32>(col + 1, inShape.cols - 1)) =
                            true;
                    }
                }
            }
        }

        return xcds;
    }
} // namespace nc::imageProcessing
