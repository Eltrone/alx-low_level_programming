#!/usr/bin/python3
"""Define a class Square with a method to calculate its area."""


class Square:
    """Represent a square with a method to calculate its area."""

    def __init__(self, size=0):
        """Initialize the class with size validation.

        Args:
            size (int): The size of the new square, defaults to 0.

        Raises:
            TypeError: If size is not an integer.
            ValueError: If size is less than 0.
        """
        if not isinstance(size, int):
            raise TypeError("size must be an integer")
        if size < 0:
            raise ValueError("size must be >= 0")
        self.__size = size

    def area(self):
        """Return the current square area."""
        return self.__size ** 2
