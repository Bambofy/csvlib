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
 * @param[in] fp filepointer pointer
 */
void closecsvfile(FILE* filepointer);

/**
 *
 */
void readcsvrecord(FILE* filepointer,
                            char (*resultingrecord)[maxrecordlen]);

void writecsvrecord(FILE* filepointer,
                            char recordtowrite[maxrecordfieldnamelen]);

void getcsvfileheader(FILE* filepointer,
                                char (*resultingheader)[maxheaderlen]);
                                
void getfieldcolnum(char header[maxheaderlen],
                            char fieldname[maxrecordfieldnamelen],
                            unsigned int* resultfieldcolumnnum);
                            
void getcsvrecordfield(char header[maxrecordfieldnamelen],
                                char record[maxrecordlen],
                                char fieldname[maxrecordfieldnamelen],
                                char (*fieldvalue)[maxrecordfieldlen]);

void setcsvrecordfield(char (*record)[maxrecordlen],
                                char fieldname[maxrecordfieldnamelen],
                                char fieldvalue[maxrecordfieldlen]);

void findcsvrecord(FILE* filepointer,
                            char fieldname[maxfieldnamelen],
                            char fieldvalue[maxrecordfieldlen],
                            char (*resultingrecord)[maxrecordlen]);
                            

#endif
