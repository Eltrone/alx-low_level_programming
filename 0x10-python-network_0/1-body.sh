#!/bin/bash
# envoie une requête GET à une URL et affiche uniquement le corps de la réponse pour un code de statut 200
curl -sf "$1"
