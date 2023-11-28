#!/usr/bin/python3
toggle_case = 0
for ascii_val in range(ord('z'), ord('a') - 1, -1):
    char_to_print = chr(ascii_val - toggle_case)
    print("{}".format(char_to_print), end="")
    toggle_case = 0 if toggle_case else 32
