#!/usr/bin/python3
"""Module pour générer le triangle de Pascal."""


def pascal_triangle(n):
    """Génère le triangle de Pascal.

    Args:
        n (int): Le nombre de lignes du triangle de Pascal.

    Returns:
        list: Une liste de listes d'entiers représentant le triangle de Pascal.
    """
    if n <= 0:
        return []

    triangle = [[1]]

    for i in range(1, n):
        row = [1]
        for j in range(1, i):
            row.append(triangle[i-1][j-1] + triangle[i-1][j])
        row.append(1)
        triangle.append(row)

    return triangle
