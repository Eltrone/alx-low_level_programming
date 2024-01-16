#!/usr/bin/python3
import unittest
import os
from models.base import Base
from models.rectangle import Rectangle

class TestBaseSaveToFile(unittest.TestCase):

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

    def test_save_to_file_with_empty_list(self):
        """ Test saving an empty list to a file. """
        Base.save_to_file([])
        self.assertTrue(os.path.exists('Rectangle.json'))

    def test_save_to_file_with_None(self):
        """ Test saving None to a file. """
        Base.save_to_file(None)
        self.assertTrue(os.path.exists('Rectangle.json'))

    def test_save_to_file_with_objects(self):
        """ Test saving list of objects to a file. """
        r1 = Rectangle(10, 7, 2, 8)
        r2 = Rectangle(2, 4)
        Base.save_to_file([r1, r2])
        self.assertTrue(os.path.exists('Rectangle.json'))

if __name__ == "__main__":
    unittest.main()
