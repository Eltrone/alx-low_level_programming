#!/usr/bin/python3
""" Module square.py - Defines Square class, inheriting from Rectangle. """

from models.rectangle import Rectangle


class Square(Rectangle):
    """
    Square class that inherits from Rectangle.

    Attributes are inherited from Rectangle.
    """

    def __init__(self, size, x=0, y=0, id=None):
        """
        Initializes a new Square instance.

        Args:
            size (int): The size of the square's sides.
            x (int): The x coordinate of the square.
            y (int): The y coordinate of the square.
            id (int): The id of the square.
        """
        super().__init__(size, size, x, y, id)

    def __str__(self):
        """Return a string representation of the Square."""
        return ("[Square] ({id}) {x}/{y} - {size}"
                .format(id=self.id, x=self.x, y=self.y, size=self.width))
