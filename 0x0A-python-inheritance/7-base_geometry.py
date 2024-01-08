#!/usr/bin/python3
""" Module pour la classe BaseGeometry avec validateur d'entiers. """


class BaseGeometry:
    """ Classe BaseGeometry avec méthodes area integer_validator. """

    def area(self):
        """ Lève une exception indiquant que la méthode area()"
        " n'est pas implémentée. """
        raise Exception("area() is not implemented")

    def integer_validator(self, name, value):
        """
        Valide si une valeur est un entier positif.

        Args:
            name (str): Le nom de la variable.
            value (int): La valeur à valider.

        Raises:
            TypeError: Si la valeur n'est pas un entier.
            ValueError: Si la valeur est inférieure ou égale à 0.
        """
        if type(value) is not int:
            raise TypeError("{} must be an integer".format(name))
        if value <= 0:
            raise ValueError("{} must be greater than 0".format(name))
