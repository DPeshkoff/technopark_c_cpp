#pragma once


#include <stdio.h>

#define EXIT_SUCCESS 0       // Success
#define EIO 5       // I/O Error
#define EMF 200     // ErrorMallocFailure
#define ENE 201     // ErrorNullEntry
#define EBE 202     // ErrorBufferisEmpty
#define ENCF 203    // ErrorNumberConversionFail

typedef int errco_t;  // Error code type

errco_t errputs(errco_t err_co);
