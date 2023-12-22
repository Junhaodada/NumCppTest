
/// Description
/// Calculate a one-dimensional gaussian filter.
///
#pragma once

#include <cmath>
#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Filter/Boundaries/Boundary.hpp"
#include "NumCpp/Filter/Filters/Filters1d/convolve1d.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Utils/gaussian1d.hpp"

namespace nc::filter
{
    //============================================================================
    // Method Description:
    /// Calculate a one-dimensional gaussian filter.
    ///
    /// SciPy Reference:
    /// https://docs.scipy.org/doc/scipy/reference/generated/scipy.ndimage.generic_filter1d.html#scipy.ndimage.generic_filter1d
    ///
    /// @param inImageArray
    /// @param inSigma: Standard deviation for Gaussian kernel
    /// @param inBoundaryType: boundary mode (default Reflect) options (reflect, constant, nearest, mirror, wrap)
    /// @param inConstantValue: contant value if boundary = 'constant' (default 0)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> gaussianFilter1d(const NdArray<dtype>& inImageArray,
                                    double                inSigma,
                                    Boundary              inBoundaryType  = Boundary::REFLECT,
                                    dtype                 inConstantValue = 0)
    {
        if (inSigma <= 0)
        {
            THROW_INVALID_ARGUMENT_ERROR("input sigma value must be greater than zero.");
        }

        // calculate the kernel size based off of the input sigma value
        constexpr uint32 MIN_KERNEL_SIZE = 5;
        uint32           kernelSize =
            std::max(static_cast<uint32>(std::ceil(inSigma * 2. * 4.)), MIN_KERNEL_SIZE); // 4 standard deviations
        if (kernelSize % 2 == 0)
        {
            ++kernelSize; // make sure the kernel is an odd size
        }

        const auto kernalHalfSize = static_cast<double>(kernelSize / 2); // integer division

        // calculate the gaussian kernel
        NdArray<double> kernel(1, kernelSize);
        for (double i = 0; i < kernelSize; ++i)
        {
            kernel[static_cast<uint32>(i)] = utils::gaussian1d(i - kernalHalfSize, 0., inSigma);
        }

        // normalize the kernel
        kernel /= kernel.sum().item();

        // perform the convolution
        NdArray<dtype> output =
            convolve1d(inImageArray.template astype<double>(), kernel, inBoundaryType, inConstantValue)
                .template astype<dtype>();

        return output;
    }
} // namespace nc::filter
