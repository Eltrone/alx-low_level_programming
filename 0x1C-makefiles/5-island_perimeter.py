#!/usr/bin/python3
"""
Module pour calculer le périmètre d'une île dans une grille
"""


def island_perimeter(grid):
    """
    Retourne le périmètre de l'île décrite dans grid
    """
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i-1][j] == 1:  # vérifie au nord
                    perimeter -= 2
                if j > 0 and grid[i][j-1] == 1:  # vérifie à l'ouest
                    perimeter -= 2
    return perimeter
