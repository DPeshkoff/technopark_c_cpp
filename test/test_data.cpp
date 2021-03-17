#include "gtest/gtest.h"

extern "C" {
#include "data.h"
}

TEST (date_t_test, date_t_test){
    date_t date_test = {1, 1, 2001};
    
    date_t test_result = to_date_t(1, 1, 2001);

    EXPECT_EQ(test_result.dd, date_test.dd);
    EXPECT_EQ(test_result.mm, date_test.mm);
    EXPECT_EQ(test_result.yy, date_test.yy);
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

