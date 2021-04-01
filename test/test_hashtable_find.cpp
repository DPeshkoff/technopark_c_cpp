#include "gtest/gtest.h"

extern "C" {
#include "hash.h"
}

#define HASH_SIZE_TEST 4

TEST(hash_find_test, hash_find_test) {
  hashtable_t test_table;

  list_node_t* list = NULL;

  entry_value_t test;

  FILE* test_input_read = fopen("./search_test.txt", "r");

  EXPECT_EQ(hashtable_create(&test_table, HASH_SIZE_TEST), EXIT_SUCCESS);

  if (test_input_read != NULL) {
    for (size_t i = 0; i < 3; ++i) {
      EXPECT_EQ(entry_value_input(&test, test_input_read, 0), EXIT_SUCCESS);
      EXPECT_EQ(hashtable_insert(&test_table, &test), EXIT_SUCCESS);
    }
    fclose(test_input_read);

    EXPECT_EQ(hashtable_find(&test_table, &list), EXIT_SUCCESS);

    EXPECT_EQ(list_sort(&list, position), EXIT_SUCCESS);

    testing::internal::CaptureStdout();
    EXPECT_EQ(list_printf(&list), EXIT_SUCCESS);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(
        output,
        " Louis\n d'Provence\n Manager\n M\n 12.50\n 15000.50 $\n 13.50\n "
        "Louis\n d'Provence\n Manager\n M\n 12.50\n 15000.50 $\n 13.50\n "
        "Guido\n van Rossum\n Teamlead\n M\n 12.50\n 15000.50 $\n 13.50\n "
        "Bill\n Gates\n Teamlead\n M\n 55.50\n 15000.50 $\n 12.50\n");
    ASSERT_EQ(list_delete(&list), EXIT_SUCCESS);
    ASSERT_EQ(hashtable_delete(&test_table), EXIT_SUCCESS);

  } else {
    ASSERT_EQ(list_delete(&list), EXIT_SUCCESS);
    ASSERT_EQ(hashtable_delete(&test_table), EXIT_SUCCESS);
    FAIL();
  }
}