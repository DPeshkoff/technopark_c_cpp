#pragma once

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "custom_errors.h"
#include "data.h"
#include "io.h"

#pragma pack(push, 1)
/* packing for 60 bytes (without packing we get 64 bytes) */
typedef struct list_node_t {
  struct entry_value_t value;
  struct list_node_t* next;
} list_node_t;
#pragma pack(pop)

typedef enum field_t { first_name = 0, last_name = 1, position = 2} field_t;

errco_t list_push(list_node_t** start, entry_value_t entry_value);

errco_t list_printf(list_node_t** start);

errco_t list_sort(list_node_t** start, field_t mode);

errco_t list_delete(list_node_t** start);

// Private methods for list_sort //

void _list_split(list_node_t *src, list_node_t **low, list_node_t **high);

void _list_merge(list_node_t *a, list_node_t *b, list_node_t **c, field_t mode);