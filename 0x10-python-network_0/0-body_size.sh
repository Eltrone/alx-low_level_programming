#!/bin/bash
# envoie une requête à une URL et affiche la taille du corps de la réponse en octets
curl -s "$1" -o /dev/null -w '%{size_download}\n'

