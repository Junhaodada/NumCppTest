#include <filesystem>
#include <iostream>

#include "NumCpp.hpp"

// 生成正定矩阵
auto create_positive_define_matrix(nc::uint32 size) {
  auto L = nc::random::rand<double>({size, size});
  auto A = L.dot(L.transpose());
  // std::cout << A << std::endl;
  return A;
}

// 测试时间
void test_time() {
  nc::Timer time;
  // nc::NdArray<int> a0 = {{1, 2}, {3, 4}};
  nc::uint32 size = 3000;
  // auto A = nc::random::rand<double>({size, size});

  auto A = create_positive_define_matrix(size);
  time.tic();
  // A.dot(A);
  // A.sort();
  // nc::linalg::lu_decomposition(A);
  nc::linalg::cholesky(A);
  time.toc();
  std::cout << A.shape() << std::endl;
}

int main() {
  test_time();
  return 0;
}