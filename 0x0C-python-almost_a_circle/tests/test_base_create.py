import unittest
from models.base import Base
from models.rectangle import Rectangle
from models.square import Square

class TestBaseCreate(unittest.TestCase):

    @classmethod
    def setUpClass(cls):
        Base._Base__nb_objects = 0

    def test_create_rectangle(self):
        """Test creating a Rectangle instance using create."""
        r = Rectangle(3, 5, 1)
        r_dictionary = r.to_dictionary()
        r_new = Rectangle.create(**r_dictionary)
        self.assertEqual(r_new.to_dictionary(), r_dictionary)

    def test_create_square(self):
        """Test creating a Square instance using create."""
        s = Square(5, 1, 1)
        s_dictionary = s.to_dictionary()
        s_new = Square.create(**s_dictionary)
        self.assertEqual(s_new.to_dictionary(), s_dictionary)

if __name__ == "__main__":
    unittest.main()
