#include <float.h>
#include <pthread.h>
#include <sys/sysinfo.h>

#include "hash.h"

#pragma pack(push, 1)
typedef struct thread_args_t {
  int id;
  int border;
  hashtable_t *table;
  list_node_t **node;
  int out;
} thread_args_t;
#pragma pack(pop)

void *hashtable_find_local(void *args);

#define MAX_THREADS get_nprocs()

void *hashtable_find_local(void *args) {
  thread_args_t *local_args = (thread_args_t *)args;

  int lower_border = local_args->border * local_args->id;
  int upper_border = local_args->border * (local_args->id + 1);

  for (int i = lower_border; i < upper_border; ++i) {
    entry_t *current_entry = local_args->table->table[i];
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
      list_push((local_args->node), min_entry);
      list_push((local_args->node), max_entry);
    }
  }
  return local_args;
}

errco_t hashtable_find(hashtable_t *table, list_node_t **list) {
  errco_t err;
  pthread_t thread[MAX_THREADS];

  thread_args_t args[MAX_THREADS];

  int border = table->capacity / MAX_THREADS;

  for (int i = 0; i < MAX_THREADS; ++i) {
    args[i].id = i;
    args[i].border = border;
    args[i].table = table;
    args[i].node = list;
  }

  for (int i = 0; i < MAX_THREADS; ++i) {
    err = pthread_create(&thread[i], NULL, hashtable_find_local, &args[i]);
    if (err != 0) {
      return err;
    }
  }

  for (int i = 0; i < MAX_THREADS; ++i) {
    err = pthread_join(thread[i], NULL);
    if (err != 0) {
      return err;
    }
  }

  return EXIT_SUCCESS;
}