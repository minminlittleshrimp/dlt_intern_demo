#include <dlt/dlt.h>
#include "hello_dlt.h"
DLT_DECLARE_CONTEXT(hello)

int dlt_log_to_console(int log_level, const char *text) {
    if (log_level == STDOUT_RETURN_ERROR)
        printf("Issue occurs, cannot print data\n");
    else if (log_level == STDOUT_RETURN_OK)
        printf("Value can be read OK and print to console: %s\n", text);
    else
        printf("Warning: Invalid data!\n");
    return log_level;
}    

