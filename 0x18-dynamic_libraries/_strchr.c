#include "main.h"
#include <stddef.h>

char *_strchr(char *s, char c) {
	for (; *s != '\0'; s++) {
		if (*s == c) {
			return (s);
		}
	}
	return (c == '\0' ? s : NULL);
}
