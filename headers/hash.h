#pragma once

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "custom_errors.h"
#include "data.h"
#include "list.h"


/* pragma pack not needed - 16 bytes with packing and 16 bytes without */
typedef struct hashtable_t {
  int size;
  int capacity;
  struct entry_t** table;
} hashtable_t;


errco_t hash (entry_value_t * entry, const unsigned int mod_value, int * hash_code);

errco_t hashtable_create (hashtable_t * table, unsigned int capacity);

errco_t hashtable_insert (hashtable_t * table, entry_value_t * entry_value);

errco_t hashtable_delete (hashtable_t * table);

errco_t hashtable_find (hashtable_t * table, list_node_t ** list);