#!/usr/bin/python3
"""Module pour définir la classe Rectangle."""


class Rectangle:
    """Classe qui définit un rectangle."""

    def __init__(self, width=0, height=0):
        """Initialisation de la classe Rectangle."""
        self.width = width
        self.height = height

    @property
    def width(self):
        """Getter pour width."""
        return self.__width

    @width.setter
    def width(self, value):
        """Setter pour width."""
        if not isinstance(value, int):
            raise TypeError("width must be an integer")
        if value < 0:
            raise ValueError("width must be >= 0")
        self.__width = value

    @property
    def height(self):
        """Getter pour height."""
        return self.__height

    @height.setter
    def height(self, value):
        """Setter pour height."""
        if not isinstance(value, int):
            raise TypeError("height must be an integer")
        if value < 0:
            raise ValueError("height must be >= 0")
        self.__height = value
