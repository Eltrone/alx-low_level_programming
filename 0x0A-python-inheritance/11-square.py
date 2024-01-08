#!/usr/bin/python3
""" Module pour la classe Square qui hérite de Rectangle. """

Rectangle = __import__('9-rectangle').Rectangle


class Square(Rectangle):
    """ Classe Square héritant de Rectangle. """

    def __init__(self, size):
        """
        Initialise un nouveau carré.

        Args:
            size (int): La taille des côtés du carréentier positif.
        """
        self.integer_validator("size", size)
        super().__init__(size, size)
        self.__size = size
