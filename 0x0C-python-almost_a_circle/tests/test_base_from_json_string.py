#!/usr/bin/python3
import unittest
from models.base import Base

class TestBaseFromJsonString(unittest.TestCase):

    def test_from_json_string_with_empty_string(self):
        """Test conversion of empty string to list."""
        self.assertEqual(Base.from_json_string(""), [])

    def test_from_json_string_with_None(self):
        """Test conversion of None to list."""
        self.assertEqual(Base.from_json_string(None), [])

    def test_from_json_string_with_valid_string(self):
        """Test conversion of valid JSON string to list."""
        list_output = Base.from_json_string('[{"id": 89}, {"id": 90}]')
        expected = [{"id": 89}, {"id": 90}]
        self.assertEqual(list_output, expected)

if __name__ == "__main__":
    unittest.main()
