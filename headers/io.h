#pragma once

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "custom_errors.h"
#include "data.h"

#define MAXLENGTH 100

errco_t str_input(char** input_field, FILE * input);

errco_t date_input(date_t* input_field, FILE * input);

errco_t entry_input(entry_t* new_entry, FILE *input_0, FILE *input_1, FILE *input_2, FILE *input_3, FILE *input_4, FILE *input_5);

errco_t tbool_input(tbool_t *tbool, FILE * input);

errco_t tbool_translation(const tbool_t tbool);

errco_t pdata(entry_t* entry);