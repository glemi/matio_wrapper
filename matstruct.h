#ifndef MATSTRUCT_H
#define MATSTRUCT_H

#include "matvar.h"

class MatStruct
{
public:
    MatStruct(matvar_t* matvar);

    MatVars fields();

    const MatVars fields() const;

private:
    MatVars mFields;

};

#endif // MATSTRUCT_H
