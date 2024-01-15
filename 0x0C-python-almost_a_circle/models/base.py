#!/usr/bin/python3
""" Module base.py: Defines the Base class for all models. """


class Base:
    """
    Base class for all other classes in the project.
    This class manages the id attribute for all future classes and
    avoids duplicating the same code (and by extension, the same bugs).
    """

    __nb_objects = 0  # Private class attribute to count number of instances

    def __init__(self, id=None):
        """
        Initializes the Base instance.

        Args:
            id (int, optional): The instance id. If None auto-generated
            id is assigned using the private __nb_objects attribute.
        """
        if id is not None:
            self.id = id
        else:
            Base.__nb_objects += 1
            self.id = Base.__nb_objects

    @staticmethod
    def to_json_string(list_dictionaries):
        """
        Returns the JSON string representation of list_dictionaries.

        Args:
            list_dictionaries (list): A list of dictionaries.

        Returns:
            str: The JSON string representation of list_dictionaries.
        """
        import json

        if list_dictionaries is None or len(list_dictionaries) == 0:
            return "[]"

        return json.dumps(list_dictionaries)

    @classmethod
    def save_to_file(cls, list_objs):
        """
        Writes the JSON string representation of list_objs to a file.

        Args:
            list_objs (list): A list of instances that inherit from Base.

        """
        import json

        if list_objs is None:
            list_objs = []

        filename = cls.__name__ + ".json"
        json_list = [obj.to_dictionary() for obj in list_objs]

        with open(filename, mode="w", encoding="utf-8") as file:
            file.write(cls.to_json_string(json_list))

    @staticmethod
    def from_json_string(json_string):
        """
        Returns the list of dictionaries represented by the JSON string.

        Args:
            json_string (str): A JSON string = a list of dictionaries.

        Returns:
            list: The list represented by the JSON string.
        """
        import json

        if json_string is None or len(json_string) == 0:
            return []

        return json.loads(json_string)
