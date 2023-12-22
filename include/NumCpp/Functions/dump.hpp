
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <string>

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Dump a binary file of the array to the specified file.
    /// The array can be read back with or NC::load.
    ///
    /// @param inArray
    /// @param inFilename
    ///
    template<typename dtype>
    void dump(const NdArray<dtype>& inArray, const std::string& inFilename)
    {
        inArray.dump(inFilename);
    }
} // namespace nc
