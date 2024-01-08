#!/usr/bin/python3
""" Module pour ajouter un attribut à un objet si possible. """


def add_attribute(obj, name, value):
    """
    Ajoute un nouvel attribut à un objet si c'est possible.

    Args:
        obj (object): L'objet auquel ajouter l'attribut.
        name (str): Le nom de l'attribut à ajouter.
        value (any): La valeur de l'attribut.

    Raises:
        TypeError: Si l'attribut ne peut pas être ajouté.
    """
    if not hasattr(obj, '__dict__'):
        raise TypeError("can't add new attribute")
    setattr(obj, name, value)
