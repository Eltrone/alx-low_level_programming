#!/usr/bin/python3
import numpy as np

def lazy_matrix_mul(m_a, m_b):
    """
    Multiplies 2 matrices using NumPy.

    Args:
    m_a (list of lists of ints/floats): The first matrix.
    m_b (list of lists of ints/floats): The second matrix.

    Returns:
    numpy.ndarray: The product of the matrices.
    """
    return np.matmul(m_a, m_b)
