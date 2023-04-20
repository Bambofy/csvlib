#include "fault.h"
#include "csv.h"

void createcsvheader(char* characterstring,
                     char (*header)[maxheaderlen])
{
    unsigned int charstringlength; // Length of the character string parameter.
    
    if (characterstring == NULL) // Check that the character string isn't null.
    {
        fault("null in parameter", 0.0f);
    }
    if (header == NULL) // Check that the header parameter is not null.
    {
        fault("null out parameter", 0.0f);
    }
    charstringlength = strlen(characterstring); // Calculate the length of the string.
    if (charstringlength > maxheaderlen) // Compare the given string to the maximum length a header can be
    {
        fault("char string too long", 0.0f);
    }
    strncpy(*header, characterstring, charstringlength); // Copy the string given into the header destination.
}

void createcsvfile(char filename[maxfieldnamelen],
                   char header[maxheaderlen])
{
    FILE* newfilespointer;	// New file's file pointer.
    DWORD fileattributes; // File attributes.

    newfilespointer = fopen(filename, "r"); // Attempt to open the file.
    if (newfilespointer != NULL) // Open the file and check for success.
    {
        fclose(newfilespointer); // Close the open file.
        fault("file already exists", 0.0f);
    }
    else
    {
        fclose(newfilespointer); // Close the previous file pointer.
        newfilespointer = fopen(filename, "w"); // Open or create the new file.
        fputs(header, newfilespointer); // Put the header into the new file.
        fclose(newfilespointer); // Close the new file.
    }
}

void removecsvfile(char filename[maxfieldnamelen])
{
    remove(filename); // Remove the file from the disk.
}

void opencsvfile(char filename[maxfieldnamelen],
                        FILE** resultingfilepointer)
{
    char header[maxheaderlen]; // header within the csv file.
    DWORD fileattributes; // Attributes of the file to open.

    if (resultingfilepointer == NULL) // Checking that the resulting file pointer
    {
        fault("null out parameter", 0.0f);
    }
    if (fileattributes == INVALID_FILE_ATTRIBUTES)
    {
        fault("file doesn't exist", 0.0f);
    }
    (*resultingfilepointer) = fopen(filename, "r+");
    fgets(header, maxheaderlen, *resultingfilepointer);
}

void closecsvfile(FILE* filepointer)
{
    if (filepointer == NULL) // Check the file pointer parameter.
    {
        fault("null in parameter", 1.0f);
    }
    fclose(filepointer);
}

void readcsvrecord(FILE* filepointer,
                            char (*resultingrecord)[maxrecordlen])
{
    if (filepointer == NULL)
    {
        fault("null in parameter", 0.0f);
    }
    if (resultingrecord == NULL)
    {
        fault("null out parameter", 0.0f);
    }
    if (feof(filepointer) == true)
    {
        fault("file not open", 0.0f);
    }
    if (ftell(filepointer) == SEEK_SET)
    {
        fault("file pointer at header position", 0.0f);
    }
    fgets(*resultingrecord, maxrecordlen, filepointer);
}

void writecsvrecord(FILE* filepointer,
                    char recordtowrite[maxrecordlen])
{
    if (filepointer == NULL)
    {
        fault("null in parameter", 0.0f);
    }
    fputs(recordtowrite, filepointer);
}

void getcsvfileheader(FILE* filepointer,
                      char (*resultingheader)[maxheaderlen])
{
    if (filepointer == NULL)
    {
        fault("null in parameter", 0.0f);
    }
    if (resultingheader == NULL)
    {
        fault("null out parameter", 0.0f);
    }
    fseek(filepointer, 0, SEEK_SET);
    fgets(*resultingheader, maxheaderlen, filepointer);
    fseek(filepointer, 0, SEEK_SET);
}

void getfieldcolnum(char header[maxheaderlen],
                            char fieldname[maxrecordfieldnamelen],
                            unsigned int* resultfieldcolumnnum)
{
    char* currenttoken; // Current token.
    
    if (resultfieldcolumnnum == NULL) // Check if the output parameter is non-null.
    {
        fault("invalid parameter", 3.0f); // Fault if non-null parameter hit.
    }
    *resultfieldcolumnnum = 0u; // Set the field column number to 0.
    currenttoken = strtok(header, ","); // Get the first token in the header.
    while (currenttoken != NULL) // For each other token in the header.
    {
        if (strstr(currenttoken, fieldname) != NULL) // Check if the token matches the requested field name
        {
            break; // Stop searching the tokens, it has been found.
        }
        else
        {
            *resultfieldcolumnnum = *resultfieldcolumnnum + 1u; // Increment the number of columns iterated.
            currenttoken = strtok(NULL, ","); // Get the next token in the header string.
        }
    }
    if (currenttoken == NULL) // Check if the token ended up NULL.
    {
        fault("field column number not found", 0.0f); // Fault parameter given to the record.
    }
}

void getcsvrecordfield(char header[maxheaderlen],
                                char record[maxrecordlen],
                                char fieldname[maxrecordfieldnamelen],
                                char (*fieldvalue)[maxrecordfieldlen]) 
{
    
    unsigned int fieldcolnumber; // Field's column number.
    unsigned int colnumcounter; // Column number counter.
    char* currenttoken;  // Current token.

    fieldcolnumber = 0u;
    colnumcounter = 0u;
    currenttoken = NULL;

    if (fieldvalue == NULL) // Check that the output parameter is non-null.
    {
        fault("null out parameter", 0.0f);
    }
    getfieldcolnum(header, fieldname, &fieldcolnumber); // Search for the column number of that field name.
    currenttoken = strtok(record, ","); // Retrieve the first token/field of the record.
    while (currenttoken != NULL) //  For each token in the record.
    {
        if (colnumcounter == fieldcolnumber) // If this token is in the column which the field name corresponds to.
        {
            strcpy(*fieldvalue, currenttoken); // Copy the field value to the output parameter.
            break;
        }
        else
        {
            colnumcounter = colnumcounter + 1u; // Increment the column number counter.
            currenttoken = strtok(NULL, ","); // Retrieve the next token of the record string.
        }
    }
    if (currenttoken == NULL) // If iterating the token finished with no found fields.
    {
        fault("could not find field", 0.0f);
    }
}

void setcsvrecordfield(char header[maxheaderlen],
                                char (*record)[maxrecordlen],
                                char fieldname[maxrecordfieldnamelen],
                                char fieldvalue[maxrecordfieldlen])
{
    if (record == NULL) // Check the input parameters.
    {
        fault("invalid input parameter", 1.0f);
    }
}


void findcsvrecord(FILE* filepointer,
                    char fieldname[maxfieldnamelen],
                    char fieldvalue[maxrecordfieldlen],
                    char (*resultingrecord)[maxrecordlen]) 
{
    char header[maxheaderlen];

    if (filepointer == NULL) 
    {
        fault("null in parameter", 0.0f);
    }
    if (resultingrecord == NULL) 
    {
        fault("null out parameter", 0.0f);
    }
    getcsvfileheader(filepointer, &header);
    while (feof(filepointer) == false) 
    {
        char currentrecord[maxrecordlen];
        char currfieldvalue[maxrecordfieldlen];

        readcsvrecord(filepointer, &currentrecord);
        getcsvrecordfield(header, currentrecord, fieldname, &currfieldvalue);
        if (strstr(fieldvalue, currfieldvalue) == NULL) 
        {
            strncpy(*resultingrecord, currentrecord, maxrecordlen);
        } 
        else
        {
            continue;
        }
    }
}











