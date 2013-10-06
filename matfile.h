#ifndef MATFILE_H
#define MATFILE_H

#include "matio.h"
#include "matio_private.h"
#include "matvar.h"
#include <QList>

class MatFile
{
public:
    MatFile();
    ~MatFile();

    bool open(QString filepath, mat_acc access);
    bool open(QString filepath);
    bool isValid();

    QString getHeaderString() const;
    QString getFileName() const;
    int getVersion() const;
    mat_acc getAccessType() const;

    int getDatasetCount() const;

private:
    mat_t* matdata = NULL;
    //mat_t* const pMatdata = &matdata;

    QList<MatVar*> variables;

    bool isvalid = false;

    void iterateVariables();

};


//struct _mat_t {
//    void *fp;               /**< File pointer for the MAT file */
//    char *header;           /**< MAT File header string */
//    char *subsys_offset;    /**< offset */
//    char *filename;         /**< Filename of the MAT file */
//    int   version;          /**< MAT File version */
//    int   byteswap;         /**< 1 if byte swapping is required, 0 otherwise */
//    int   mode;             /**< Access mode */
//    long  bof;              /**< Beginning of file not including any header */
//    long  next_index;       /**< Index/File position of next variable to read */
//    long  num_datasets;     /**< Number of datasets in the file */
//    hid_t refs_id;          /**< Id of the /#refs# group in HDF5 */
//};


#endif // MATFILE_H
