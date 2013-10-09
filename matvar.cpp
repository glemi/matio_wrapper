#include "matvar.h"

MatVar::MatVar()
    : matvarData(NULL) {}

MatVar::MatVar(matvar_t *matvar)
    : matvarData(matvar) {}

MatVar::~MatVar()
{
    if(matvarData != NULL)
        Mat_VarFree(matvarData);
}

QString MatVar::getName() const
{
    return QString(matvarData->name);
}

const QVector<double> MatVar::getDoubleArrayData() const
{
    const QVector<double> vector;
    return vector;
}
