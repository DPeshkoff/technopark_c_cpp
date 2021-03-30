#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "custom_errors.h"

/* 4 bytes */
typedef enum gender_t { FEMALE = 1, MALE = 0, NOT_STATED = -1 } gender_t;

#pragma pack(push, 1)
/* packing for 52 bytes (without packing we get 56 bytes) */
typedef struct entry_value_t {
  char* first_name;
  char* last_name;
  char* position;  
  gender_t sex;
  double age;
  double salary;
  double experience;
} entry_value_t;

/* packing for 72 bytes (without packing we get 80 bytes) */
typedef struct entry_t {
  int key;
  struct entry_value_t value;
  size_t value_size;
  struct entry_t* next;
} entry_t;
#pragma pack(pop)


