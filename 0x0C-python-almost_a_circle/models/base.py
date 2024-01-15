#!/usr/bin/python3
""" Module base.py: Defines the Base class for all models. """


class Base:
    """
    Base class for all other classes in the project.
    This class manages the id attribute for all future classes and
    avoids duplicating the same code (and by extension, the same bugs).
    """

    __nb_objects = 0  # Private class attribute to count number of instances

    def __init__(self, id=None):
        """
        Initializes the Base instance.

        Args:
            id (int, optional): The instance id. If None auto-generated
            id is assigned using the private __nb_objects attribute.
        """
        if id is not None:
            self.id = id
        else:
            Base.__nb_objects += 1
            self.id = Base.__nb_objects
