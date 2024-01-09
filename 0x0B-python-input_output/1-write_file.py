#!/usr/bin/python3
"""Module pour écrire une chaîne dans un fichier texte."""


def write_file(filename="", text=""):
    """Écrit une chaîne dans un fichier texte.

    Args:
        filename (str): Le chemin vers le fichier à écrire.
        text (str): Le texte à écrire dans le fichier.

    Returns:
        int: Le nombre de caractères écrits.
    """
    with open(filename, 'w', encoding='utf-8') as f:
        return f.write(text)
