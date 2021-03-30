#include "hash.h"

errco_t hash(entry_value_t *entry, const unsigned int mod_value,
             int *hash_code) {
  int key_sum = 0;

  if (mod_value == 0) {
    return EWHB;
  }

  for (int i = 0; i < strlen(entry->position); ++i) {
    key_sum += entry->position[i];
  }

  *hash_code = key_sum % mod_value;

  return EXIT_SUCCESS;
}

errco_t hashtable_create(hashtable_t *table, unsigned int capacity) {
  if (capacity < 1) {
    return ENSG;
  }

  errno = 0;

  table->table = (entry_t **)malloc(sizeof(entry_t) * capacity);

  if (errno == 0 && table->table != NULL) {
    for (int i = 0; i < capacity; ++i) {
      table->table[i] = NULL;
    }

    table->capacity = capacity;
    table->size = 0;
  } else {
    free(table);
    perror(
        "[Error] Memory allocation error at function hashtable_create(...) ");
    return EMF;
  }

  return EXIT_SUCCESS;
}

errco_t hashtable_insert(hashtable_t *table, entry_value_t *entry_value) {
  entry_t *new_node;
  errco_t err = 0;
  int hash_code = 0;

  err = hash(entry_value, table->capacity, &hash_code);

  if (err != EXIT_SUCCESS) {
    return err;
  }

  errno = 0;

  new_node = (entry_t *)malloc(sizeof(entry_t));

  if (errno == 0 && table->table != NULL) {
    new_node->key = hash_code;

    errno = 0;
    int *dest_pointer =
        (int *)memcpy(&(new_node->value), entry_value, sizeof(entry_value_t));

    if (dest_pointer != NULL && errno == 0) {
      new_node->next = table->table[hash_code];

      table->table[hash_code] = new_node;

      ++table->size;
    } else {
      free(new_node);
      perror(
          "[Error] Memory allocation error at function hashtable_insert(...) ");
      return EMF;
    }
  } else {
    perror(
        "[Error] Memory allocation error at function hashtable_insert(...) ");
    return EMF;
  }

  return EXIT_SUCCESS;
}

errco_t hashtable_delete(hashtable_t *table) {
  entry_t *current_entry;
  entry_t *next_entry;

  if (table == NULL) {
    return EHTE;
  }

  for (int i = 0; i < table->capacity; ++i) {
    current_entry = table->table[i];
    while (current_entry) {
      next_entry = current_entry->next;

      free(current_entry->value.first_name);
      free(current_entry->value.last_name);
      free(current_entry->value.position);
      free(current_entry);

      current_entry = next_entry;
    }
  }

  free(table->table);

  return EXIT_SUCCESS;
}