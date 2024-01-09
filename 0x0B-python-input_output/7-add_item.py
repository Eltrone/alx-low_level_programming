#!/usr/bin/python3
import sys

# Assurez-vous d'avoir les fonctions load_from_json_file 
# et save_to_json_file définies dans les fichiers respectifs
from 5-save_to_json_file import save_to_json_file
from 6-load_from_json_file import load_from_json_file

file_name = "add_item.json"

try:
    items = load_from_json_file(file_name)
except (FileNotFoundError, TypeError):
    items = []

# Ajouter les arguments de la ligne de commande à la liste 
#en excluant le nom du script
items.extend(sys.argv[1:])

# Enregistrer la liste mise à jour dans le fichier JSON
save_to_json_file(items, file_name)

