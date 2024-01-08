#!/usr/bin/python3
"""
Module 1-my_list.
Contient une classe MyList qui hérite de la classe list.
"""


class MyList(list):
    """
    Classe MyList qui hérite de la classe list.
    """

    def print_sorted(self):
        """
        Imprime la liste, mais triée (tri ascendant).
        """
        print(sorted(self))


if __name__ == "__main__":
    my_list = MyList()
    my_list.append(1)
    my_list.append(4)
    my_list.append(2)
    my_list.append(3)
    my_list.append(5)
    print(my_list)
    my_list.print_sorted()
    print(my_list)
