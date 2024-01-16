#!/usr/bin/python3
import unittest
import os
from models.base import Base
from models.rectangle import Rectangle

class TestBaseLoadFromFileCsv(unittest.TestCase):

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

    def test_load_from_file_csv_no_file(self):
        """ Test loading from a CSV file that doesn't exist. """
        self.assertEqual(Rectangle.load_from_file_csv(), [])

    def test_load_from_file_csv_with_file(self):
        """ Test loading from an existing CSV file. """
        r1 = Rectangle(10, 7, 2, 8)
        r2 = Rectangle(2, 4)
        Rectangle.save_to_file_csv([r1, r2])
        list_rectangles = Rectangle.load_from_file_csv()
        self.assertTrue(len(list_rectangles) == 2)

if __name__ == "__main__":
    unittest.main()
