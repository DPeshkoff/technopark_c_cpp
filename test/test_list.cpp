#include "gtest/gtest.h"

extern "C" {
#include "list.h"
}

TEST (list_init_test, list_init_test){
    entry_t test_entry;
    node_t * head = NULL;

    EXPECT_EQ(list_add(&head, test_entry), EXIT_SUCCESS);
    ASSERT_EQ(list_delete(&head), EXIT_SUCCESS);
}

TEST (list_add_test, list_add_test){
    entry_t test_entry_1;

    node_t * head = NULL;

    list_add(&head, test_entry_1);
    list_add(&head, test_entry_1);


    EXPECT_FALSE(head == NULL);
    ASSERT_EQ(list_delete(&head), EXIT_SUCCESS);

}

TEST (list_printf_test, list_printf_test){
    entry_t test_entry = {(char *)"test1", (char *)"test2", (char *)"test3", to_date_t(1, 1, 2001), to_date_t(1, 2, 2001), NS};

    node_t * head = NULL;

    list_add(&head, test_entry);

    testing::internal::CaptureStdout();
    list_printf(&head);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, " test1\n test2, test3\n 1.1.2001\n 1.2.2001\n Translation not specified\n \n");

    
    ASSERT_EQ(list_delete(&head), EXIT_SUCCESS);

} 

TEST (list_find_eq_single, list_find_eq_single){
    entry_t test_entry = {(char *)"test", (char *)"testeq", (char *)"testing", to_date_t(1, 5, 2001), to_date_t(1, 1, 2008), FALSE};
    entry_t test_entry_eq = {(char *)"test", (char *)"testeq", (char *)"testing", to_date_t(1, 5, 2001), to_date_t(1, 1, 2008), FALSE};

    node_t * head = NULL;

    list_add(&head, test_entry);

    testing::internal::CaptureStdout();
    list_find(&head, test_entry_eq);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output,  "Entry found: \n test\n testeq, testing\n 1.5.2001\n 1.1.2008\n Translation does not exist\n \n");
    
    ASSERT_EQ(list_delete(&head), EXIT_SUCCESS);

} 

TEST (list_find_neq_single, list_find_neq_single){

    entry_t test_entry = {(char *)"test", (char *)"testeq", (char *)"test_eq", to_date_t(1, 1, 2001), to_date_t(1, 2, 2001), FALSE};
    entry_t test_entry_neq = {(char *)"test", (char *)"testeq", (char *)"test_neq", to_date_t(1, 1, 2001), to_date_t(1, 2, 2001), FALSE};

    node_t * head = NULL;

    list_add(&head, test_entry);

    testing::internal::CaptureStdout();
    list_find(&head, test_entry_neq);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output,  "No entries found.\n");
    
    ASSERT_EQ(list_delete(&head), EXIT_SUCCESS);

} 

TEST (list_find_eq_multiple, list_find_eq_multiple){

    entry_t filler_entry_1 = {(char *)"iam", (char *)"afirst", (char *)"fillerentry_t", to_date_t(12, 10, 2005), to_date_t(2, 12, 2006), TRUE};

    entry_t filler_entry_2 = {(char *)"iam", (char *)"asecond", (char *)"fillerentry_t", to_date_t(11, 4, 1970), to_date_t(5, 12, 2007), FALSE};

    entry_t test_entry = {(char *)"iam", (char *)"tobe", (char *)"found", to_date_t(10, 1, 2009), to_date_t(12, 2, 2009), TRUE};

    entry_t test_entry_eq = {(char *)"iam", (char *)"tobe", (char *)"found", to_date_t(10, 1, 2009), to_date_t(12, 2, 2009), TRUE};

    node_t * head = NULL;


    list_add(&head, filler_entry_1);
    list_add(&head, filler_entry_2);
    list_add(&head, filler_entry_1);
    list_add(&head, filler_entry_1);
    list_add(&head, filler_entry_2);
    list_add(&head, test_entry);
    list_add(&head, filler_entry_1);
    list_add(&head, filler_entry_1);
    list_add(&head, filler_entry_2);


    testing::internal::CaptureStdout();
    list_find(&head, test_entry_eq);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output,  "Entry found: \n iam\n tobe, found\n 10.1.2009\n 12.2.2009\n Translation exists\n \n");
    
    ASSERT_EQ(list_delete(&head), EXIT_SUCCESS);

} 

TEST (list_find_neq_multiple, list_find_neq_multiple){
    entry_t filler_entry_1 = {(char *)"a", (char *)"first entry", (char *)"of fillers", to_date_t(5, 5, 5555), to_date_t(1, 12, 2076), NS};

    entry_t filler_entry_2 = {(char *)"a", (char *)"second entry", (char *)"of fillers", to_date_t(11, 2, 1970), to_date_t(1, 1, 2015), FALSE};

    entry_t test_entry = {(char *)"the loneliest", (char *)"entry", (char *)"ever", to_date_t(11, 4, 2001), to_date_t(12, 4, 2001), TRUE};

    node_t * head = NULL;

    list_add(&head, filler_entry_1);
    list_add(&head, filler_entry_2);
    list_add(&head, filler_entry_1);
    list_add(&head, filler_entry_1);
    list_add(&head, filler_entry_2);
    list_add(&head, filler_entry_2);
    list_add(&head, filler_entry_1);
    list_add(&head, filler_entry_1);
    list_add(&head, filler_entry_2);

    testing::internal::CaptureStdout();
    list_find(&head, test_entry);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output,  "No entries found.\n");
    
    ASSERT_EQ(list_delete(&head), EXIT_SUCCESS);

} 


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}