#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
* _strdup - manually duplicates a string
* @str: the string to duplicate
* Return: pointer to new string, or NULL if it fails
*/
char *_strdup(char *str)
{
	int i = 0, len = 0;
	char *newStr;

	while (str[len])
		len++;

	newStr = malloc(len + 1);
	if (newStr == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		newStr[i] = str[i];
	newStr[i] = '\0';

	return (newStr);
}

/**
* new_dog - Creates a new dog
* @name: Name of the dog
* @age: Age of the dog
* @owner: Owner of the dog
* Return: Pointer to new dog_t type, or NULL if it fails
*/
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *newDog;
	char *newName, *newOwner;

	newDog = malloc(sizeof(dog_t));
	if (newDog == NULL)
		return (NULL);

	newName = _strdup(name);
	if (newName == NULL)
	{
		free(newDog);
		return (NULL);
	}

	newOwner = _strdup(owner);
	if (newOwner == NULL)
	{
		free(newName);
		free(newDog);
		return (NULL);
	}

	newDog->name = newName;
	newDog->age = age;
	newDog->owner = newOwner;

	return (newDog);
}
