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

    @classmethod
    def create(cls, **dictionary):
        """
        Creates and returns an instance with all attributes already set.

        Args:
            **dictionary (dict): A dictionary with attribute names and values.

        Returns:
            instance: class with attributes set based on the dictionary.
        """
        if cls.__name__ == "Rectangle":
            dummy_instance = cls(1, 1)
        elif cls.__name__ == "Square":
            dummy_instance = cls(1)

        dummy_instance.update(**dictionary)
        return dummy_instance

    @classmethod
    def load_from_file(cls):
        """
        Loads instances from a JSON file.

        Returns:
            list: A list of instances created from the JSON file.
        """
        filename = cls.__name__ + ".json"
        try:
            with open(filename, "r") as file:
                json_data = file.read()
                if not json_data:
                    return []
                dict_list = Base.from_json_string(json_data)
                instance_list = [cls.create(**d) for d in dict_list]
                return instance_list
        except FileNotFoundError:
            return []  # Return an empty list if the file doesn't exist

    @classmethod
    def save_to_file_csv(cls, list_objs):
        """ Serialize instances to a CSV file. """
        filename = cls.__name__ + ".csv"
        with open(filename, mode="w", encoding="utf-8") as file:
            if cls.__name__ == "Rectangle":
                fields = ["id", "width", "height", "x", "y"]
            elif cls.__name__ == "Square":
                fields = ["id", "size", "x", "y"]

            if list_objs is None:
                list_objs = []

            for obj in list_objs:
                csv_data = ",".join(str(getattr(obj, field)) for field in fields)
                file.write(csv_data + "\n")

    @classmethod
    def load_from_file_csv(cls):
        """ Deserialize instances from a CSV file. """
        filename = cls.__name__ + ".csv"
        try:
            with open(filename, mode="r", encoding="utf-8") as file:
                instance_list = []
                for line in file:
                    line = line.strip()
                    if line:
                        data = line.split(",")
                        obj_data = {field: int(data[i]) for i, field in enumerate(fields)}
                        instance = cls.create(**obj_data)
                        instance_list.append(instance)
                return instance_list
        except FileNotFoundError:
            return []  # Return an empty list if the file doesn't exist
