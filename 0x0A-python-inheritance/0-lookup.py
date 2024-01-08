#!/usr/bin/python3
"""
Module 0-lookup.
Définit une fonction pour rechercher les attributs d'un objet.
"""


def lookup(obj):
    """
    Retourne la liste des attributs et méthodes disponibles d'un objet.

    Args:
        obj (any): L'objet pour lequel chercher les attributs et méthodes.

    Returns:
        list: Liste des attributs et méthodes de l'objet.
    """
    return dir(obj)
