#include "main.h"
#include <stddef.h>

char *_strpbrk(char *s, char *accept) {
	char *start = accept;

	while (*s) {
		while (*accept) {
			if (*s == *accept) {
				return (s);
			}
			accept++;
		}
		accept = start;
		s++;
	}
	return (NULL);
}
