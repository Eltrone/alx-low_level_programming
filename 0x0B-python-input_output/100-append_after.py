#!/usr/bin/python3
"""Module pour insérer une ligne après une chaîne spécifique dans un fichier."""


def append_after(filename="", search_string="", new_string=""):
    """Insère une ligne de texte après chaque ligne contenant chaîne spécifique.

    Args:
        filename (str): Le chemin du fichier à modifier.
        search_string (str): La chaîne à rechercher dans le fichier.
        new_string (str): La nouvelle chaîne à insérer.
    """
    with open(filename, 'r', encoding='utf-8') as file:
        lines = file.readlines()

    with open(filename, 'w', encoding='utf-8') as file:
        for line in lines:
            file.write(line)
            if search_string in line:
                file.write(new_string)
