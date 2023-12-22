
/// Description
/// Calculates a multidimensional complemenatry mean filter.
///
#pragma once

#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Filter/Boundaries/Boundary.hpp"
#include "NumCpp/Filter/Filters/Filters2d/meanFilter.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::filter
{
    //============================================================================
    // Method Description:
    /// Calculates a multidimensional complemenatry mean filter.
    ///
    /// @param inImageArray
    /// @param inSize: square size of the kernel to apply
    /// @param inBoundaryType: boundary mode (default Reflect) options (reflect, constant, nearest, mirror, wrap)
    /// @param inConstantValue: contant value if boundary = 'constant' (default 0)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<double> complementaryMeanFilter(const NdArray<dtype>& inImageArray,
                                            uint32                inSize,
                                            Boundary              inBoundaryType  = Boundary::REFLECT,
                                            dtype                 inConstantValue = 0)
    {
        auto inImageArrayCopy = inImageArray.template astype<double>();
        inImageArrayCopy -= meanFilter(inImageArray, inSize, inBoundaryType, inConstantValue);

        return inImageArrayCopy;
    }
} // namespace nc::filter
