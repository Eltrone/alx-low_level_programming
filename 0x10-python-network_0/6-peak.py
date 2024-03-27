#!/usr/bin/python3

def find_peak(list_of_integers):
    """
    Find a peak in a list of unsorted integers
    Trouve un pic dans une liste d'entiers non triés
    """
    # Vérifie si la liste est vide
    if not list_of_integers:
        return None

    length = len(list_of_integers)
    
    # Si la liste contient un seul élément, retourne cet élément
    if length == 1:
        return list_of_integers[0]
    
    # Si la liste contient deux éléments, retourne le maximum
    if length == 2:
        return max(list_of_integers)

    # Trouve l'indice médian de la liste
    mid_index = length // 2
    mid_value = list_of_integers[mid_index]

    # Vérifie si l'élément au milieu est un pic
    if mid_value > list_of_integers[mid_index - 1] and mid_value > list_of_integers[mid_index + 1]:
        return mid_value
    # Si l'élément à gauche est plus grand, recherche dans la partie gauche
    elif mid_value < list_of_integers[mid_index - 1]:
        return find_peak(list_of_integers[:mid_index])
    # Sinon, recherche dans la partie droite
    else:
        return find_peak(list_of_integers[mid_index + 1:])
