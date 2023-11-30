#!/usr/bin/python3
import sys

def print_args():
    argc = len(sys.argv) - 1  # Définition de argc dans la fonction

    if argc == 0:
        print("0 arguments.")
    elif argc == 1:
        print("1 argument:")
    else:
        print("{} arguments:".format(argc))

    for i in range(1, argc + 1):
        print("{}: {}".format(i, sys.argv[i]))

if __name__ == "__main__":
    print_args()
