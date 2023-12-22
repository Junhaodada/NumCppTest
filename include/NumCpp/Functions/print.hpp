
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <iostream>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Prints the array to the console.
    ///
    /// @param inArray
    ///
    template<typename dtype>
    void print(const NdArray<dtype>& inArray)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        std::cout << inArray;
    }
} // namespace nc
