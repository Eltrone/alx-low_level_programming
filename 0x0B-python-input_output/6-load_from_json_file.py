#!/usr/bin/python3
"""Module pour créer un objet à partir d'un fichier JSON."""

import json


def load_from_json_file(filename):
    """Crée un objet à partir d'un fichier JSON.

    Args:
        filename (str): Le chemin du fichier JSON à charger.

    Returns:
        L'objet Python créé à partir du fichier JSON.
    """
    with open(filename, 'r', encoding='utf-8') as f:
        return json.load(f)
