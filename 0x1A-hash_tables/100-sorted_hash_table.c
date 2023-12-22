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
    shash_node_t *node, *new_node, *temp;
    unsigned long int index;

    if (!ht || !key || strlen(key) == 0 || !value)
        return 0;

    // Create a new node
    new_node = malloc(sizeof(shash_node_t));
    if (!new_node)
        return 0;
    new_node->key = strdup(key);
    new_node->value = strdup(value);
    if (!new_node->key || !new_node->value) {
        free(new_node);
        return 0;
    }

    // Insert node into the hash table
    index = key_index((const unsigned char *)key, ht->size);
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    // Insert node into the sorted linked list
    if (!ht->shead || strcmp(key, ht->shead->key) <= 0) {
        new_node->sprev = NULL;
        new_node->snext = ht->shead;
        if (ht->shead)
            ht->shead->sprev = new_node;
        ht->shead = new_node;
        if (!ht->stail)
            ht->stail = new_node;
    } else {
        temp = ht->shead;
        while (temp->snext && strcmp(key, temp->snext->key) > 0)
            temp = temp->snext;
        new_node->snext = temp->snext;
        new_node->sprev = temp;
        if (temp->snext)
            temp->snext->sprev = new_node;
        temp->snext = new_node;
        if (!new_node->snext)
            ht->stail = new_node;
    }

    return 1;
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
