#!/usr/bin/python3
class LockedClass:
    """
    Cette classe ne permet que la création d'un attribut 'first_name'.
    Toute tentative de création d'autres attributs générera une AttributeError.
    """
    __slots__ = ['first_name']
