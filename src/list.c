#include "list.h"

/*
 * list_init
 */
errco_t list_add(node_t **start, entry_t entry_value) {
  node_t *node;

  errno = 0;

  node = (node_t *)malloc(sizeof(struct node_t));

  /* check errno for possible non-null memory address not backed by actual
   * memory (memory overcommitment) */
  if (errno == 0 && node != NULL) {
    node->value = entry_value;
    node->next = *start;

    *start = node;
  }

  else {
    perror("[Error] Memory allocation error at list_init(...) ");
    return EMF;
  }

  // start = node;
  return EXIT_SUCCESS;
}

errco_t list_printf(node_t **start) {
  node_t *tmp = *start;

  while (tmp != NULL) {
    pdata(&(tmp->value));
    tmp = tmp->next;
  }

  return EXIT_SUCCESS;
}

errco_t list_find(node_t **start, entry_t pattern) {
  _Bool is_found = 0;

  node_t *tmp = *start;

  while (tmp != NULL) {
    if (check_pattern(tmp, pattern)) {
      is_found = 1;
      printf("Entry found: \n");
      pdata(&(tmp->value));
    } 
    tmp = tmp->next;
  }

  if (!is_found){
    printf("No entries found.\n");
  }

  return EXIT_SUCCESS;
}

/*
    list_delete

*/
errco_t list_delete(node_t **start) {
  node_t *ptr = *start;

  while (ptr != NULL) {
    node_t *delete = ptr;
    ptr = ptr->next;
    free(delete);
  }

  return EXIT_SUCCESS;
}

bool check_pattern (node_t * tmp, entry_t pattern)
{
  if ((strlen(pattern.organization) == 0 ||
         strncmp(pattern.organization, tmp->value.organization,
                 strlen(pattern.organization)) == 0) &&
        (strlen(pattern.type_of_document) == 0 ||
         strncmp(pattern.type_of_document, tmp->value.type_of_document,
                 strlen(pattern.type_of_document)) == 0) &&
        (strlen(pattern.document_name) == 0 ||
         strncmp(pattern.document_name, tmp->value.organization,
                 strlen(pattern.document_name)) == 0) &&
        (date_t_cmp(pattern.accepted, tmp->value.accepted) == 1) &&
        (date_t_cmp(pattern.active_since, tmp->value.active_since) == 1) &&
        (pattern.is_translated == NS ||
         pattern.is_translated == tmp->value.is_translated ||
         tmp->value.is_translated == NS)) {
           return 1;
         }
         else{
           return 0;
         }
}