#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "custom_errors.h"

/* 4 bytes x 3 == 12 bytes */
typedef struct date_t {
  int dd;
  int mm;
  int yy;
} date_t;

/* 4 bytes */
typedef enum tbool_t { TRUE = 1, FALSE = 0, NS = -1 } tbool_t;

/* packing for 49 bytes (without packing we get 56 bytes) */
#pragma pack(push, 1)
typedef struct entry_t {
  char* organization;
  char* type_of_document;
  char* document_name;
  date_t accepted;
  date_t active_since;
  tbool_t is_translated;
} entry_t;
#pragma pack(pop)

#define MAX_DAYS_MONTH 31
#define MAX_MONTHS_YEAR 12
#define MIN_YEAR 1

date_t to_date_t(const int dd, const int mm, const int yy);

bool date_t_cmp(const date_t date1, const date_t date2);


