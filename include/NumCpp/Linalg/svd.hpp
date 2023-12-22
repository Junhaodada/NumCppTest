
/// Description
/// matrix svd
///
#pragma once

#include <utility>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Functions/diagflat.hpp"
#include "NumCpp/Linalg/svd/SVDClass.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::linalg
{
    //============================================================================
    // Method Description:
    /// matrix svd
    ///
    /// NumPy Reference: https://docs.scipy.org/doc/numpy/reference/generated/numpy.linalg.svd.html#numpy.linalg.svd
    ///
    /// @param inArray: NdArray to be SVDed
    /// @param outU: NdArray output U
    /// @param outS: NdArray output S
    /// @param outVt: NdArray output V transpose
    ///
    template<typename dtype>
    void svd(const NdArray<dtype>& inArray, NdArray<double>& outU, NdArray<double>& outS, NdArray<double>& outVt)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        SVD svdSolver(inArray.template astype<double>());
        outU = svdSolver.u();

        NdArray<double> vt = svdSolver.v().transpose();
        outVt              = std::move(vt);

        NdArray<double> s = diagflat(svdSolver.s(), 0);
        outS              = std::move(s);
    }
} // namespace nc::linalg
