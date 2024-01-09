#!/usr/bin/python3
"""Module définissant la classe Student avec mise à jour depuis un JSON."""


class Student:
    """Classe représentant un étudiant."""

    def __init__(self, first_name, last_name, age):
        """Initialise une nouvelle instance de Student."""
        self.first_name = first_name
        self.last_name = last_name
        self.age = age

    def to_json(self, attrs=None):
        """Renvoie une représentation dictionnaire de l'instance.

        Args:
            attrs (list): Attributs à inclure dans le dictionnaire.

        Returns:
            dict: Dictionnaire des attributs spécifiés.
        """
        if attrs is not None and all(isinstance(attr, str) for attr in attrs):
            return {
                attr: getattr(self, attr)
                for attr in attrs if hasattr(self, attr)
            }
        return self.__dict__

    def reload_from_json(self, json):
        """Met à jour les attributs à partir d'un dictionnaire.

        Args:
            json (dict): Dictionnaire des nouveaux attributs.
        """
        for key, value in json.items():
            if hasattr(self, key):
                setattr(self, key, value)
