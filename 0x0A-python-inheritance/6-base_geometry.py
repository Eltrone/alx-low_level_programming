#!/usr/bin/python3
""" Module pour la classe BaseGeometry. """


class BaseGeometry:
    """ Classe BaseGeometry avec méthode area non implémentée. """

    def area(self):
        """ Lève une exception avec un message indiquant"
        "que la méthode n'est pas implémentée. """
        raise Exception("area() is not implemented")
