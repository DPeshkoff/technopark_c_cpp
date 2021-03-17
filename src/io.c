#include "io.h"

errco_t str_input(char **input_field, FILE * input) {
  char buffer[MAXLENGTH];

  if (fgets(buffer, MAXLENGTH, input) != NULL) {
    errno = 0;

    *input_field = (char *)malloc(sizeof(buffer));

    if (errno != 0 || *input_field == NULL) {
      free(*input_field);
      return EMF;
    }

    buffer[strlen(buffer) - 1] = '\0';

    strcpy(*input_field, buffer);
  } else {
    return EIO;
  }

  return EXIT_SUCCESS;
}

errco_t date_input(date_t *input_field, FILE * input) {
  char buffer[MAXLENGTH];

  char *num_end;

  if (fgets(buffer, MAXLENGTH, input) != NULL) {
    if (input_field == NULL) {
      return ENOMEM;
    } else {
      int dd = strtol(buffer, &num_end, 10);
      int mm = strtol(num_end, &num_end, 10);
      int yy = strtol(num_end, NULL, 10);

      if (check_date(&dd, &mm, &yy)) {
            *input_field = to_date_t(dd, mm, yy);

        } else {
            return ENCF;
        }
    }

  } else {
    return EIO;
  }

  return EXIT_SUCCESS;
}

errco_t tbool_input(tbool_t *tbool, FILE * input) {
  char buffer[MAXLENGTH];

  if (fgets(buffer, MAXLENGTH, input) != NULL) {
    if (tbool == NULL) {
      return EMF;
    }

    int sign = strtol(buffer, NULL, 10);

    switch (sign) {
      case 1:
        *tbool = TRUE;
        break;
      case -1:
        *tbool = FALSE;
        break;

      default:
        *tbool = NS;
        break;
    }

  } else {
    return EIO;
  }

  return EXIT_SUCCESS;
}

errco_t entry_input(entry_t *new_entry, FILE *input_0) {
  errco_t err = 0;

  if (new_entry == NULL) {
    return ENE;
  }

  printf("Please, enter organization name: \n");
  err = str_input(&(new_entry->organization), input_0);
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }

  printf("Please, enter type of document: \n");
  err = str_input(&(new_entry->type_of_document), input_0);
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }

  printf("Please, enter document name: \n");
  err = str_input(&(new_entry->document_name), input_0);
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }

  printf("Please, enter acceptance date: \n");
  err = date_input(&(new_entry->accepted), input_0);
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }

  printf("Please, enter activation date: \n");
  err = date_input(&(new_entry->active_since), input_0);
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }

  printf("Please, enter translation status: \n");
  err = tbool_input(&(new_entry->is_translated), input_0);
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }

  pdata(new_entry);

  return EXIT_SUCCESS;
}

errco_t tbool_translation(const tbool_t tbool) {
  int bytes;
  switch (tbool) {
    case TRUE:
      bytes = printf("Translation exists");
      if (bytes == 0) {
        return EIO;
      }
      break;

    case FALSE:
      bytes = printf("Translation does not exist");
      if (bytes == 0) {
        return EIO;
      }
      break;

    case NS:
      bytes = printf("Translation not specified");
      if (bytes == 0) {
        return EIO;
      }
      break;

    default:
      bytes = printf("Unknown translation status");
      if (bytes == 0) {
        return EIO;
      }
      break;
  }

  return EXIT_SUCCESS;
}

errco_t pdata(entry_t *entry) {
  int bytes;
  bytes =
      printf(" %s\n %s, %s\n %d.%d.%d\n %d.%d.%d\n ", entry->organization,
             entry->type_of_document, entry->document_name, entry->accepted.dd,
             entry->accepted.mm, entry->accepted.yy, entry->active_since.dd,
             entry->active_since.mm, entry->active_since.yy);
  if (bytes == 0)
    return EIO;
  else {
    tbool_translation((entry->is_translated));
    bytes = printf("\n \n");
    if (bytes == 0) return EIO;
  }
  return EXIT_SUCCESS;
}

bool check_date (int * dd, int * mm, int * yy)
{
  if ((*dd == 0 || (*dd > 0 && *dd <= MAX_DAYS_MONTH)) &&
      (*mm == 0 || (*mm > 0 && *mm <= MAX_MONTHS_YEAR)) &&
      (*yy == 0 || (*yy > 0 && *yy >= MIN_YEAR))) {
           return 1;
         }
         else{
           return 0;
         }
}