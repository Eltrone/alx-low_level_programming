#!/bin/bash
# Envoie requête à une URL et affiche uniquement le code de statut de la réponse
curl -s -o /dev/null -w "%{http_code}" "$1"
