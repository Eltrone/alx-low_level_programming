#!/usr/bin/python3
import unittest
import os
from models.base import Base
from models.rectangle import Rectangle

class TestBaseSaveToFileCsv(unittest.TestCase):

    @classmethod
    def setUpClass(cls):
        Base._Base__nb_objects = 0
        cls.test_file = 'Rectangle.csv'
        if os.path.exists(cls.test_file):
            os.remove(cls.test_file)

    @classmethod
    def tearDownClass(cls):
        """ Clean up after tests. """
        if os.path.exists(cls.test_file):
            os.remove(cls.test_file)

    def test_save_to_file_csv(self):
        """ Test saving objects to a CSV file. """
        r1 = Rectangle(10, 7, 2, 8)
        r2 = Rectangle(2, 4)
        Rectangle.save_to_file_csv([r1, r2])
        self.assertTrue(os.path.exists('Rectangle.csv'))

if __name__ == "__main__":
    unittest.main()
