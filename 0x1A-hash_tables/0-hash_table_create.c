#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_create - Crée une nouvelle table de hachage
 * @size: La taille du tableau de la table de hachage
 *
 * Return: Un pointeur vers la nouvelle table de hachage, ou NULL en cas d'échec
 */
hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *hash_table;
    unsigned long int i;

    /* Allocation de mémoire pour la structure de la table de hachage */
    hash_table = malloc(sizeof(hash_table_t));
    if (hash_table == NULL)
        return (NULL);

    /* Initialisation de la table */
    hash_table->size = size;
    hash_table->array = malloc(sizeof(hash_node_t *) * size);
    if (hash_table->array == NULL)
    {
        free(hash_table);
        return (NULL);
    }

    /* Initialisation des pointeurs de nœuds à NULL */
    for (i = 0; i < size; i++)
        hash_table->array[i] = NULL;

    return (hash_table);
}
