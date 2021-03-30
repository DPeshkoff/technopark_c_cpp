#include "gtest/gtest.h"

extern "C" {
#include "hash.h"
}

TEST(hash_test, hash_test) {
  unsigned int test_mod_value = 17;

  char *test_string = (char *)"Visiting Professor";
  entry_value_t test_entry = {(char *)"Bjarne",
                              (char *)"Stroustrup",
                              test_string,
                              MALE,
                              70,
                              100000.25,
                              42.5};

  int control_key_sum = 0, hash_code = 0;

  for (size_t i = 0; i < strlen(test_string); ++i) {
    control_key_sum += test_string[i];
  }

  control_key_sum = control_key_sum % test_mod_value;

  EXPECT_EQ(hash(&test_entry, test_mod_value, &hash_code), EXIT_SUCCESS);
  EXPECT_EQ(hash_code, control_key_sum);
}

TEST(hashtable_create_test, hashtable_create_test) {
  hashtable_t test_table;
  int test_table_size = 25;

  EXPECT_EQ(hashtable_create(&test_table, test_table_size), EXIT_SUCCESS);
  ASSERT_EQ(hashtable_delete(&test_table), EXIT_SUCCESS);
}