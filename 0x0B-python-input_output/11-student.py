#!/usr/bin/python3
"""Module définissant la classe Student avec mise à jour depuis un JSON."""


class Student:
    """Classe représentant un étudiant."""

    def __init__(self, first_name, last_name, age):
        """Initialise une nouvelle instance de la classe Student.

        Args:
            first_name (str): Le prénom de l'étudiant.
            last_name (str): Le nom de famille de l'étudiant.
            age (int): L'âge de l'étudiant.
        """
        self.first_name = first_name
        self.last_name = last_name
        self.age = age

    def to_json(self, attrs=None):
        """Renvoie une représentation dictionnaire de l'instance Student.

        Args:
            attrs (list): Liste des attributs à inclure dans le dictionnaire.

        Returns:
            dict: Un dictionnaire contenant les attributs spécifiés de l'étudiant.
        """
        if attrs is not None and all(isinstance(attr, str) for attr in attrs):
            return {attr: getattr(self, attr) for attr in attrs if hasattr(self, attr)}
        return self.__dict__

    def reload_from_json(self, json):
        """Met à jour les attributs de l'instance à partir d'un dictionnaire.

        Args:
            json (dict): Un dictionnaire contenant les nouveaux attributs.
        """
        for key, value in json.items():
            if hasattr(self, key):
                setattr(self, key, value)
