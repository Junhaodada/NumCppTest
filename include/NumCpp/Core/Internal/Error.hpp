
/// Description
/// Standard NumCpp errors
///
#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

#include "NumCpp/Core/Types.hpp"

// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define THROW_INVALID_ARGUMENT_ERROR(msg) \
    nc::error::throwError<std::invalid_argument>(__FILE__, __func__, __LINE__, msg)
// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define THROW_RUNTIME_ERROR(msg) nc::error::throwError<std::runtime_error>(__FILE__, __func__, __LINE__, msg)

namespace nc::error
{
    //============================================================================
    /// Makes the full error message string
    ///
    /// @param file: the file
    /// @param function: the function
    /// @param line: the line of the file
    /// @param msg: the message to throw (default "")
    ///
    template<typename ErrorType>
    void throwError(const std::string& file, const std::string& function, uint32 line, const std::string& msg = "")
    {
        std::string errMsg =
            "File: " + file + "\n\tFunction: " + function + "\n\tLine: " + std::to_string(line) + "\n\tError: " + msg;
        std::cerr << errMsg;
        throw ErrorType(errMsg);
    }
} // namespace nc::error
