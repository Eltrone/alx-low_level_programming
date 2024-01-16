#!/usr/bin/python3
import unittest
import os
from models.base import Base
from models.rectangle import Rectangle

class TestBaseLoadFromFile(unittest.TestCase):

    @classmethod
    def setUpClass(cls):
        Base._Base__nb_objects = 0
        cls.test_file = 'Rectangle.json'
        if os.path.exists(cls.test_file):
            os.remove(cls.test_file)

    @classmethod
    def tearDownClass(cls):
        """ Clean up after tests. """
        if os.path.exists(cls.test_file):
            os.remove(cls.test_file)

    def test_load_from_file_no_file(self):
        """ Test loading from a file that doesn't exist. """
        self.assertEqual(Rectangle.load_from_file(), [])

    def test_load_from_file_with_file(self):
        """ Test loading from an existing file. """
        r1 = Rectangle(10, 7, 2, 8)
        r2 = Rectangle(2, 4)
        Rectangle.save_to_file([r1, r2])
        list_rectangles = Rectangle.load_from_file()
        self.assertTrue(len(list_rectangles) == 2)

if __name__ == "__main__":
    unittest.main()
