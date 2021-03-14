#pragma once

#define EMF 200     // ErrorMallocFailure
#define ESUCCESS 0  // Success
#define ENE 201     // ErrorNullEntry
#define EIO 5       // I/O Error
#define EBE 202     // ErrorBufferisEmpty
#define ESTRCF 203  // ErrorStringCopyFailed
#define ENCF 204    // ErrorNumberConversionFail

typedef int errco_t;  // Error code type

errco_t errputs(errco_t err_co);
