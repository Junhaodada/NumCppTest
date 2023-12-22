
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>

#include "NumCpp/Core/DtypeInfo.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Functions/argmax.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Returns the indices of the maximum values along an axis ignoring NaNs.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.nanargmax.html
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<uint32> nanargmax(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        STATIC_ASSERT_FLOAT(dtype);

        NdArray<dtype> arrayCopy(inArray);
        stl_algorithms::for_each(arrayCopy.begin(),
                                 arrayCopy.end(),
                                 [](dtype& value) noexcept -> void
                                 {
                                     if (std::isnan(value))
                                     {
                                         value = DtypeInfo<dtype>::min();
                                     };
                                 });

        return argmax(arrayCopy, inAxis);
    }
} // namespace nc
