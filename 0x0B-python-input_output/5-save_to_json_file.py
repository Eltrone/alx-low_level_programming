#!/usr/bin/python3
"""Module pour écrire un objet Python dans un fichier au format JSON."""

import json


def save_to_json_file(my_obj, filename):
    """Écrit un objet Python dans un fichier texte au format JSON.

    Args:
        my_obj: L'objet Python à sérialiser.
        filename (str): Le chemin du fichier où écrire.

    """
    with open(filename, 'w', encoding='utf-8') as f:
        json.dump(my_obj, f)
