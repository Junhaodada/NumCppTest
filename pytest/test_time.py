import time
import numpy as np
from scipy.linalg import lu, cholesky, svd
from scipy.io import mmread


def read_mtx(file_path='data\F2\F2.mtx'):
    """读取 mtx 格式文件"""
    matrix: np.matrix = mmread(file_path).T.tocsr().astype('float64').todense()
    return matrix


def generate_positive_definite_matrix_cholesky(size):
    """"生成正定矩阵"""
    L = np.random.rand(size, size)
    A = np.dot(L, L.T)
    return A


if __name__ == '__main__':
    size = 3000
    # A = read_mtx()

    A = generate_positive_definite_matrix_cholesky(size)
    start_time = time.time()
    # 随机方阵
    # A = np.random.randint(0, 1000, (size, size))
    # 矩阵乘法测试
    # res = A.dot(A)
    # 矩阵排序测试
    # A.sort(axis=0)
    # LU 分解测试
    # p, l, u = lu(A)
    # cholesky 分解测试
    L = cholesky(A)

    end_time = time.time()
    run_time = 1000 * (end_time - start_time)
    print("Elapsed Time = {:.0f} milliseconds".format(run_time))
