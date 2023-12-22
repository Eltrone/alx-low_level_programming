#ifndef HASH_TABLES_H
#define HASH_TABLES_H

/* Inclure les bibliothèques standard nécessaires ici */

/**
 * struct hash_node_s - Nœud d'une table de hachage
 * @key: La clé, une chaîne de caractères
 * @value: La valeur correspondant à la clé
 * @next: Un pointeur vers le prochain nœud de la liste
 */
typedef struct hash_node_s
{
     char *key;
     char *value;
     struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Structure de données pour une table de hachage
 * @size: La taille du tableau
 * @array: Un tableau de pointeurs vers les nœuds de la liste
 */
typedef struct hash_table_s
{
     unsigned long int size;
     hash_node_t **array;
} hash_table_t;

/* Prototype de la fonction hash_table_create */
hash_table_t *hash_table_create(unsigned long int size);

#endif /* HASH_TABLES_H */
