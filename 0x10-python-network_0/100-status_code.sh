#!/bin/bash
# Script qui envoie une requête à une URL et affiche uniquement le code de statut de la réponse
curl -so /dev/null -w "%{http_code}" "$1"
