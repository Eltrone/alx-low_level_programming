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

    @property
    def size(self):
        """
        Getter method for size attribute.

        Returns:
            int: The size of the square.

        """
        return self.width

    @size.setter
    def size(self, value):
        """
        Setter method for size attribute.

        Args:
            value (int): The new size value.

        Raises:
            ValueError: If value is not a positive integer.
            TypeError: If value is not an integer.

        """
        if not isinstance(value, int):
            raise TypeError("width must be an integer")
        if value <= 0:
            raise ValueError("width must be > 0")
        self.width = value
        self.height = value

    def update(self, *args, **kwargs):
        """
        Update the attributes of the square.

        Args:
            *args (list): List of arguments in order id, size, x, y.
            **kwargs (dict): Dictionary of keyword arguments.

        """
        if args:
            attributes = ["id", "size", "x", "y"]
            for i, arg in enumerate(args):
                setattr(self, attributes[i], arg)
        else:
            for key, value in kwargs.items():
                setattr(self, key, value)

    def __str__(self):
        """Return a string representation of the Square."""
        return ("[Square] ({id}) {x}/{y} - {size}"
                .format(id=self.id, x=self.x, y=self.y, size=self.width))
