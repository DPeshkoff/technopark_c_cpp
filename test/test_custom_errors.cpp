#include "gtest/gtest.h"

extern "C" {
#include "custom_errors.h"
}

TEST(custom_errors_test_5, custom_errors_test_5) {
  errco_t test = 5;  // ErrorMallocFailed
  testing::internal::CaptureStdout();
  errputs(test);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "[Error]:I/O error (code 5) \n");
}

TEST(custom_errors_test_200, custom_errors_test_200) {
  errco_t test = 200;  // ErrorMallocFailed
  testing::internal::CaptureStdout();
  errputs(test);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "[Error]:ErrorMallocFailed (code 200) \n");
}

TEST(custom_errors_test_201, custom_errors_test_201) {
  errco_t test = 201;  // ErrorNullEntry
  testing::internal::CaptureStdout();
  errputs(test);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "[Error]:ErrorNullEntry (code 201) \n");
}

TEST(custom_errors_test_202, custom_errors_test_202) {
  errco_t test = 202;  // ErrorNumberConversionFail
  testing::internal::CaptureStdout();
  errputs(test);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "[Error]:ErrorNumberConversionFail (code 202) \n");
}

TEST(custom_errors_test_203, custom_errors_test_203) {
  errco_t test = 203;  // ErrorNoSizeGiven
  testing::internal::CaptureStdout();
  errputs(test);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "[Error]:ErrorNoSizeGiven (code 203) \n");
}

TEST(custom_errors_test_204, custom_errors_test_204) {
  errco_t test = 204;  // ErrorHashTableisNull
  testing::internal::CaptureStdout();
  errputs(test);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "[Error]:ErrorHashTableisNull (code 204) \n");
}

TEST(custom_errors_test_205, custom_errors_test_205) {
  errco_t test = 205;  // ErrorListSortFail
  testing::internal::CaptureStdout();
  errputs(test);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "[Error]:ErrorListSortFail (code 205) \n");
}

TEST(custom_errors_test_206, custom_errors_test_206) {
  errco_t test = 206;  // ErrorHashTableEmpty
  testing::internal::CaptureStdout();
  errputs(test);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "[Error]:ErrorHashTableEmpty (code 206) \n");
}

TEST(custom_errors_test_207, custom_errors_test_203) {
  errco_t test = 207;  // ErrorWrongHashBasis
  testing::internal::CaptureStdout();
  errputs(test);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "[Error]:ErrorWrongHashBasis (code 207) \n");
}

TEST(custom_errors_test_501, custom_errors_test_501) {
  errco_t test = 501;  // unknown
  testing::internal::CaptureStdout();
  errputs(test);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "[Error]:Unidentified error (code 501) \n");
}