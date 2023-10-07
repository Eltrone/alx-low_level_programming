#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/* Prototypes for existing functions */
void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* New prototypes for the 101-mul.c file */
int _putchar(char c);
int is_number(char *s);
void print_error(void);

#endif /* MAIN_H */
