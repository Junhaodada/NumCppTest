
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <filesystem>
#include <fstream>
#include <memory>
#include <sstream>
#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Functions/fromstring.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Construct an array from data in a binary file.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.fromfile.html
    ///
    /// @param inFilename
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> fromfile(const std::string& inFilename)
    {
        if (!std::filesystem::exists(inFilename))
        {
            THROW_INVALID_ARGUMENT_ERROR("input filename does not exist.\n\t" + inFilename);
        }

        // read in as binary file
        std::ifstream file(inFilename.c_str(), std::ios::in | std::ios::binary);
        if (!file.is_open())
        {
            THROW_INVALID_ARGUMENT_ERROR("unable to open file\n\t" + inFilename);
        }

        file.seekg(0, std::ifstream::end);
        const uint32 fileSize = static_cast<uint32>(file.tellg());
        file.seekg(0, std::ifstream::beg);

        std::vector<char> fileBuffer;
        fileBuffer.reserve(fileSize);
        file.read(fileBuffer.data(), fileSize);

        if (file.bad() || file.fail())
        {
            THROW_INVALID_ARGUMENT_ERROR("error occured while reading the file");
        }

        file.close();

        NdArray<dtype> returnArray(reinterpret_cast<dtype*>(fileBuffer.data()), fileSize / sizeof(dtype));

        return returnArray;
    }

    //============================================================================
    // Method Description:
    /// Construct an array from data in a text file.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.fromfile.html
    ///
    /// @param inFilename
    /// @param inSep: Delimiter separator between values in the file
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> fromfile(const std::string& inFilename, const char inSep)
    {
        std::ifstream file(inFilename.c_str());
        if (!file.is_open())
        {
            THROW_INVALID_ARGUMENT_ERROR("unable to open file\n\t" + inFilename);
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        file.close();

        return fromstring<dtype>(buffer.str(), inSep);
    }
} // namespace nc
