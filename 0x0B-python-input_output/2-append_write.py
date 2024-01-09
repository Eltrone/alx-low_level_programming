#!/usr/bin/python3
"""Module pour ajouter une chaîne à la fin d'un fichier texte."""


def append_write(filename="", text=""):
    """Ajoute une chaîne à la fin d'un fichier texte.

    Args:
        filename (str): Le chemin vers le fichier à modifier.
        text (str): Le texte à ajouter à la fin du fichier.

    Returns:
        int: Le nombre de caractères ajoutés.
    """
    with open(filename, 'a', encoding='utf-8') as f:
        return f.write(text)
