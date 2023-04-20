#include "fault.h"

void stop() 
{
    while (1) 
    {
        int inchar; // Input character from the user.

        fprintf(stdout, "Abort or continue? (a for abort, c for continue)\r\n");
        inchar = getc(stdin);
        if (inchar == 'a') 
        {
            exit(EXIT_FAILURE);
        } 
        else if (inchar == 'c')
        {
            break;
        } 
        else 
        {
            fprintf(stdout, "Unknown reponse given: '%c' must be 'a' or 'c'.\r\n", inchar);
        }
    }
}

void fault(char* str, float r) 
{
    fprintf(stderr, "fault  %s  %f\r\n", str, r);
    stop();
}
