#!/bin/bash
# Envoie requête POST avec le contenu d'un fichier JSON à une URL et affiche le corps de la réponse
curl -s -H "Content-Type: application/json" -d "$(cat "$2")" "$1"
