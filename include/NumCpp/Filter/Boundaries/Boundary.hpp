
/// Description
/// Boundary condition to apply to the image filter
///
#pragma once

namespace nc::filter
{
    //================================================================================
    // Enum Description:
    /// Boundary condition to apply to the image filter
    enum class Boundary
    {
        REFLECT = 0,
        CONSTANT,
        NEAREST,
        MIRROR,
        WRAP
    };
} // namespace nc::filter
