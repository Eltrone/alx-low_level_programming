#!/usr/bin/python3
""" Ajoute tous les arguments à une liste Python, puis enregistre cette liste dans un fichier """
import sys

if __name__ == "__main__":
    # Importation des fonctions depuis les fichiers 5-save_to_json_file et 6-load_from_json_file
    save_to_json_file = __import__('5-save_to_json_file').save_to_json_file
    load_from_json_file = __import__('6-load_from_json_file').load_from_json_file

    try:
        # Chargement de la liste existante depuis le fichier
        items = load_from_json_file("add_item.json")
    except FileNotFoundError:
        # Si le fichier n'existe pas, initialiser une liste vide
        items = []

    # Ajout des arguments de la ligne de commande à la liste
    items.extend(sys.argv[1:])

    # Enregistrement de la liste mise à jour dans le fichier add_item.json
    save_to_json_file(items, "add_item.json")
