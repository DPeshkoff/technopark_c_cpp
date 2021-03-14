#include "../headers/io.h"

errco_t str_input(char **input_field) {
  char buffer[MAXLENGTH];

  if (fgets(buffer, MAXLENGTH, stdin) != NULL) {
    errno = 0;

    *input_field = (char *)malloc(sizeof(buffer));

    if (errno != 0 || *input_field == NULL) {
      free(*input_field);
      return EMF;
    }

    buffer[strlen(buffer) - 1] = '\0';

    strcpy(*input_field, buffer);
    /*
        // TODO STRCOPY_S
    */
  } else {
    return EIO;
  }

  return EXIT_SUCCESS;
}

errco_t date_input(date_t *input_field) {
  char buffer[MAXLENGTH];

  char *num_end;

  if (fgets(buffer, MAXLENGTH, stdin) != NULL) {
    if (input_field == NULL) {
      return ENOMEM;
    } else {
      int dd = strtol(buffer, &num_end, 10);

      if (dd == 0 || (dd > 0 && dd <= MAX_DAYS_MONTH)) {
        int mm = strtol(num_end, &num_end, 10);
        if (mm == 0 || (mm > 0 && mm <= MAX_MONTHS_YEAR)) {
          int yy = strtol(num_end, NULL, 10);
          if (yy == 0 || (yy > 0 && yy >= UNIX_ERA)) {
            *input_field = to_date_t(dd, mm, yy);

          } else {
            return ENCF;
          }
        } else {
          return ENCF;
        }
      } else {
        return ENCF;
      }
    }

  } else {
    return EIO;
  }

  return EXIT_SUCCESS;
}

errco_t tbool_input(tbool_t *tbool) {
  char buffer[MAXLENGTH];

  if (fgets(buffer, MAXLENGTH, stdin) != NULL) {
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

  return ESUCCESS;
}

errco_t entry_input(entry_t *new_entry) {
  errco_t err = 0;

  if (new_entry == NULL) {
    return ENE;
  }

  printf("%s\n", "Please, enter organization name: ");
  err = str_input(&(new_entry->organization));
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }

  printf("%s\n", "Please, enter type of document: ");
  err = str_input(&(new_entry->type_of_document));
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }

  printf("%s\n", "Please, enter document name: ");
  err = str_input(&(new_entry->document_name));
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }

  printf("%s\n", "Please, enter acceptance date: ");
  err = date_input(&(new_entry->accepted));
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }

  printf("%s\n", "Please, enter activation date: ");
  err = date_input(&(new_entry->active_since));
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }

  printf("%s\n", "Please, enter translation status: ");
  err = tbool_input(&(new_entry->is_translated));
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
      bytes = printf("%s", "Translation exists");
      if (bytes == 0) {
        return EIO;
      }
      break;

    case FALSE:
      bytes = printf("%s", "Translation does not exist");
      if (bytes == 0) {
        return EIO;
      }
      break;

    case NS:
      bytes = printf("%s", "Translation not specified");
      if (bytes == 0) {
        return EIO;
      }
      break;

    default:
      bytes = printf("%s", "Unknown translation status");
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