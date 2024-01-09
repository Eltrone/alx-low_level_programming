#!/usr/bin/python3
"""Module pour lire et imprimer le contenu d'un fichier texte."""


def read_file(filename=""):
    """Lit un fichier texte et imprime son contenu.

    Args:
        filename (str): Le chemin vers le fichier à lire.
    """
    with open(filename, 'r', encoding='utf-8') as f:
        print(f.read(), end='')
