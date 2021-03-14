#include "gtest/gtest.h"

extern "C" {
#include "../headers/custom_errors.h"
}

TEST (custom_errors_test_204, custom_errors_test_204){
    errco_t test = 204; // ErrorNumberConversionFail
    testing::internal::CaptureStdout();
    errputs(test);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "[Error]:ErrorNumberConversionFail (code 204) \n");
}

TEST (custom_errors_test_200, custom_errors_test_200){
    errco_t test = 200; // ErrorMallocFailed
    testing::internal::CaptureStdout();
    errputs(test);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "[Error]:ErrorMallocFailed (code 200) \n");
}

TEST (custom_errors_test_201, custom_errors_test_201){
    errco_t test = 201; // ErrorNullEntry
    testing::internal::CaptureStdout();
    errputs(test);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "[Error]:ErrorNullEntry (code 201) \n");
}

TEST (custom_errors_test_501, custom_errors_test_501){
    errco_t test = 501; // unknown
    testing::internal::CaptureStdout();
    errputs(test);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "[Error]:Unidentified error (code 501) \n");
}

