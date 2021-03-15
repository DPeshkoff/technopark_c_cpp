#pragma once

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "custom_errors.h"
#include "data.h"
#include "io.h"

/* packing for 57 bytes (without packing we get 64 bytes) */
#pragma pack(push, 1)
typedef struct node_t {
  entry_t value;
  struct node_t* next;
} node_t;
#pragma pack(pop)

errco_t list_add(node_t** start, entry_t entry_value);

errco_t list_printf(node_t** start);

errco_t list_find(node_t** start, entry_t pattern);

errco_t list_delete(node_t** start);

bool check_pattern (node_t * tmp, entry_t pattern);