#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int f1(int len) {
    return ((len ^ 0x3b) & 0x3f);
}

int f2(const char* str, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += str[i];
    }
    return ((sum ^ 0x4f) & 0x3f);
}

int f3(const char* str, int len) {
    int product = 1;
    for (int i = 0; i < len; i++) {
        product *= str[i];
    }
    return ((product ^ 0x55) & 0x3f);
}

int f4(const char* str, int len) {
    int max_val = str[0];
    for (int i = 0; i < len; i++) {
        if (str[i] > max_val) {
            max_val = str[i];
        }
    }
    srand((max_val ^ 0xe));
    return (rand() & 0x3f);
}

int f5(const char* str, int len) {
    int squares_sum = 0;
    for (int i = 0; i < len; i++) {
        squares_sum += str[i] * str[i];
    }
    return ((squares_sum ^ 0xef) & 0x3f);
}

int f6(char first_char) {
    int random_sum = 0;
    for (int i = 0; i < first_char; i++) {
        random_sum += rand();
    }
    return ((random_sum ^ 0xe5) & 0x3f);
}

int main(int argc, char** argv) {
    const char *key = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
    const char *input_str = argv[1];
    int str_len = strlen(input_str);
    char code[6];

    code[0] = key[f1(str_len)];
    code[1] = key[f2(input_str, str_len)];
    code[2] = key[f3(input_str, str_len)];
    code[3] = key[f4(input_str, str_len)];
    code[4] = key[f5(input_str, str_len)];
    code[5] = key[f6(input_str[0])];

    printf("%s\n", code);

    return 0;
}

