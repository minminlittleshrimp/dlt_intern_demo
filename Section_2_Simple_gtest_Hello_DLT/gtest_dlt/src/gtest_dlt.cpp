#include <stdio.h>
#include <stdlib.h>
#include "gtest/gtest.h"
#include "dlt/hello_dlt.h"

TEST(t_dlt_log_to_console, normal) {
    int level = STDOUT_RETURN_OK;
    const char* str = "Hello World!";

    EXPECT_EQ(STDOUT_RETURN_OK, dlt_log_to_console(level, str));
    
    //level = STDOUT_RETURN_ERROR;
    //EXPECT_EQ(STDOUT_RETURN_ERROR, dlt_log_string(context, loglevel, text));

    //level = STDOUT_RETURN_INVALID;


}

//TEST(t_dlt_log_string, abnormal) {

//}

//TEST(t_dlt_log_string, null) {

//}

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
