#include <float.h>

#include "hash.h"

errco_t hashtable_find(hashtable_t* table, list_node_t** list) {
  if (table == NULL) {
    return EHTN;
  }

  for (int i = 0; i < table->capacity; ++i) {
    entry_t* current_entry = table->table[i];
    bool is_not_empty = false;

    entry_value_t min_entry = {NULL, NULL, NULL, NOT_STATED, DBL_MAX, 0, 0};

    entry_value_t max_entry = {NULL, NULL, NULL, NOT_STATED, 0, 0, 0};

    while (current_entry) {
      is_not_empty = true;
      if (current_entry->value.age < min_entry.age) {
        min_entry = current_entry->value;
      }
      if (current_entry->value.age > max_entry.age) {
        max_entry = current_entry->value;
      }
      current_entry = current_entry->next;
    }
    if (is_not_empty) {
      errco_t err = 0;
      err = list_push(list, min_entry);
      if (err != EXIT_SUCCESS) {
        return err;
      }
      err = 0;
      err = list_push(list, max_entry);
      if (err != EXIT_SUCCESS) {
        return err;
      }
    }
  }

  return EXIT_SUCCESS;
}