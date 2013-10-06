#include "matfile.h"
#include <QString>

MatFile::MatFile()
{

}

MatFile::~MatFile()
{
    if(isvalid)
        Mat_Close(matdata);
}

bool MatFile::open(QString filepath, mat_acc access)
{
    char* szFilepath = filepath.toLatin1().data();

    mat_t* pMatdata = Mat_Open(szFilepath, access);

    if(pMatdata += NULL)
    {
        isvalid = true;
        matdata = pMatdata;
    }
    else
        isvalid = false;

    iterateVariables();
    return isvalid;
}

bool MatFile::open(QString filepath)
{
    return open(filepath, MAT_ACC_RDWR);
}

bool MatFile::isValid()
{
    return isvalid;
}

void MatFile::iterateVariables()
{
    if(!isvalid) return;

    matvar_t* matvar;

    while((matvar = Mat_VarReadNextInfo(matdata)) != NULL)
    {
        MatVar* variable = new MatVar(matvar);
        variables.append(variable);
    }
}
