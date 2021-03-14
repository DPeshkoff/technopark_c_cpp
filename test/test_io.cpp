#include "gtest/gtest.h"
#include <iostream>
#include <string>

extern "C" {
#include "../headers/io.h"
}

TEST (pdata_test, pdata_test){
    date_t date_test = {1, 1, 2001};
    tbool_t test_tbool = NS;
    char * test_str = "test";
    entry_t test_entry = {test_str, test_str, test_str, date_test, date_test, test_tbool};

    testing::internal::CaptureStdout();
    pdata(&test_entry);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, " test\n test, test\n 1.1.2001\n 1.1.2001\n Translation not specified\n \n");
}


TEST (tbool_test, tbool_test){
    tbool_t test_tbool_1 = NS;
    tbool_t test_tbool_2 = TRUE;
    tbool_t test_tbool_3 = FALSE;

    testing::internal::CaptureStdout();
    tbool_translation(test_tbool_1);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Translation not specified");

    testing::internal::CaptureStdout();
    tbool_translation(test_tbool_2);
    output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Translation exists");

    testing::internal::CaptureStdout();
    tbool_translation(test_tbool_3);
    output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Translation does not exist");
}