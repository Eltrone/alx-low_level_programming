#!/usr/bin/python3


def find_peak(list_of_integers):
    """
    Fonction qui trouve un pic dans une liste d'entiers non triés.
    Un pic est un élément plus grand ou égal à ses voisins.
    """
    if not list_of_integers:
        return None

    low = 0
    high = len(list_of_integers) - 1

    while low <= high:
        mid = (low + high) // 2
        if (mid == 0 or list_of_integers[mid - 1] <= list_of_integers[mid]) and \
           (mid == len(list_of_integers) - 1 or list_of_integers[mid + 1] <= list_of_integers[mid]):
            return list_of_integers[mid]
        elif mid > 0 and list_of_integers[mid - 1] > list_of_integers[mid]:
            high = mid - 1
        else:
            low = mid + 1

    return None
