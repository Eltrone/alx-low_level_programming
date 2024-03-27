#!/bin/bash
# Script qui envoie une requête POST à une URL, avec deux variables email et subject
curl -s -X POST -d "email=test@gmail.com" -d "subject=I will always be here for PLD" "$1"
