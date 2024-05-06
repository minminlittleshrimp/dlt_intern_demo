#include "hello_dlt.hpp"
#include <dlt/dlt.h>

DLT_DECLARE_CONTEXT(logCtx);

void init_logging() {
    DLT_REGISTER_APP("hello", "hello dlt");
    DLT_REGISTER_CONTEXT(logCtx, "hello_dlt", "hello dlt");
}

int log_message(const char* message) {
    if (message == nullptr) {
        return 0; 
    }
    DLT_LOG(logCtx, DLT_LOG_INFO, DLT_STRING(message));
    return 1; 
}

void deinit_logging() {
    DLT_UNREGISTER_CONTEXT(logCtx);
    DLT_UNREGISTER_APP();
}
