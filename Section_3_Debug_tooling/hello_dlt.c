#include <dlt/dlt.h>
DLT_DECLARE_CONTEXT(hello)

int main() {
    DLT_REGISTER_APP("HLLO", "An app to send Hello mesg");
    DLT_REGISTER_CONTEXT(hello, "HLL1", "A context for Hello");
    DLT_LOG(hello, DLT_LOG_INFO, DLT_CSTRING("Hello World"));

    DLT_UNREGISTER_CONTEXT(hello);
    DLT_UNREGISTER_APP();
    return 0;
}

