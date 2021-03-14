#include "gtest/gtest.h"
#include <iostream>
#include <string>

extern "C" {
#include "../headers/io.h"
}

TEST (str_input_test, str_input_test){
    char * test;
    FILE * test_input_create = fopen("./test_input.txt", "w");
    std::string control = "test"; 
    if (test_input_create != NULL)
    {
        fputs("test\n", test_input_create); 
        fclose (test_input_create);
    }
    else{
        ASSERT_TRUE(false);
    }
    FILE * test_input_read = fopen("./test_input.txt", "r");
    if (test_input_read != NULL)
    {
        str_input(&test, test_input_read);
        fclose (test_input_read);
    }
    else{
        ASSERT_TRUE(false);
    }
    std::string str(test);
    EXPECT_EQ(test, control);
}

TEST (date_input_test, date_input_test){
    date_t date_test = {1, 1, 2001};
    date_t test_result = {NULL, NULL, NULL};
    FILE * test_input_create = fopen("./test_input.txt", "w");
    if (test_input_create != NULL)
    {
        fputs("1 1 2001\n", test_input_create); 
        fclose (test_input_create);
    }
    else{
        ASSERT_TRUE(false);
    }
    FILE * test_input_read = fopen("./test_input.txt", "r");
    if (test_input_read != NULL)
    {
        date_input(&test_result, test_input_read);
        fclose (test_input_read);
    }
    else{
        ASSERT_TRUE(false);
    }
    EXPECT_EQ(test_result.dd, date_test.dd);
    EXPECT_EQ(test_result.mm, date_test.mm);
    EXPECT_EQ(test_result.yy, date_test.yy);
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