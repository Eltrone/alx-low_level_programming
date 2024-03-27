#!/bin/bash
# envoie une requête à une URL et affiche la taille du corps de la réponse en octets
curl -s -v "$1" -o response_body.txt -w '%{size_download}\n'
