#!/usr/bin/python3
""" Classe Square héritant de Rectangle. """

Rectangle = __import__('9-rectangle').Rectangle


class Square(Rectangle):
    """ Classe Square qui hérite de la classe Rectangle. """

    def __init__(self, size):
        """
        Initialise un nouveau carré.

        Args:
            size (int): La taille des côtés du carré entier positif.
        """
        self.integer_validator("size", size)
        super().__init__(size, size)
        self.__size = size

    def __str__(self):
        """ Retourne la description du carré. """
        return "[Square] {}/{}".format(self.__size, self.__size)
