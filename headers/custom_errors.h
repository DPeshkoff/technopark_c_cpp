#pragma once

#include <stdio.h>

#define EXIT_SUCCESS    0               // Success
#define EIO             5               // I/O Error
#define EMF             200             // ErrorMallocFailure
#define ENE             201             // ErrorNullEntry
#define ENCF            202             // ErrorNumberConversionFail
#define ENSG            203             // ErrorNoSizeGiven
#define EHTN            204             // ErrorHashTableisNull
#define ELSF            205             // ErrorListSortFail
#define EHTE            206             // ErrorHashTableEmpty
#define EWHB            207             // ErrorWrongHashBasis

typedef int errco_t;        // Error code type

errco_t errputs(errco_t err_co);