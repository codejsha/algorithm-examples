import numpy as np

from algorithm.math.matrix_multiplication import multiply_matrix


def test_matrix_multiplication():
    matrix_a = np.array([[1, 2, 3], [4, 5, 6]])
    matrix_b = np.array([[1, 2], [3, 4], [5, 6]])
    assert np.array_equal(multiply_matrix(matrix_a, matrix_b), np.dot(matrix_a, matrix_b))
