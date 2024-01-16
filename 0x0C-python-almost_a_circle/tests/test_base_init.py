#!/usr/bin/python3
import unittest
from models.base import Base

class TestBaseInit(unittest.TestCase):

    @classmethod
    def setUpClass(cls):
        Base._Base__nb_objects = 0

    def test_id_auto_assignment(self):
        """Test if the ID is auto-assigned correctly."""
        b1 = Base()
        self.assertEqual(b1.id, 1)
        b2 = Base()
        self.assertEqual(b2.id, 2)

    def test_id_manual_assignment(self):
        """Test if the ID is manually assigned correctly."""
        b3 = Base(12)
        self.assertEqual(b3.id, 12)

    def test_id_mixed_assignment(self):
        """Test mixed manual and auto ID assignment."""
        b4 = Base()
        self.assertEqual(b4.id, 3)
        b5 = Base(20)
        self.assertEqual(b5.id, 20)
        b6 = Base()
        self.assertEqual(b6.id, 4)

if __name__ == "__main__":
    unittest.main()
