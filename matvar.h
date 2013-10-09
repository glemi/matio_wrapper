#ifndef MATVAR_H
#define MATVAR_H

#include <QVector>
#include <QString>
#include <QList>

#include "matio.h"


class MatVar;
typedef QList<MatVar> MatVars;

class MatVar
{
public:
    MatVar();
    MatVar(matvar_t* matvar);
    virtual ~MatVar();

    QString getName() const;

    matio_types   getDataType() const;
    matio_classes getClassType() const;

    bool isComplex() const;
    bool isGlobal() const;
    bool isLogical() const;

    int getRank() const;
    int getBytesSize() const;

    const QVector<double> getDoubleArrayData() const;
    double getDoubleScalarData();

private:
    matvar_t* matvarData;
};


//typedef struct matvar_t {
//    size_t nbytes;                        /**< Number of bytes for the MAT variable */
//    int    rank;                          /**< Rank (Number of dimensions) of the data */
//    enum matio_types   data_type;         /**< Data type(MAT_T_*) */
//    int   data_size;                      /**< Bytes / element for the data */
//    enum matio_classes class_type;        /**< Class type in Matlab(MAT_C_DOUBLE, etc) */
//    int   isComplex;                      /**< non-zero if the data is complex, 0 if real */
//    int   isGlobal;                       /**< non-zero if the variable is global */
//    int   isLogical;                      /**< non-zero if the variable is logical */
//    size_t *dims;                         /**< Array of lengths for each dimension */
//    char *name;                           /**< Name of the variable */
//    void *data;                           /**< Pointer to the data */
//    int   mem_conserve;                   /**< 1 if Memory was conserved with data */
//    enum matio_compression  compression;  /**< Variable compression type */
//    struct matvar_internal *internal;     /**< matio internal data */
//} matvar_t;




#endif // MATVAR_H
