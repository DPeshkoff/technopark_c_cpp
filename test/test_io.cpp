#include "gtest/gtest.h"

extern "C" {
#include "io.h"
}

TEST(str_input_test, str_input_test) {
  char *test;
  FILE *test_input_create = fopen("./test_input.txt", "w");
  std::string control = "test";
  if (test_input_create != NULL) {
    fputs("test\n", test_input_create);
    fclose(test_input_create);
  }
  FILE *test_input_read = fopen("./test_input.txt", "r");
  if (test_input_read != NULL) {
    EXPECT_EQ(str_input(&test, test_input_read), EXIT_SUCCESS);
    fclose(test_input_read);
  }
  std::string str(test);
  EXPECT_EQ(test, control);
  std::remove("./test_input.txt");
  free(test);
}

TEST(gender_t_input_test, gender_t_input_test) {
  gender_t gender_t_test_result = NOT_STATED;
  FILE *test_input_create = fopen("./test_input.txt", "w");
  if (test_input_create != NULL) {
    fputs("1\n", test_input_create);
    fclose(test_input_create);
  }
  FILE *test_input_read = fopen("./test_input.txt", "r");
  if (test_input_read != NULL) {
    EXPECT_EQ(gender_input(&gender_t_test_result, test_input_read),
              EXIT_SUCCESS);
    fclose(test_input_read);
  }
  EXPECT_TRUE(gender_t_test_result);
  std::remove("./test_input.txt");
}

TEST(double_input_test, double_input_test) {
  double double_test_result;
  FILE *test_input_create = fopen("./test_input.txt", "w");
  if (test_input_create != NULL) {
    fputs("75.285\n", test_input_create);
    fclose(test_input_create);
  }
  FILE *test_input_read = fopen("./test_input.txt", "r");
  if (test_input_read != NULL) {
    EXPECT_EQ(double_input(&double_test_result, test_input_read), EXIT_SUCCESS);
    fclose(test_input_read);
  }
  EXPECT_EQ(double_test_result, 75.285);
  std::remove("./test_input.txt");
}

TEST(entry_value_input_test, entry_value_input_test) {
  entry_value_t test_entry = {(char *)"Bjarne",
                              (char *)"Stroustrup",
                              (char *)"Visiting Professor",
                              MALE,
                              70,
                              100000.25,
                              42.5};
  entry_value_t test_result = {NULL, NULL, NULL, NOT_STATED, 0, 0, 0};

  FILE *test_input_create = fopen("./test_input.txt", "w");

  if (test_input_create != NULL) {
    fputs("Bjarne\n", test_input_create);
    fputs("Stroustrup\n", test_input_create);
    fputs("Visiting Professor\n", test_input_create);
    fputs("0\n", test_input_create);
    fputs("70\n", test_input_create);
    fputs("100000.25\n", test_input_create);
    fputs("42.5\n", test_input_create);
    fclose(test_input_create);
  }
  FILE *test_input_read = fopen("./test_input.txt", "r");
  if (test_input_read != NULL) {
    EXPECT_EQ(entry_value_input(&test_result, test_input_read, 0),
              EXIT_SUCCESS);
    fclose(test_input_read);
  }
  std::string test_string_0(test_result.first_name);
  std::string control_string_0(test_entry.first_name);
  std::string test_string_1(test_result.last_name);
  std::string control_string_1(test_entry.last_name);
  std::string test_string_2(test_result.position);
  std::string control_string_2(test_entry.position);

  EXPECT_EQ(test_string_0, control_string_0);
  EXPECT_EQ(test_string_1, control_string_1);
  EXPECT_EQ(test_string_2, control_string_2);

  EXPECT_EQ(test_result.sex, test_entry.sex);
  EXPECT_EQ(test_result.salary, test_entry.salary);
  EXPECT_EQ(test_result.age, test_entry.age);
  EXPECT_EQ(test_result.experience, test_entry.experience);

  std::remove("./test_input.txt");

  free(test_result.first_name);
  free(test_result.last_name);
  free(test_result.position);
}

TEST(entry_value_output_test, entry_value_output_test) {
  entry_value_t test = {(char *)"Guido",
                        (char *)"van Rossum",
                        (char *)"Developer",
                        MALE,
                        65.0,
                        150000.25,
                        0.5};

  testing::internal::CaptureStdout();
  EXPECT_EQ(entry_value_output(&test), EXIT_SUCCESS);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(
      output,
      " Guido\n van Rossum\n Developer\n M\n 65.00\n 150000.25 $\n 0.50\n");
}

TEST(gender_translation_test, gender_translation_test) {
  gender_t test_gender_0 = NOT_STATED;
  gender_t test_gender_1 = FEMALE;
  gender_t test_gender_2 = MALE;

  testing::internal::CaptureStdout();
  EXPECT_EQ(gender_translation(&test_gender_0), EXIT_SUCCESS);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, " N\n");

  testing::internal::CaptureStdout();
  EXPECT_EQ(gender_translation(&test_gender_1), EXIT_SUCCESS);
  output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, " F\n");

  testing::internal::CaptureStdout();
  EXPECT_EQ(gender_translation(&test_gender_2), EXIT_SUCCESS);
  output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, " M\n");
}