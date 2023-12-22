
/// Description
/// Seeds the random number generator
///
#pragma once

#include <random>

namespace nc::random
{
    /// generator function
    static std::mt19937_64 generator_;

    //============================================================================
    // Method Description:
    /// Seeds the random number generator
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.random.seed.html#numpy.random.seed
    ///
    /// @param inSeed
    ///
    inline void seed(int inSeed)
    {
        generator_.seed(inSeed);
    }
} // namespace nc::random
