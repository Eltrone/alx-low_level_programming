#!/usr/bin/python3
"""Module pour la classe Base."""


class Base:
    """Classe de base pour d'autres classes dans le projet.

    Attributs:
        __nb_objects (int): Compteur d'objets pour attribuer des ID automatiques.

    Args:
        id (int): L'identifiant de l'instance.
    """

    __nb_objects = 0

    def __init__(self, id=None):
        """Initialise une nouvelle instance de Base.

        Args:
            id (int): L'identifiant de l'instance. Si None, un ID est attribué automatiquement.
        """
        if id is not None:
            self.id = id
        else:
            Base.__nb_objects += 1
            self.id = Base.__nb_objects
