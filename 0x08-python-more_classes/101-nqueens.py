#!/usr/bin/python3
import sys


def print_solution(board):
    """Imprime la solution du problème des N reines."""
    solution = []
    for row in range(len(board)):
        for col in range(len(board)):
            if board[row][col] == 1:
                solution.append([row, col])
    print(solution)


def is_safe(board, row, col):
    """Vérifie si une reine peut être placée en (row, col)."""
    for i in range(len(board)):
        if board[row][i] == 1 or board[i][col] == 1:
            return False
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    for i, j in zip(range(row, -1, -1), range(col, len(board))):
        if board[i][j] == 1:
            return False
    return True


def solve_nqueens(board, col):
    """Résout le problème des N reines."""
    if col >= len(board):
        print_solution(board)
        return
    for i in range(len(board)):
        if is_safe(board, i, col):
            board[i][col] = 1
            solve_nqueens(board, col + 1)
            board[i][col] = 0


def nqueens(n):
    """Initialise et lance le problème des N reines."""
    board = [[0 for _ in range(n)] for _ in range(n)]
    solve_nqueens(board, 0)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)
    nqueens(n)
