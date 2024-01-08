#!/usr/bin/python3
""" Module pour la fonction inherits_from. """


def inherits_from(obj, a_class):
    """
    Vérifie objet est une instance d'une classe qui a hérité (directement ou
    indirectement) de la classe spécifiée.

    Args:
        obj (any): L'objet à vérifier.
        a_class (type): La classe à comparer.

    Returns:
        bool: True si obj est instance d'une classe qui a hérité de a_class,
        sinon False.
    """
    return isinstance(obj, a_class) and type(obj) != a_class
