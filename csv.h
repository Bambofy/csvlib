#ifndef csv_h
#define csv_h

#define maxheaderlen 256u // Maximum header length.
#define maxfieldnamelen 256u // Maximum file name length. 
#define maxrecordlen 256u // Maximum record length.
#define maxrecordfieldnamelen 256u // Maximum record field name length.
#define maxrecordfieldlen 2048u // Maximum record field length.

/**
 * Create csv header
 * Creates a new csv header from a given char string.
 *
 * @param[in] characterstring string of characters.
 * @param[out] header header for writing.
 */
void createcsvheader(char* characterstring,
                                char (*header)[maxheaderlen]);

/**
 * Create CSV file
 * Creates a new csv file.
 *
 * @param[in] filename name of the file to create.
 * @param[in] header csv header for the new csv file.
 */
void createcsvfile(char filename[maxrecordfieldnamelen],
                            char header[maxheaderlen]);

void removecsvfile(char filename[maxrecordfieldnamelen]);

/**
 * Open CSV file
 * Opens a csv file for reading and writing.
 *
 * @param[in] filename name of the file to open.
 * @param[out] filepointer file pointer of the opened file.
 */
void opencsvfile(char filename[maxrecordfieldnamelen],
                        FILE** filepointer);

/**
 * Close CSV file
 * Closes a csv file.
 *
 * @param[in] filepointer the file pointer of the csv file
 */
void closecsvfile(FILE* filepointer);

/**
 * Read CSV record.
 * Reads the next available record from the csv file.
 * 
 * @param[in] filepointer file pointer of the csv file to read from.
 * @param[out] resultingrecord record read from the csv file.
 */
void readcsvrecord(FILE* filepointer,
                            char (*resultingrecord)[maxrecordlen]);

/**
 * Write CSV Record.
 * Writes a record to the end of the csv file.
 *
 * @param[in] filepointer file pointer of the csv to write to.
 * @param[in] recordtowrite record to write to the csv file.
 */
void writecsvrecord(FILE* filepointer,
                            char recordtowrite[maxrecordfieldnamelen]);

/**
 * Get CSV file header.
 * Retrieves the header from the file pointer.
 * 
 * @param[in] filepointer file pointer to retrieve the header from.
 * @param[out] resultingheader header that is read from the file.
 */
void getcsvfileheader(FILE* filepointer,
                                char (*resultingheader)[maxheaderlen]);

/**
 * Get field column number.
 * Gets the column number of the field in the header with the name given.
 *
 * @param[in] header header to calculate the column number of.
 * @param[in] fieldname name of the field whos value to retrieve.
 * @param[out] resultfieldcolumnnum resulting field's column number.
 */
void getfieldcolnum(char header[maxheaderlen],
                            char fieldname[maxrecordfieldnamelen],
                            unsigned int* resultfieldcolumnnum);

/**
 * Get CSV record field.
 * Gets the value in the record given at the field with the name given.
 *
 * @param[in] header csv header of the corresponding record.
 * @param[in] record record to retrieve the field value from.
 * @param[in] fieldname name of the field which the value should be read from.
 * @param[out] fieldvalue value of the field read from the record.
 */
void getcsvrecordfield(char header[maxrecordfieldnamelen],
                                char record[maxrecordlen],
                                char fieldname[maxrecordfieldnamelen],
                                char (*fieldvalue)[maxrecordfieldlen]);

/**
 * Set csv record field.
 * Replaces the field value within the given record.
 *
 * @param[in,out] record Record who's field is to be set.
 * @param[in]  fieldname Name of the field which is it be set.
 * @param[in] fieldvalue Value of the field to set.
 */
void setcsvrecordfield(char (*record)[maxrecordlen],
                                char fieldname[maxrecordfieldnamelen],
                                char fieldvalue[maxrecordfieldlen]);

/**
 * Find csv record.
 * Locates the record within the file with the given field parameters.
 *
 * @param[in] filepointer File pointer to search with.
 * @param[in] fieldname Field name of the field to search for.
 * @param[in] fieldvalue Value of the field at the given field name to search for.
 * @param[out] resultingrecord Record found within the file.
 */
void findcsvrecord(FILE* filepointer,
                            char fieldname[maxfieldnamelen],
                            char fieldvalue[maxrecordfieldlen],
                            char (*resultingrecord)[maxrecordlen]);
                            

#endif
