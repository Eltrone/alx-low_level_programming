#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* new_dog - Creates a new dog
* @name: Name of the dog
* @age: Age of the dog
* @owner: Owner of the dog
*
* Return: Pointer to new dog_t type, or NULL if it fails
*/
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *newDog;
	char *newName, *newOwner;

	newDog = malloc(sizeof(dog_t));
	if (newDog == NULL)
		return (NULL);

	newName = strdup(name);
	if (newName == NULL)
	{
		free(newDog);
		return (NULL);
	}

	newOwner = strdup(owner);
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
