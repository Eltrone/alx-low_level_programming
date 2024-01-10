#!/usr/bin/python3

def matrix_mul(m_a, m_b):
    """
    Multiplies 2 matrices.

    Args:
    m_a (list of lists of ints/floats): The first matrix.
    m_b (list of lists of ints/floats): The second matrix.

    Raises:
    TypeError: If m_a or m_b are not lists of lists of integers or floats,
               or if they are not rectangular, or if one is empty.
    ValueError: If m_a and m_b cannot be multiplied due to size mismatch.

    Returns:
    list: A new matrix which is the product of m_a and m_b.
    """
    if not all(isinstance(row, list) for row in m_a) or not isinstance(m_a, list):
        raise TypeError("m_a must be a list of lists")
    if not all(isinstance(row, list) for row in m_b) or not isinstance(m_b, list):
        raise TypeError("m_b must be a list of lists")
    if m_a == [] or m_a == [[]]:
        raise ValueError("m_a can't be empty")
    if m_b == [] or m_b == [[]]:
        raise ValueError("m_b can't be empty")
    if not all(isinstance(el, (int, float)) for row in m_a for el in row):
        raise TypeError("m_a should contain only integers or floats")
    if not all(isinstance(el, (int, float)) for row in m_b for el in row):
        raise TypeError("m_b should contain only integers or floats")
    if not all(len(row) == len(m_a[0]) for row in m_a):
        raise TypeError("each row of m_a must be of the same size")
    if not all(len(row) == len(m_b[0]) for row in m_b):
        raise TypeError("each row of m_b must be of the same size")
    if len(m_a[0]) != len(m_b):
        raise ValueError("m_a and m_b can't be multiplied")

    return [[sum(a * b for a, b in zip(row_a, col_b)) for col_b in zip(*m_b)] for row_a in m_a]
