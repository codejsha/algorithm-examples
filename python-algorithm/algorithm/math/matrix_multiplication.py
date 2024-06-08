import numpy as np


def multiply_matrix(matrix_a: np.array, matrix_b: np.array) -> np.array:
    """
    Function that performs matrix multiplication.
    If you use numpy, it is np.dot(matrix_a, matrix_b)
    :param matrix_a: matrix1
    :param matrix_b: matrix2
    :return: the result of matrix multiplication
    """
    m = matrix_a.shape[0]
    n = matrix_b.shape[1]
    matrix_c = np.zeros((m, n))

    p = matrix_b.shape[0]

    for i in range(m):
        for j in range(n):
            for k in range(p):
                matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j]

    return matrix_c
