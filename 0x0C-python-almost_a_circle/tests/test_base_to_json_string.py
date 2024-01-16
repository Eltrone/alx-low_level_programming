#!/usr/bin/python3
import unittest
from models.base import Base

class TestBaseToJsonString(unittest.TestCase):

    def test_to_json_string_with_empty_list(self):
        """Test conversion of empty list to JSON string."""
        self.assertEqual(Base.to_json_string([]), "[]")

    def test_to_json_string_with_None(self):
        """Test conversion of None to JSON string."""
        self.assertEqual(Base.to_json_string(None), "[]")

    def test_to_json_string_with_dictionaries(self):
        """Test conversion of list of dictionaries to JSON string."""
        list_dicts = [{"id": 12}, {"id": 34}]
        json_str = Base.to_json_string(list_dicts)
        self.assertEqual(json_str, '[{"id": 12}, {"id": 34}]')

if __name__ == "__main__":
    unittest.main()
