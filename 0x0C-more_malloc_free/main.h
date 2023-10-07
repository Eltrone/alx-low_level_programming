#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>

/* Prototypes for previous tasks */
void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* Prototypes for 101-mul.c */
int _putchar(char c);
int is_number(char *s);
void multiply(char *num1, char *num2);

#endif /* MAIN_H */
