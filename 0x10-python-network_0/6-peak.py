#!/usr/bin/python3

def find_peak(list_of_integers):
    """
    Fonction qui trouve un pic dans une liste d'entiers non triés.
    Un pic est un élément qui est plus grand ou égal à ses voisins.
    """
    n = len(list_of_integers)
    # Cas de base
    if n == 0:
        return None
    if n == 1:
        return list_of_integers[0]
    if n == 2:
        return max(list_of_integers)
    
    mid = n // 2
    # Vérification si l'élément milieu est un pic
    if (mid == 0 or list_of_integers[mid] >= list_of_integers[mid - 1]) and \
       (mid == n - 1 or list_of_integers[mid] >= list_of_integers[mid + 1]):
        return list_of_integers[mid]
    # Si le pic est potentiellement à gauche
    elif mid > 0 and list_of_integers[mid - 1] > list_of_integers[mid]:
        return find_peak(list_of_integers[:mid])
    # Si le pic est potentiellement à droite
    else:
        return find_peak(list_of_integers[mid + 1:])
