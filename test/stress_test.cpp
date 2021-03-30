#include "gtest/gtest.h"
#include <chrono>
#include <stdint.h>

extern "C" {
#include "io.h"
#include "hash.h"
}

extern __inline__ uint64_t rdtsc() {
  uint64_t x;
  __asm__ volatile ("rdtsc\n\tshl $32, %%rdx\n\tor %%rdx, %%rax" : "=a" (x) : : "rdx");
  return x;
}

#define STRESS_TEST_POSITIONS 16

#define NO_OUTPUT 0

TEST (stress_test_10k, stress_test_10k){

    std::string stress_test_result = " Jubal\n Fitzgerald\n Cleaner\n F\n 18.10\n 24388.70 $\n 41.26\n Rutherford\n Bowie\n Cleaner\n F\n 99.00\n 24950.50 $\n 25.76\n Winfield\n Bailey\n Owner\n F\n 18.10\n 19866.68 $\n 12.42\n Theodore\n Banks\n Technical Support\n F\n 18.30\n 19858.20 $\n 10.83\n Ferdinand\n Kent\n Technical Support\n F\n 98.90\n 15776.11 $\n 8.29\n August\n Waterhouse\n Director\n M\n 18.10\n 10281.29 $\n 44.82\n Paul\n Vane\n Owner\n F\n 99.00\n 21829.80 $\n 15.33\n Jebediah\n Garfield\n Programmer\n F\n 99.00\n 21183.55 $\n 44.28\n Julius\n Stuyvesant\n Teamlead\n F\n 18.20\n 7487.23 $\n 44.48\n Ian\n Corbin\n Teamlead\n F\n 98.90\n 2307.64 $\n 38.81\n Rufus\n Arnold\n Designer\n F\n 18.10\n 11475.82 $\n 53.18\n Daniel\n May\n Designer\n M\n 99.00\n 24527.63 $\n 19.94\n Upton\n Roberts\n Language Team Member\n F\n 18.00\n 18196.22 $\n 22.10\n Hector\n Whitney\n Visiting Professor\n M\n 18.10\n 11124.14 $\n 8.11\n Michael\n Pierce\n Visiting Professor\n M\n 98.90\n 8327.11 $\n 14.78\n Patrick\n Penn\n Language Team Member\n F\n 99.00\n 20746.66 $\n 42.43\n Anthony\n McKinley\n System Administrator\n M\n 18.00\n 8751.88 $\n 41.17\n Sylvester\n Brown\n System Administrator\n M\n 99.00\n 5964.18 $\n 34.36\n Angus\n Tuttle\n Tester\n F\n 18.00\n 2259.39 $\n 2.78\n Donald\n Harris\n Tester\n F\n 98.90\n 4983.65 $\n 45.18\n";


    hashtable_t table;
    entry_value_t test;
    list_node_t * list = NULL;
    FILE * test_input_read = fopen("./stress_test.txt", "r");

    EXPECT_EQ(hashtable_create(&table, STRESS_TEST_POSITIONS), EXIT_SUCCESS);

    if (test_input_read != NULL)
    {
        
        for (size_t i = 0; i < 10000; ++i){
            EXPECT_EQ(entry_value_input(&test, test_input_read, NO_OUTPUT), EXIT_SUCCESS);
            EXPECT_EQ(hashtable_insert(&table, &test), EXIT_SUCCESS);    
        }
        fclose(test_input_read);

        auto start_time = std::chrono::steady_clock::now();
        uint64_t start = rdtsc();
        EXPECT_EQ(hashtable_find(&table, &list), EXIT_SUCCESS);
        uint64_t finish = rdtsc();
        auto end_time = std::chrono::steady_clock::now();

        EXPECT_EQ(list_sort(&list, position), EXIT_SUCCESS);

        testing::internal::CaptureStdout();
        EXPECT_EQ(list_printf(&list), EXIT_SUCCESS);
        std::string output = testing::internal::GetCapturedStdout();

        EXPECT_EQ(list_printf(&list), EXIT_SUCCESS);

        EXPECT_EQ(output, stress_test_result);
        auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
        std::cout << "Stress test chrono results: " << elapsed_ns.count() << " ns\n";
        std::cout << "Stress test ticks results: " << (finish - start) << " ticks\n";

        ASSERT_EQ(list_delete(&list), EXIT_SUCCESS);
        ASSERT_EQ(hashtable_delete(&table), EXIT_SUCCESS);
    }
    else{
        ASSERT_EQ(list_delete(&list), EXIT_SUCCESS);
        ASSERT_EQ(hashtable_delete(&table), EXIT_SUCCESS);
        FAIL();
    }

} 


