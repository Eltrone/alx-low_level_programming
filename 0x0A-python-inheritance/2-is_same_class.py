#!/usr/bin/python3
""" Module pour la fonction is_same_class. """

def is_same_class(obj, a_class):
    """
    Vérifie si un objet est une instance exacte d'une classe spécifiée.

    Args:
        obj (any): L'objet à vérifier.
        a_class (type): La classe par rapport à laquelle comparer.

    Returns:
        bool: True si obj est une instance exacte de a_class, sinon False.
    """
    return type(obj) is a_class
