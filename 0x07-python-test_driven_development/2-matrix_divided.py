#!/usr/bin/python3
def matrix_divided(matrix, div):
    """
    Divides matrix elements by a divisor.

    Args:
    matrix: List of lists of int/float.
    div: Divisor (int/float).

    Returns:
    New matrix with divided elements, rounded to 2 decimal places.

    Raises:
    TypeError: If matrix is not a list of lists of int/float, rows are not
               of the same size, or div is not a number.
    ZeroDivisionError: If div is zero.
    """
    if (not isinstance(matrix, list) or
            not all(isinstance(row, list) for row in matrix)):
        raise TypeError("matrix must be a matrix (list of lists) of integers/floats")
    if not all(isinstance(elem, (int, float))
               for row in matrix for elem in row):
        raise TypeError("matrix must be a matrix (list of lists) of integers/floats")
    if len(set(len(row) for row in matrix)) != 1:
        raise TypeError("Each row of the matrix must have the same size")
    if not isinstance(div, (int, float)):
        raise TypeError("div must be a number")
    if div == 0:
        raise ZeroDivisionError("division by zero")

    return [[round(elem / div, 2) for elem in row] for row in matrix]
