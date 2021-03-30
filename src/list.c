#include "list.h"

/*
 * list_push
 */
errco_t list_push(list_node_t **start, entry_value_t entry_value) {
  list_node_t *node = NULL;

  errno = 0;

  node = (list_node_t *)malloc(sizeof(struct list_node_t));

  /* check errno for possible non-null memory address not backed by actual
   * memory (memory overcommitment) */
  if (errno == 0 && node != NULL) {
    node->value = entry_value;

    node->next = *start;

    *start = node;
  }

  else {
    perror("[Error] Memory allocation error at list_push(...) ");
    return EMF;
  }

  return EXIT_SUCCESS;
}

errco_t list_printf(list_node_t **start) {
  list_node_t *tmp = *start;

  while (tmp != NULL) {
    entry_value_output(&(tmp->value));
    tmp = tmp->next;
  }

  return EXIT_SUCCESS;
}

errco_t list_sort(list_node_t **start, field_t mode ) {
  list_node_t *low = NULL;
  list_node_t *high = NULL;

  if ((*start == NULL) || ((*start)->next == NULL)) {
    return ELSF;
  }

  _list_split(*start, &low, &high);

  list_sort(&low, mode);


  list_sort(&high, mode);


  _list_merge(low, high, start, mode);

  return EXIT_SUCCESS;
}

/*
    list_delete
*/
errco_t list_delete(list_node_t **start) {
  list_node_t *ptr = *start;

  while (ptr != NULL) {
    list_node_t *delete = ptr;
    ptr = ptr->next;
    free(delete);
  }

  return EXIT_SUCCESS;
}

// Private functions for list_sort

void _list_split(list_node_t *src, list_node_t **low, list_node_t **high) {
  list_node_t *fast = NULL;
  list_node_t *slow = NULL;

  if (src == NULL || src->next == NULL) {
    (*low) = src;
    (*high) = NULL;

    return;
  }

  slow = src;
  fast = src->next;

  while (fast != NULL) {
    fast = fast->next;

    if (fast != NULL) {
      fast = fast->next;
      slow = slow->next;
    }
  }

  (*low) = src;
  (*high) = slow->next;
  slow->next = NULL;

  return;
}

void _list_merge(list_node_t *a, list_node_t *b, list_node_t **c, field_t mode) {
  list_node_t tmp;
  bool condition;

  *c = NULL;
  if (a == NULL) {
    *c = b;
    return;
  }

  if (b == NULL) {
    *c = a;
    return;
  }

  switch (mode) {
    case first_name:
      condition = a->value.first_name[0] < b->value.first_name[0];
      break;

    case last_name:
      condition = a->value.last_name[0] < b->value.last_name[0];
      break;

    case position:
      condition = a->value.position[0] < b->value.position[0];
      break;

    default:
      return;
  }

  if (condition) {
    *c = a;
    a = a->next;
  } 
  else {
    *c = b;
    b = b->next;
  }

  tmp.next = *c;

  while (a && b) {
    if (condition) {
      (*c)->next = a;
      a = a->next;
    } 
    else {
      (*c)->next = b;
      b = b->next;
    }

    (*c) = (*c)->next;
  }

  if (a) {

    while (a) {
      (*c)->next = a;
      (*c) = (*c)->next;
      a = a->next;
    }

  }
  if (b) {

    while (b) {
      (*c)->next = b;
      (*c) = (*c)->next;
      b = b->next;
    }

  }
  *c = tmp.next;

  return;
}