#include "test_s21.h"

int main() {
  int no_failed = 0;
  Suite* suite = my_string_suite();
  SRunner* runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (no_failed == 0) ? EXIT_SUCCSESS : EXIT_FAILURE;
}
