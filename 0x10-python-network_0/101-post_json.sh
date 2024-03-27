#!/bin/bash
# Envoie requête POST avec le contenu d'un fichier JSON à une URL et affiche le corps de la réponse
curl -s -X POST -H "Content-Type: application/json" -d @"$2" "$1"

