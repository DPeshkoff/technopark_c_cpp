#include "io.h"

errco_t str_input(char **input_field, FILE *input) {
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

errco_t gender_input(gender_t *tbool, FILE *input) {
  char buffer[MAXLENGTH];

  if (fgets(buffer, MAXLENGTH, input) != NULL) {
    if (tbool == NULL) {
      return EMF;
    }

    int sign = strtol(buffer, NULL, 10);

    switch (sign) {
      case 1:
        *tbool = FEMALE;
        break;
      case 0:
        *tbool = MALE;
        break;

      default:
        *tbool = NOT_STATED;
        break;
    }

  } else {
    return EIO;
  }

  return EXIT_SUCCESS;
}

errco_t double_input(double *input_field, FILE *input) {
  char buffer[MAXLENGTH];

  if (fgets(buffer, MAXLENGTH, input) != NULL) {
    if (input_field == NULL) {
      return ENOMEM;
    } else {
      double amount = strtod(buffer, NULL);

      if (amount >= 0) {
        *input_field = amount;
      } else {
        return ENCF;
      }
    }

  } else {
    return EIO;
  }

  return EXIT_SUCCESS;
}

errco_t entry_value_input(entry_value_t *new_entry, FILE *input, bool mode) {
  errco_t err = 0;

  if (new_entry == NULL) {
    return ENE;
  }
  if (mode != false) {
    printf("Please, enter first name: \n");
  }
  err = str_input(&(new_entry->first_name), input);
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }

  if (mode != false) {
    printf("Please, enter surname: \n");
  }

  err = str_input(&(new_entry->last_name), input);
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }

  if (mode != false) {
    printf("Please, enter position: \n");
  }

  err = str_input(&(new_entry->position), input);
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }

  if (mode != false) {
    printf("Please, enter sex: \n");
  }

  err = gender_input(&(new_entry->sex), input);
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }

  if (mode != false) {
    printf("Please, enter age: \n");
  }

  err = double_input(&(new_entry->age), input);
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }

  if (mode != false) {
    printf("Please, enter salary: \n");
  }

  err = double_input(&(new_entry->salary), input);
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }

  if (mode != false) {
    printf("Please, enter experience: \n");
  }

  err = double_input(&(new_entry->experience), input);
  if (err != EXIT_SUCCESS) {
    errputs(err);
    return err;
  }

  if (mode != false) {
    err = entry_value_output(new_entry);
    if (err != EXIT_SUCCESS) {
      errputs(err);
      return err;
    }
  }

  return EXIT_SUCCESS;
}

errco_t gender_translation(const gender_t *tbool) {
  int bytes;
  switch (*tbool) {
    case FEMALE:
      bytes = printf(" F\n");
      if (bytes == 0) {
        return EIO;
      }
      break;

    case MALE:
      bytes = printf(" M\n");
      if (bytes == 0) {
        return EIO;
      }
      break;

    case NOT_STATED:
      bytes = printf(" N\n");
      if (bytes == 0) {
        return EIO;
      }
      break;

    default:
      bytes = printf(" ?\n");
      if (bytes == 0) {
        return EIO;
      }
      break;
  }

  return EXIT_SUCCESS;
}

errco_t entry_value_output(entry_value_t *entry) {
  int bytes = 0;
  errco_t err = 0;
  bytes = printf(" %s\n %s\n %s\n", entry->first_name, entry->last_name,
                 entry->position);
  if (bytes == 0) {
    return EIO;
  }

  err = gender_translation(&(entry->sex));
  if (err != 0) {
    return err;
  }

  bytes = printf(" %.2f\n", entry->age);
  if (bytes == 0) {
    return EIO;
  }

  bytes = printf(" %.2f $\n", entry->salary);
  if (bytes == 0) {
    return EIO;
  }

  bytes = printf(" %.2f\n", entry->experience);
  if (bytes == 0) {
    return EIO;
  }

  return EXIT_SUCCESS;
}