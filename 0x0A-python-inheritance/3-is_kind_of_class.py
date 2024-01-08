#!/usr/bin/python3
""" Module pour la fonction is_kind_of_class. """

def is_kind_of_class(obj, a_class):
    """
    Vérifie si l'objet est une instance de, ou s'il est une instance d'une classe
    qui a hérité de, la classe spécifiée.

    Args:
        obj (any): L'objet à vérifier.
        a_class (type): La classe à comparer.

    Returns:
        bool: True si obj est une instance de a_class ou hérite de a_class, sinon False.
    """
    return isinstance(obj, a_class)
