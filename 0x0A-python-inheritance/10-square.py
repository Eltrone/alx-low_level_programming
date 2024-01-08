#!/usr/bin/python3
""" Module pour la classe Square qui hérite de Rectangle. """

Rectangle = __import__('9-rectangle').Rectangle


class Square(Rectangle):
    """ Classe Square qui hérite de Rectangle. """

    def __init__(self, size):
        """
        Initialise un nouveau Square.

        Args:
            size (int): La taille du côté du carré doit être un entier positif.
        """
        self.integer_validator("size", size)
        super().__init__(size, size)

    def area(self):
        """ Retourne l'aire du carré. """
        return self.__width ** 2
