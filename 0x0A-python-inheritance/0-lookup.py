#!/usr/bin/python3
def lookup(obj):
    """
    Retourne la liste des attributs et méthodes disponibles d'un objet

    Args:
        obj (any): L'objet pour lequel chercher les attributs et méthodes.

    Returns:
        list: Liste des attributs et méthodes de l'objet.
    """
    return dir(obj)
