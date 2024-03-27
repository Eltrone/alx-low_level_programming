#!/bin/bash
# Script qui envoie une requête DELETE à une URL et affiche le corps de la réponse
curl -s -X DELETE "$1"
