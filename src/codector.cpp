#include <stdlib.h>
#include <assert.h>
#include "codector.h"
#include "VM.h"

Code *CodeCtor(Code *codearr, size_t code_size) {
    assert(codearr);

    codearr->size = code_size;
    codearr->code = (unsigned char *)calloc(code_size, sizeof(double));

    if (!codearr->code) return NULL;

    return codearr;
}

void CodeDtor(Code *codearr) {
    CODE_ASSERT(codearr);

    free(codearr->code);
    codearr->code = NULL;
    codearr->size = 0;
}

Code *CodeRealloc(Code *codearr, size_t coeff) {
    CODE_ASSERT(codearr);

    unsigned char *newcode = (unsigned char *)realloc(codearr->code, codearr->size * coeff);

    if (!newcode) return NULL;

    codearr->code = newcode;
    codearr->size *= coeff;

    return codearr;
}
