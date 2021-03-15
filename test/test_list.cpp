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
    date_t date_test = {1, 1, 2001};
    tbool_t test_tbool = NS;
    char * test_str = (char *)"test";
    entry_t test_entry = {test_str, test_str, test_str, date_test, date_test, test_tbool};

    node_t * head = NULL;

    list_add(&head, test_entry);

    testing::internal::CaptureStdout();
    list_printf(&head);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, " test\n test, test\n 1.1.2001\n 1.1.2001\n Translation not specified\n \n");

    
    ASSERT_EQ(list_delete(&head), EXIT_SUCCESS);

} 

TEST (list_find_eq, list_find_eq){
    date_t date_test = {1, 1, 2001};
    tbool_t test_tbool = NS;
    char * test_str = (char *)"test";
    entry_t test_entry = {test_str, test_str, test_str, date_test, date_test, test_tbool};
    entry_t test_entry_eq = {test_str, test_str, test_str, date_test, date_test, test_tbool};

    node_t * head = NULL;

    list_add(&head, test_entry);

    testing::internal::CaptureStdout();
    list_find(&head, test_entry_eq);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output,  "Entry found: \n test\n test, test\n 1.1.2001\n 1.1.2001\n Translation not specified\n \n");
    
    ASSERT_EQ(list_delete(&head), EXIT_SUCCESS);

} 

TEST (list_find_neq, list_find_neq){
    date_t date_test = {1, 1, 2001};
    tbool_t test_tbool = NS;
    tbool_t test_tbool_neq = FALSE;
    char * test_str = (char *)"test";
    char * test_str_neq = (char *)"test1";
    entry_t test_entry = {test_str, test_str, test_str, date_test, date_test, test_tbool};
    entry_t test_entry_neq = {test_str_neq, test_str_neq, test_str_neq, date_test, date_test, test_tbool_neq};

    node_t * head = NULL;

    list_add(&head, test_entry);

    testing::internal::CaptureStdout();
    list_find(&head, test_entry_neq);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output,  "No entries found.\n");
    
    ASSERT_EQ(list_delete(&head), EXIT_SUCCESS);

} 

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}