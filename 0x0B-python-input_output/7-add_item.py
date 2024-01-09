#!/usr/bin/python3
"""Script pour ajouter des arguments à une liste et sauvegarder en JSON."""

import sys

if __name__ == "__main__":
    # Importation divisée en deux lignes pour réduire la longueur
    load_module = __import__('6-load_from_json_file')
    load_from_json_file = load_module.load_from_json_file
    save_to_json_file = __import__('5-save_to_json_file').save_to_json_file

    filename = "add_item.json"

    try:
        items = load_from_json_file(filename)
    except FileNotFoundError:
        items = []

    items.extend(sys.argv[1:])
    save_to_json_file(items, filename)
