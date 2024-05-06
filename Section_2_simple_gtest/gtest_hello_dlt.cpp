#include <gtest/gtest.h>
#include "hello_dlt.hpp"

TEST(LoggingTest, LogMessageSuccess) {
    init_logging();
    
    int result = log_message("hello");
    EXPECT_EQ(1, result);
    
    deinit_logging();
}

TEST(LoggingTest, LogMessageFailure) {
    init_logging();
    
    int result = log_message(nullptr);
    EXPECT_EQ(0, result);
    
    deinit_logging();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
