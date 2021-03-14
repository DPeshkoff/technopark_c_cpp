#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "data.h"
#include "custom_errors.h"

#define MAXLENGTH 100

errco_t str_input (char ** input_field);

errco_t date_input (date_t * input_field);

errco_t entry_input (entry_t * new_entry);

errco_t tbool_translation (const tbool_t tbool);

errco_t pdata (entry_t * entry);