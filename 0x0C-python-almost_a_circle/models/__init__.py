#!/usr/bin/python3
"""Module base.py - Defines a base class for all models in the project."""


class Base:
    """Base class for all other classes in the project."""
    __nb_objects = 0  # Private class attribute

    def __init__(self, id=None):
        """Initializes the Base instance.

        Args:
            id (int): The id of the instance. If None, increment __nb_objects.
        """
        if id is not None:
            self.id = id
        else:
            Base.__nb_objects += 1
            self.id = Base.__nb_objects
