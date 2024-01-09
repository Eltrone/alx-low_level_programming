#!/usr/bin/python3
"""Module définissant la classe Student."""


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

    def to_json(self):
        """Renvoie une représentation dictionnaire de l'instance Student.

        Returns:
            dict: Un dictionnaire contenant attributs de l'étudiant.
        """
        return self.__dict__
