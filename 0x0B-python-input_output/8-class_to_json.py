#!/usr/bin/python3
"""Module pour convertir un objet de classe en dictionnaire pour JSON."""


def class_to_json(obj):
    """Retourne la description d'un objet pour la sérialisation JSON.

    Args:
        obj: L'instance d'une classe.

    Returns:
        dict: Dictionnaire de description de l'objet.
    """
    return obj.__dict__
