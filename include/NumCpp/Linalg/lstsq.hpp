
/// Description
/// linear least squares
///
#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Linalg/svd/SVDClass.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::linalg
{
    //============================================================================
    // Method Description:
    /// Solves the equation a x = b by computing a vector x
    /// that minimizes the Euclidean 2-norm || b - a x ||^2.
    /// The equation may be under-, well-, or over- determined
    /// (i.e., the number of linearly independent rows of a can
    /// be less than, equal to, or greater than its number of
    /// linearly independent columns). If a is square and of
    /// full rank, then x (but for round-off error) is the
    /// "exact" solution of the equation.
    ///
    /// SciPy Reference:
    /// https://docs.scipy.org/doc/scipy/reference/generated/scipy.linalg.lstsq.html#scipy.linalg.lstsq
    ///
    /// @param inA: coefficient matrix
    /// @param inB: Ordinate or "dependent variable" values
    /// @param inTolerance (default 1e-12)
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<double> lstsq(const NdArray<dtype>& inA, const NdArray<dtype>& inB, double inTolerance = 1e-12)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        SVD          svdSolver(inA.template astype<double>());
        const double threshold = inTolerance * svdSolver.s().front();

        return svdSolver.solve(inB.template astype<double>(), threshold);
    }
} // namespace nc::linalg
