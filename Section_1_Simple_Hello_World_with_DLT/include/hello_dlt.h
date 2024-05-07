#ifndef HELLO_DLT
#define HELLO_DLT

enum stdout_level {
    STDOUT_RETURN_INVALID = -2,
    STDOUT_RETURN_ERROR = -1,
    STDOUT_RETURN_OK = 0,
};

/* This function will log to stdout
 * log_level: the stdout level
 * text: data to be log
 */
int dlt_log_to_console(int log_level, const char *text);

#endif
