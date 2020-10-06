#include "CUnit/Basic.h"
#include <CUnit/CUnit.h>

/* Modify these two lines according to the project */
#include <manage.h>
#define PROJECT_NAME    "Customer_Data_Management_System_Covid-19"


/* Prototypes for all the test functions */

void test_phone(void);
void test_temperature(void);
void test_sanitize_check(void);

/* Start of the application test */
int main() {
/* Note: Do not edit START*/
  /*Initialize and setup the Test Framework */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  CU_pSuite suite = CU_add_suite(PROJECT_NAME, 0, 0);
/* Note: Do not edit END */


  /* Add your test functions in this format for testing*/
  
  CU_add_test(suite, "phone", test_phone);
  CU_add_test(suite, "temperature", test_temperature);
  CU_add_test(suite, "sanitize", test_sanitize_check);


/* Note: Do not edit START*/
  /* Setup Test Framework to output the result to Screen */
  CU_basic_set_mode(CU_BRM_VERBOSE);

  /* run the unit test framework*/
  CU_basic_run_tests();

  /* Cleaning the Resources used by Unit test framework */
  CU_cleanup_registry();
/* Note: Do not edit END */
  return 0;
}


/* Write all the test functions */

struct Customer c={.phone="1234567890"};
struct Customer d={.phone="123456"};

void test_phone(void) {
  CU_ASSERT(1 == phone_check(c));
  CU_ASSERT(0 == phone_check(d));
}

void test_temperature(void) {
  CU_ASSERT(1 == temp_check());
  CU_ASSERT(1 == temp_check());
}

void test_sanitize_check(void) {
  CU_ASSERT(1 == sanitize());
  CU_ASSERT(1 == sanitize());
}
