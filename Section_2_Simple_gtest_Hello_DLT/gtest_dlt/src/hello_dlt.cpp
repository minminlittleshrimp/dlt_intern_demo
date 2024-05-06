#include <stdio.h>
#include <stdlib.h>
#include "dlt/hello_dlt.h"

int dlt_log_to_console(int log_level, const char *text) {
    if (log_level == STDOUT_RETURN_ERROR)
        printf("Level %d: Issue occurs, cannot print data\n", log_level);
    else if (log_level == STDOUT_RETURN_OK)
        printf("Level  %d: Value can be read OK and print to console: %s\n", log_level, text);
    else
        printf("Level %d: Warning, invalid data!\n", log_level);
    return log_level;
}    

/*int main() {
    const char* str = "Hello";
    dlt_log_to_console(0, str);
    dlt_log_to_console(-1, str);
    dlt_log_to_console(-2, str);
}*/
