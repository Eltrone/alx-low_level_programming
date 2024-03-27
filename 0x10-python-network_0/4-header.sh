#!/bin/bash
# envoie une requête GET à une URL et inclut un en-tête personnalisé
curl -s -H "X-School-User-Id: 98" "$1"
