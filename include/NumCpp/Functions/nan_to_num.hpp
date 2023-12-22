
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <utility>

#include "NumCpp/Core/DtypeInfo.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Functions/isinf.hpp"
#include "NumCpp/Functions/isnan.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Replace NaN with zero and infinity with large finite numbers (default behaviour)
    /// or with the numbers defined by the user using the nan, posinf and/or neginf keywords.
    ///
    /// NumPy Reference: https://numpy.org/doc/stable/reference/generated/numpy.nan_to_num.html
    ///
    /// @param inArray
    /// @param nan: value to be used to fill NaN values, default 0
    /// @param posInf: value to be used to fill positive infinity values, default a very large number
    /// @param negInf: value to be used to fill negative infinity values, default a very large negative number
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> nan_to_num(NdArray<dtype> inArray,
                              dtype          nan    = static_cast<dtype>(0.),
                              dtype          posInf = DtypeInfo<dtype>::max(),
                              dtype          negInf = DtypeInfo<dtype>::min())
    {
        STATIC_ASSERT_FLOAT(dtype);

        stl_algorithms::for_each(inArray.begin(),
                                 inArray.end(),
                                 [nan, posInf, negInf](dtype& value)
                                 {
                                     if (isnan(value))
                                     {
                                         value = nan;
                                     }
                                     else if (isinf(value))
                                     {
                                         if (value > static_cast<dtype>(0.))
                                         {
                                             value = posInf;
                                         }
                                         else
                                         {
                                             value = negInf;
                                         }
                                     }
                                 });

        return inArray;
    }
} // namespace nc
