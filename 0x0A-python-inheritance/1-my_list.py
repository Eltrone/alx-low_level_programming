#!/usr/bin/python3
""" Module pour la classe MyList qui hérite de list. """

class MyList(list):
    """ Classe MyList qui hérite de la classe intégrée list. """

    def print_sorted(self):
        """ Imprime la liste dans un ordre trié. """
        print(sorted(self))
