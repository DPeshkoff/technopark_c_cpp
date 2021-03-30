#pragma once

#include <errno.h>
#include <string.h>

#include "custom_errors.h"
#include "data.h"

#define MAXLENGTH 150

errco_t str_input(char **input_field, FILE * input);

errco_t gender_input(gender_t *tbool, FILE * input);

errco_t double_input(double *input_field, FILE * input);

errco_t entry_value_input(entry_value_t *new_entry, FILE *input, bool mode);

errco_t gender_translation(const gender_t * tbool);

errco_t entry_value_output(entry_value_t *entry);