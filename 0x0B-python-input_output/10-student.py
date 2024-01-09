#!/usr/bin/python3
"""Module définissant la classe Student avec filtration des attributs."""


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
            attrs (list): Liste attributs à inclure dans le dictionnaire.

        Returns:
            dict: Un dictionnaire avec attributs spécifiés de l'étudiant.
        """
        if attrs is not None and all(isinstance(attr, str) for attr in attrs):
            return {
                attr: getattr(self, attr)
                for attr in attrs if hasattr(self, attr)
            }
        return self.__dict__
