#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

shash_table_t *shash_table_create(unsigned long int size) {
    shash_table_t *ht = malloc(sizeof(shash_table_t));
    if (!ht)
        return (NULL);

    ht->size = size;
    ht->array = calloc(size, sizeof(shash_node_t *));
    if (!ht->array) {
        free(ht);
        return (NULL);
    }

    ht->shead = NULL;
    ht->stail = NULL;
    return ht;
}

int shash_table_set(shash_table_t *ht, const char *key, const char *value) {
    if (!ht || !key || strlen(key) == 0 || !value)
        return 0;

    // ... (Ajouter la logique pour insérer le nœud dans la table et dans la liste triée)
    return 1; // Placeholder, doit être ajusté selon la logique d'insertion
}

char *shash_table_get(const shash_table_t *ht, const char *key) {
    unsigned long int index;
    shash_node_t *node;

    if (!ht || !key)
        return NULL;

    index = key_index((const unsigned char *)key, ht->size);
    node = ht->array[index];
    while (node) {
        if (strcmp(node->key, key) == 0)
            return node->value;
        node = node->next;
    }

    return NULL;
}

void shash_table_print(const shash_table_t *ht) {
    shash_node_t *node;
    int comma = 0;

    if (!ht)
        return;

    printf("{");
    for (node = ht->shead; node != NULL; node = node->snext) {
        if (comma)
            printf(", ");
        printf("'%s': '%s'", node->key, node->value);
        comma = 1;
    }
    printf("}\n");
}

void shash_table_print_rev(const shash_table_t *ht) {
    shash_node_t *node;
    int comma = 0;

    if (!ht)
        return;

    printf("{");
    for (node = ht->stail; node != NULL; node = node->sprev) {
        if (comma)
            printf(", ");
        printf("'%s': '%s'", node->key, node->value);
        comma = 1;
    }
    printf("}\n");
}

void shash_table_delete(shash_table_t *ht) {
    shash_node_t *node, *tmp;
    unsigned long int i;

    if (!ht)
        return;

    for (i = 0; i < ht->size; i++) {
        node = ht->array[i];
        while (node) {
            tmp = node->next;
            free(node->key);
            free(node->value);
            free(node);
            node = tmp;
        }
    }

    free(ht->array);
    free(ht);
}
