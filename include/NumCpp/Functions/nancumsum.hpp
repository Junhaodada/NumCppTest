
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Functions/cumsum.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the cumulative sum of the elements along a given axis ignoring NaNs.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.nancumsum.html
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> nancumsum(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        STATIC_ASSERT_FLOAT(dtype);

        NdArray<dtype> arrayCopy(inArray);
        stl_algorithms::for_each(arrayCopy.begin(),
                                 arrayCopy.end(),
                                 [](dtype& value) noexcept -> void
                                 {
                                     if (std::isnan(value))
                                     {
                                         value = dtype{ 0 };
                                     };
                                 });

        return cumsum(arrayCopy, inAxis);
    }
} // namespace nc
