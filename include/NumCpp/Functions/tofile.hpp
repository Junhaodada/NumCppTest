
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
    /// Write array to a file as binary.
    /// The data produced by this method can be recovered
    /// using the function fromfile().
    ///
    /// @param inArray
    /// @param inFilename
    ///
    template<typename dtype>
    void tofile(const NdArray<dtype>& inArray, const std::string& inFilename)
    {
        return inArray.tofile(inFilename);
    }

    //============================================================================
    // Method Description:
    /// Write array to a file as text.
    /// The data produced by this method can be recovered
    /// using the function fromfile().
    ///
    /// @param inArray
    /// @param inFilename
    /// @param inSep: Separator between array items for text output.
    ///
    template<typename dtype>
    void tofile(const NdArray<dtype>& inArray, const std::string& inFilename, const char inSep)
    {
        return inArray.tofile(inFilename, inSep);
    }
} // namespace nc
