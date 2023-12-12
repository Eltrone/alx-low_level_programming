#include "main.h"

char *_strstr(char *haystack, char *needle) {
	char *start = needle;

	if (!*needle) {
		return (haystack);
	}

	while (*haystack) {
		if (*haystack == *needle) {
			while (*needle) {
				if (*haystack != *needle) {
					break;
				}
				haystack++;
				needle++;
			}
			if (!*needle) {
				return (haystack - (needle - start));
			}
			needle = start;
		}
		haystack++;
	}
	return (NULL);
}
