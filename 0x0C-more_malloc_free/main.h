#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strlen(char *s);
void _putchar(char *str);
int error_exit(char *result);
void initialize_result(char *result, int lenr);
void multiply_numbers(char *num1, char *num2, char *result, int len1, int len2, int lenr);
void print_result(char *result, int lenr);

#endif /* MAIN_H */
