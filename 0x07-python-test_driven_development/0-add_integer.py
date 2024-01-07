#!/usr/bin/python3
def add_integer(a, b=98):
    """
    Ajoute deux nombres entiers ou flottants.

    Si a ou b est un flottant, il est converti en entier avant l'addition.
    Si a ou b n'est pas un entier ou un flottant, une exception TypeError
    est levée.

    Args:
    a (int ou float): Le premier nombre à additionner.
    b (int ou float, optional): Le deuxième nombre à additionner.
                                Par défaut à 98.

    Returns:
    int: La somme de a et b.

    Raises:
    TypeError: Si a ou b n'est pas un entier ou un flottant.
    """
    if not isinstance(a, (int, float)):
        raise TypeError("a must be an integer")
    if not isinstance(b, (int, float)):
        raise TypeError("b must be an integer")
    return int(a) + int(b)
