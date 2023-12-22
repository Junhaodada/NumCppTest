
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <string>

#include "NumCpp/Functions/fromfile.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// loads a .bin file from the dump() method into an NdArray
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.load.html
    ///
    /// @param inFilename
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> load(const std::string& inFilename)
    {
        return fromfile<dtype>(inFilename);
    }
} // namespace nc
