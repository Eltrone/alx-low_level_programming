#!/usr/bin/python3
"""Module pour définir la classe Rectangle."""


class Rectangle:
    """Classe qui définit un rectangle."""

    number_of_instances = 0
    print_symbol = "#"

    def __init__(self, width=0, height=0):
        """Initialise Rectangle."""
        Rectangle.number_of_instances += 1
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

    def area(self):
        """Retourne l'aire du rectangle."""
        return self.__width * self.__height

    def perimeter(self):
        """Retourne le périmètre du rectangle."""
        if self.__width == 0 or self.__height == 0:
            return 0
        return 2 * (self.__width + self.__height)

    def __str__(self):
        """Représentation en chaîne de caractères."""
        if self.__width == 0 or self.__height == 0:
            return ""
        symbol = str(self.print_symbol)
        rect_lines = [symbol * self.__width for _ in range(self.__height)]
        return "\n".join(rect_lines)

    def __repr__(self):
        """Représentation pour recréer un nouveau rectangle."""
        return f"Rectangle({self.__width}, {self.__height})"

    def __del__(self):
        """Affiche un message lors de la suppression d'une instance."""
        Rectangle.number_of_instances -= 1
        print("Bye rectangle...")

    @staticmethod
    def bigger_or_equal(rect_1, rect_2):
        """Retourne le plus grand rectangle basé sur l'aire."""
        if not isinstance(rect_1, Rectangle):
            raise TypeError("rect_1 must be an instance of Rectangle")
        if not isinstance(rect_2, Rectangle):
            raise TypeError("rect_2 must be an instance of Rectangle")
        if rect_1.area() >= rect_2.area():
            return rect_1
        return rect_2