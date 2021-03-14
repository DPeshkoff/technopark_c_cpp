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
    FILE * test_input_read = fopen("./test_input.txt", "r");
    if (test_input_read != NULL)
    {
        str_input(&test, test_input_read);
        fclose (test_input_read);
    }
    std::string str(test);
    EXPECT_EQ(test, control);
    std::remove("./test_input.txt");
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
    FILE * test_input_read = fopen("./test_input.txt", "r");
    if (test_input_read != NULL)
    {
        date_input(&test_result, test_input_read);
        fclose (test_input_read);
    }
    EXPECT_EQ(test_result.dd, date_test.dd);
    EXPECT_EQ(test_result.mm, date_test.mm);
    EXPECT_EQ(test_result.yy, date_test.yy);
    std::remove("./test_input.txt");
}


TEST (tbool_input_test, tbool_input_test){
    tbool_t tbool_test_result = TRUE;
    FILE * test_input_create = fopen("./test_input.txt", "w");
    if (test_input_create != NULL)
    {
        fputs("1\n", test_input_create); 
        fclose(test_input_create);
    }
    FILE * test_input_read = fopen("./test_input.txt", "r");
    if (test_input_read != NULL)
    {
        tbool_input(&tbool_test_result, test_input_read);
        fclose(test_input_read);
    }
    EXPECT_TRUE(tbool_test_result);
    std::remove("./test_input.txt");
}


TEST (entry_input_test, entry_input_test){
    date_t date_test = {NULL, NULL, NULL};
    entry_t test_entry = {"test", "test", "test", date_test, date_test, NS};
    entry_t test_result = {NULL, NULL, NULL, date_test, date_test, NS};
    FILE * test_input_create_0 = fopen("./test_input_0.txt", "w");
    FILE * test_input_create_1 = fopen("./test_input_1.txt", "w");
    FILE * test_input_create_2 = fopen("./test_input_2.txt", "w");
    FILE * test_input_create_3 = fopen("./test_input_3.txt", "w");
    FILE * test_input_create_4 = fopen("./test_input_4.txt", "w");
    FILE * test_input_create_5 = fopen("./test_input_5.txt", "w");
    if ((test_input_create_0 != NULL)&&(test_input_create_1 != NULL)&&(test_input_create_2 != NULL)&&(test_input_create_3 != NULL)&&(test_input_create_4 != NULL)&&(test_input_create_5 != NULL))
    {
        fputs("test\n", test_input_create_0); 
        fclose (test_input_create_0);
        fputs("test\n", test_input_create_1); 
        fclose (test_input_create_1);
        fputs("test\n", test_input_create_2); 
        fclose (test_input_create_2);
        fputs("0 0 0\n", test_input_create_3); 
        fclose (test_input_create_3);
        fputs("0 0 0\n", test_input_create_4); 
        fclose (test_input_create_4);
        fputs("0\n", test_input_create_5); 
        fclose (test_input_create_5);
    }
    FILE * test_input_read_0 = fopen("./test_input_0.txt", "r");
    FILE * test_input_read_1 = fopen("./test_input_1.txt", "r");
    FILE * test_input_read_2 = fopen("./test_input_2.txt", "r");
    FILE * test_input_read_3 = fopen("./test_input_3.txt", "r");
    FILE * test_input_read_4 = fopen("./test_input_4.txt", "r");
    FILE * test_input_read_5 = fopen("./test_input_5.txt", "r");
    if ((test_input_read_0 != NULL)&&(test_input_read_1 != NULL)&&(test_input_read_2 != NULL)&&(test_input_read_3 != NULL)&&(test_input_read_4 != NULL)&&(test_input_read_5 != NULL))
    {
        entry_input(&test_result, test_input_read_0, test_input_read_1, test_input_read_2, test_input_read_3, test_input_read_4, test_input_read_5);
        fclose (test_input_read_0);
        fclose (test_input_read_1);
        fclose (test_input_read_2);
        fclose (test_input_read_3);
        fclose (test_input_read_4);
        fclose (test_input_read_5);
    }
    std::string test_string_0(test_result.organization);
    std::string control_string_0(test_entry.organization);
    std::string test_string_1(test_result.type_of_document);
    std::string control_string_1(test_entry.type_of_document);
    std::string test_string_2(test_result.document_name);
    std::string control_string_2(test_entry.document_name);

    EXPECT_EQ(test_string_0, control_string_0);
    EXPECT_EQ(test_string_1, control_string_1);
    EXPECT_EQ(test_string_2, control_string_2);


    EXPECT_EQ(test_result.accepted.dd, test_entry.accepted.dd);
    EXPECT_EQ(test_result.accepted.mm, test_entry.accepted.mm);
    EXPECT_EQ(test_result.accepted.yy, test_entry.accepted.yy);

    EXPECT_EQ(test_result.active_since.dd, test_entry.active_since.dd);
    EXPECT_EQ(test_result.active_since.mm, test_entry.active_since.mm);
    EXPECT_EQ(test_result.active_since.yy, test_entry.active_since.yy);

    EXPECT_EQ(test_result.is_translated, test_entry.is_translated);

    std::remove("./test_input_0.txt");
    std::remove("./test_input_1.txt");
    std::remove("./test_input_2.txt");
    std::remove("./test_input_3.txt");
    std::remove("./test_input_4.txt");
    std::remove("./test_input_5.txt");
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