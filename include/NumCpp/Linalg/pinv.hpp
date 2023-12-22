
/// Description
/// matrix psuedo-inverse
///
#pragma once

#include <string>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Functions/zeros.hpp"
#include "NumCpp/Linalg/svd.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::linalg
{
    //============================================================================
    // Method Description:
    /// matrix psuedo-inverse
    ///
    /// NumPy Reference: https://numpy.org/doc/stable/reference/generated/numpy.linalg.pinv.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<double> pinv(const NdArray<dtype>& inArray)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        NdArray<double> u;
        NdArray<double> d;
        NdArray<double> v;
        svd(inArray, u, d, v);

        const auto inShape = inArray.shape();
        auto       dPlus   = nc::zeros<double>(inShape.cols, inShape.rows); // transpose

        for (uint32 i = 0; i < d.shape().rows; ++i)
        {
            dPlus(i, i) = 1. / d(i, i);
        }

        return v.transpose().dot(dPlus).dot(u.transpose());
    }
} // namespace nc::linalg