
/// Description
/// Enumerations
///
#pragma once

namespace nc
{
    //================================================================================
    // Class Description:
    /// Enum To describe an axis
    enum class Axis
    {
        NONE = 0,
        ROW,
        COL
    };

    //================================================================================
    // Class Description:
    /// Enum for endianess
    enum class Endian
    {
        NATIVE = 0,
        BIG,
        LITTLE
    };

    //================================================================================
    // Class Description:
    /// Policy for NdArray constructor that takes in a pointer to data
    enum class PointerPolicy
    {
        COPY,
        SHELL
    };

    //================================================================================
    // Class Description:
    /// Bias boolean
    enum class Bias : bool
    {
        YES = true,
        NO  = false
    };

    //================================================================================
    // Class Description:
    /// End Point boolean
    enum class EndPoint : bool
    {
        YES = true,
        NO  = false
    };

    //================================================================================
    // Class Description:
    /// Increasing boolean
    enum class Increasing : bool
    {
        YES = true,
        NO  = false
    };

    //================================================================================
    // Class Description:
    /// Is Roots boolean
    enum class IsRoots : bool
    {
        YES = true,
        NO  = false
    };

    //================================================================================
    // Class Description:
    /// Replace boolean
    enum class Replace : bool
    {
        YES = true,
        NO  = false
    };

    //================================================================================
    // Class Description:
    /// Print Elapsed Time boolean
    enum class PrintElapsedTime : bool
    {
        YES = true,
        NO  = false
    };

    //================================================================================
    // Class Description:
    /// Print Results boolean
    enum class PrintResults : bool
    {
        YES = true,
        NO  = false
    };

    //============================================================================
    // Class Description:
    /// Right or Left side
    ///
    enum class Side
    {
        LEFT,
        RIGHT
    };

    //============================================================================
    // Class Description:
    /// Interpolation method
    ///
    enum class InterpolationMethod
    {
        LINEAR,
        LOWER,
        HIGHER,
        NEAREST,
        MIDPOINT
    };
} // namespace nc