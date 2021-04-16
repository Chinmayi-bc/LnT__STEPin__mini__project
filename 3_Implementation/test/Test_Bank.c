/**
 * @file Test_Bank.c
 * @author Chinmayi B C (chinmayi1219@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "unity.h"
#include "bankheader.h"
#define PROJECT_NAME "Bank"
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}
/**
 * @brief unit test
 * 
 */
void test_fun_close(void)
{
     TEST_ASSERT_EQUAL_STRING( "Have a nice day!",fun_close());
     TEST_ASSERT_EQUAL_STRING("Visit again", fun_close());
}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();
  RUN_TEST(test_fun_close);
  /* Close the Unity Test Framework */
  return UNITY_END();
}