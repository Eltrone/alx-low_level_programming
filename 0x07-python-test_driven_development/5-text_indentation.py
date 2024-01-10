#!/usr/bin/python3

def text_indentation(text):
    """
    Print a text with 2 new lines after each '.', '?' and ':'.

    Args:
    text (str): The text to be indented.

    Raises:
    TypeError: If text is not a string.
    """
    if not isinstance(text, str):
        raise TypeError("text must be a string")

    i = 0
    while i < len(text):
        print(text[i], end="")
        if text[i] in ".?:":
            print("\n\n", end="")
            while i + 1 < len(text) and text[i + 1] == ' ':
                i += 1
        i += 1

# Exemple d'utilisation
if __name__ == "__main__":
    text = ("Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
            "Quonam modo? Utrum igitur tibi litteram videor an totas paginas commovere? "
            "Non autem hoc: igitur ne illud quidem. Fortasse id optimum, sed ubi illud: "
            "Plus semper voluptatis? Teneo, inquit, finem illi videri nihil dolere. "
            "Transfer idem ad modestiam vel temperantiam, quae est moderatio cupiditatum "
            "rationi oboediens. Si id dicis, vicimus. Inde sermone vario sex illa a Dipylo "
            "stadia confecimus. Sin aliud quid voles, postea. Quae animi affectio suum "
            "cuique tribuens atque
