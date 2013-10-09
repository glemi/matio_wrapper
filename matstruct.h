#ifndef MATSTRUCT_H
#define MATSTRUCT_H

#include "matvar.h"

class MatStruct : public MatVar
{
public:
    MatStruct(matvar_t* matvar);

    MatVars fields();

private:
    MatVars mFields;

};

#endif // MATSTRUCT_H
