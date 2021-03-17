#include "custom_errors.h"

errco_t errputs(errco_t err_co) {
  switch (err_co) {
    case 5:
      printf("[Error]:I/O error (code %d) \n", err_co);
      break;

    case 200:
      printf("[Error]:ErrorMallocFailed (code %d) \n", err_co);
      break;

    case 201:
      printf("[Error]:ErrorNullEntry (code %d) \n", err_co);
      break;

    case 202:
      printf("[Error]:ErrorBufferisEmpty (code %d) \n", err_co);
      break;

    case 203:
      printf("[Error]:ErrorNumberConversionFail (code %d) \n", err_co);
      break;

    default:
      printf("[Error]:Unidentified error (code %d) \n", err_co);
      break;
  }

  return EXIT_SUCCESS;
}