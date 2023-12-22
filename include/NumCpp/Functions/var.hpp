
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <algorithm>
#include <complex>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Functions/stdev.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Compute the variance along the specified axis.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.var.html
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<double> var(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        NdArray<double> stdValues = stdev(inArray, inAxis);
        const auto      function  = [](double& value) -> void { value *= value; };

        stl_algorithms::for_each(stdValues.begin(), stdValues.end(), function);
        return stdValues;
    }

    //============================================================================
    // Method Description:
    /// Compute the variance along the specified axis.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.var.html
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<double>> var(const NdArray<std::complex<dtype>>& inArray, Axis inAxis = Axis::NONE)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        NdArray<std::complex<double>> stdValues = stdev(inArray, inAxis);
        const auto                    function  = [](std::complex<double>& value) -> void { value *= value; };

        stl_algorithms::for_each(stdValues.begin(), stdValues.end(), function);
        return stdValues;
    }
} // namespace nc
