#include "gtest/gtest.h"

extern "C" {
#include "list.h"
}

TEST(list_push_test, list_push_test) {
  entry_value_t test_entry;
  list_node_t *head = NULL;

  EXPECT_EQ(list_push(&head, test_entry), EXIT_SUCCESS);

  ASSERT_EQ(list_delete(&head), EXIT_SUCCESS);
}

TEST(list_push_two_test, list_push_two_test) {
  entry_value_t test_entry;
  list_node_t *head = NULL;

  EXPECT_EQ(list_push(&head, test_entry), EXIT_SUCCESS);

  EXPECT_EQ(list_push(&head, test_entry), EXIT_SUCCESS);

  EXPECT_FALSE(head == NULL);

  ASSERT_EQ(list_delete(&head), EXIT_SUCCESS);
}

TEST(list_printf_test, list_printf_test) {
  entry_value_t test_entry = {(char *)"Yukihiro",
                              (char *)"Matsumoto",
                              (char *)"Chief Architect of Ruby",
                              MALE,
                              55,
                              25000,
                              26};
  list_node_t *head = NULL;

  EXPECT_EQ(list_push(&head, test_entry), EXIT_SUCCESS);

  testing::internal::CaptureStdout();
  EXPECT_EQ(list_printf(&head), EXIT_SUCCESS);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output,
            " Yukihiro\n Matsumoto\n Chief Architect of Ruby\n M\n 55.00\n "
            "25000.00 $\n 26.00\n");

  ASSERT_EQ(list_delete(&head), EXIT_SUCCESS);
}

TEST(list_sort_first_name_test, list_sort_first_name_test) {
  entry_value_t test_entry_1 = {(char *)"Yukihiro",
                                (char *)"Matsumoto",
                                (char *)"Chief Architect of Ruby",
                                MALE,
                                55,
                                25000,
                                26};
  entry_value_t test_entry_2 = {(char *)"William",
                                (char *)"Shakespeare",
                                (char *)"Artist",
                                MALE,
                                55,
                                25000,
                                26};
  list_node_t *head = NULL;

  EXPECT_EQ(list_push(&head, test_entry_1), EXIT_SUCCESS);

  EXPECT_EQ(list_push(&head, test_entry_2), EXIT_SUCCESS);

  EXPECT_EQ(list_sort(&head, first_name), EXIT_SUCCESS);

  testing::internal::CaptureStdout();
  EXPECT_EQ(list_printf(&head), EXIT_SUCCESS);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output,
            " William\n Shakespeare\n Artist\n M\n 55.00\n 25000.00 $\n "
            "26.00\n Yukihiro\n Matsumoto\n Chief Architect of Ruby\n M\n "
            "55.00\n 25000.00 $\n 26.00\n");

  ASSERT_EQ(list_delete(&head), EXIT_SUCCESS);
}

TEST(list_sort_last_name_test, list_sort_last_name_test) {
  entry_value_t test_entry_1 = {(char *)"Yukihiro",
                                (char *)"Matsumoto",
                                (char *)"Chief Architect of Ruby",
                                MALE,
                                55,
                                25000,
                                26};
  entry_value_t test_entry_2 = {(char *)"William",
                                (char *)"Shakespeare",
                                (char *)"Artist",
                                MALE,
                                55,
                                25000,
                                26};
  list_node_t *head = NULL;

  EXPECT_EQ(list_push(&head, test_entry_2), EXIT_SUCCESS);

  EXPECT_EQ(list_push(&head, test_entry_1), EXIT_SUCCESS);

  EXPECT_EQ(list_sort(&head, last_name), EXIT_SUCCESS);

  testing::internal::CaptureStdout();
  EXPECT_EQ(list_printf(&head), EXIT_SUCCESS);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output,
            " Yukihiro\n Matsumoto\n Chief Architect of Ruby\n M\n 55.00\n "
            "25000.00 $\n 26.00\n William\n Shakespeare\n Artist\n M\n 55.00\n "
            "25000.00 $\n 26.00\n");

  ASSERT_EQ(list_delete(&head), EXIT_SUCCESS);
}

TEST(list_sort_position_test, list_sort_position_test) {
  entry_value_t test_entry_1 = {(char *)"Yukihiro",
                                (char *)"Matsumoto",
                                (char *)"Chief Architect of Ruby",
                                MALE,
                                55,
                                25000,
                                26};
  entry_value_t test_entry_2 = {(char *)"William",
                                (char *)"Shakespeare",
                                (char *)"Artist",
                                MALE,
                                55,
                                25000,
                                26};
  list_node_t *head = NULL;

  EXPECT_EQ(list_push(&head, test_entry_1), EXIT_SUCCESS);

  EXPECT_EQ(list_push(&head, test_entry_2), EXIT_SUCCESS);

  EXPECT_EQ(list_sort(&head, position), EXIT_SUCCESS);

  testing::internal::CaptureStdout();
  EXPECT_EQ(list_printf(&head), EXIT_SUCCESS);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output,
            " William\n Shakespeare\n Artist\n M\n 55.00\n 25000.00 $\n "
            "26.00\n Yukihiro\n Matsumoto\n Chief Architect of Ruby\n M\n "
            "55.00\n 25000.00 $\n 26.00\n");

  ASSERT_EQ(list_delete(&head), EXIT_SUCCESS);
}