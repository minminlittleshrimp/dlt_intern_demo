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

int main() {
    DLT_REGISTER_APP("HLLO", "An app to send Hello mesg");
    DLT_REGISTER_CONTEXT(hello, "HLL1", "A context for Hello");
    dlt_log_to_console(STDOUT_RETURN_OK, "Hello World");
    DLT_LOG(hello, DLT_LOG_INFO, DLT_CSTRING("Hello World"));

    DLT_UNREGISTER_CONTEXT(hello);
    DLT_UNREGISTER_APP();
    return 0;
}

