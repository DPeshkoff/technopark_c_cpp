#include "gtest/gtest.h"

extern "C" {
#include "../headers/data.h"
}

TEST (date_t_test, date_t_test){
    date_t date_test = {1, 1, 2001};
    
    date_t test_result = to_date_t(1, 1, 2001);

    EXPECT_EQ(test_result.dd, date_test.dd);
    EXPECT_EQ(test_result.mm, date_test.mm);
    EXPECT_EQ(test_result.yy, date_test.yy);
}


TEST (test_t_test, test_t_test){
    date_t date_test = {1, 1, 2001};
    tbool_t test_tbool = NS;
    char * test_str = "test";
    entry_t test_entry = {test_str, test_str, test_str, date_test, date_test, test_tbool};
    entry_t test_result = to_entry_t(test_str, test_str, test_str, date_test, date_test, test_tbool);

    EXPECT_EQ(test_result.organization, test_entry.organization);
    EXPECT_EQ(test_result.type_of_document, test_entry.type_of_document);
    EXPECT_EQ(test_result.document_name, test_entry.document_name);

    EXPECT_EQ(test_result.accepted.dd, test_entry.accepted.dd);
    EXPECT_EQ(test_result.accepted.mm, test_entry.accepted.mm);
    EXPECT_EQ(test_result.accepted.yy, test_entry.accepted.yy);

    EXPECT_EQ(test_result.active_since.dd, test_entry.active_since.dd);
    EXPECT_EQ(test_result.active_since.mm, test_entry.active_since.mm);
    EXPECT_EQ(test_result.active_since.yy, test_entry.active_since.yy);

    EXPECT_EQ(test_result.is_translated, test_entry.is_translated);
}

TEST (date_t_cmp_test_eq, date_t_cmp_test_eq){
    date_t date_test_1 = {1, 1, 2001};
    
    date_t date_test_2 = {1, 1, 2001};

    EXPECT_EQ(date_t_cmp(date_test_1, date_test_2), 1);
}

TEST (date_t_cmp_test_neq, date_t_cmp_test_neq){
    date_t date_test_1 = {1, 1, 2001};
    
    date_t date_test_2 = {25, 12, 2021};

    EXPECT_EQ(date_t_cmp(date_test_1, date_test_2), 0);
}

