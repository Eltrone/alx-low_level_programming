#!/usr/bin/python3
""" Ajoute les arguments à une liste, puis enregistre dans un fichier """

import sys

if __name__ == "__main__":
    # Importation des fonctions nécessaires
    save_json = __import__('5-save_to_json_file').save_to_json_file
    load_json = __import__('6-load_from_json_file').load_from_json_file

    try:
        # Chargement de la liste existante
        items = load_json("add_item.json")
    except FileNotFoundError:
        # Initialisation d'une liste vide
        items = []

    # Ajout des arguments à la liste
    items.extend(sys.argv[1:])

    # Sauvegarde de la liste dans un fichier
    save_json(items, "add_item.json")
