
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <functional>
#include <numeric>
#include <vector>

#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Construct an array by executing a function over each coordinate.
    /// The resulting array therefore has a value fn(x) at coordinate(x).
    ///
    ///  NumPy Reference: https://numpy.org/doc/stable/reference/generated/numpy.fromfunction.html
    ///
    ///  @param func: callable that accepts an integer coordinate and returns type T
    ///  @param size: the size of the 1d array to create
    ///
    ///  @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> fromfunction(const std::function<dtype(typename NdArray<dtype>::size_type)> func,
                                typename NdArray<dtype>::size_type                             size)
    {
        NdArray<dtype> result(1, size);
        const auto     indices = [size]
        {
            std::vector<typename NdArray<dtype>::size_type> temp(size);
            std::iota(temp.begin(), temp.end(), 0);
            return temp;
        }();

        stl_algorithms::transform(indices.begin(),
                                  indices.end(),
                                  result.begin(),
                                  [&func](const auto idx) { return func(idx); });

        return result;
    }

    //============================================================================
    // Method Description:
    /// Construct an array by executing a function over each coordinate.
    /// The resulting array therefore has a value fn(x, y) at coordinate(x, y).
    ///
    ///  NumPy Reference: https://numpy.org/doc/stable/reference/generated/numpy.fromfunction.html
    ///
    ///  @param func: callable that accepts an integer coordinate and returns type T
    ///  @param shape: the shape of the array to create
    ///
    ///  @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> fromfunction(
        const std::function<dtype(typename NdArray<dtype>::size_type, typename NdArray<dtype>::size_type)> func,
        Shape                                                                                              shape)
    {
        NdArray<dtype> result(shape);
        const auto     rows = [&shape]
        {
            std::vector<typename NdArray<dtype>::size_type> temp(shape.rows);
            std::iota(temp.begin(), temp.end(), 0);
            return temp;
        }();
        const auto cols = [&shape]
        {
            std::vector<typename NdArray<dtype>::size_type> temp(shape.cols);
            std::iota(temp.begin(), temp.end(), 0);
            return temp;
        }();

        stl_algorithms::for_each(rows.begin(),
                                 rows.end(),
                                 [&cols, &result, &func](const auto row)
                                 {
                                     stl_algorithms::transform(cols.begin(),
                                                               cols.end(),
                                                               result.begin(row),
                                                               [&func, row](const auto col) { return func(row, col); });
                                 });

        return result;
    }
} // namespace nc
