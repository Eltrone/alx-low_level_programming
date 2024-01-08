#!/usr/bin/python3
""" Module pour la classe Rectangle qui hérite de BaseGeometry. """

BaseGeometry = __import__('7-base_geometry').BaseGeometry


class Rectangle(BaseGeometry):
    """ Classe Rectangle qui hérite de BaseGeometry. """

    def __init__(self, width, height):
        """
        Initialise un nouveau Rectangle.

        Args:
            width (int): La largeur du rectangle, doit être un entier positif.
            height (int): La hauteur du rectangle, doit être un entier positif.
        """
        self.integer_validator("width", width)
        self.integer_validator("height", height)
        self.__width = width
        self.__height = height

    def area(self):
        """ Retourne l'aire du rectangle. """
        return self.__width * self.__height

    def __str__(self):
        """ Retourne la description du rectangle. """
        return "[Rectangle] {}/{}".format(self.__width, self.__height)
