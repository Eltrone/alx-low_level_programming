#!/usr/bin/python3
""" Module pour la classe MyInt qui hérite de int. """


class MyInt(int):
    """ Classe MyInt qui hérite de int avec opérateurs == et != inversés. """

    def __eq__(self, other):
        """ Inverse l'opérateur ==. """
        return super().__ne__(other)

    def __ne__(self, other):
        """ Inverse l'opérateur !=. """
        return super().__eq__(other)
