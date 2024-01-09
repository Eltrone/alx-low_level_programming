#!/usr/bin/python3
"""Module pour convertir un objet Python en une chaîne JSON."""

import json


def to_json_string(my_obj):
    """Renvoie la représentation JSON d'un objet Python.

    Args:
        my_obj: L'objet Python à sérialiser en JSON.

    Returns:
        str: La représentation JSON de l'objet.
    """
    return json.dumps(my_obj)
