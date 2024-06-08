import numpy as np
import pytest

from algorithm.math.matrix_multiplication import multiply_matrix

matrix_a = np.array([[1, 2, 3], [4, 5, 6]])
matrix_b = np.array([[1, 2], [3, 4], [5, 6]])
matrix_ab = np.array([[22, 28], [49, 64]])


@pytest.mark.benchmark(group='matrix_multiplication')
@pytest.mark.parametrize(
    argnames='a, b, expected',
    argvalues=[(matrix_a, matrix_b, matrix_ab)],
    ids=['multiply_matrix'])
def test_matrix_multiplication1(benchmark, a, b, expected):
    result = benchmark(multiply_matrix, a, b)
    assert np.array_equal(expected, result)


@pytest.mark.benchmark(group='matrix_multiplication')
@pytest.mark.parametrize(
    argnames='a, b, expected',
    argvalues=[(matrix_a, matrix_b, matrix_ab)],
    ids=['np.dot'])
def test_matrix_multiplication2(benchmark, a, b, expected):
    result = benchmark(np.dot, a, b)
    assert np.array_equal(expected, result)
