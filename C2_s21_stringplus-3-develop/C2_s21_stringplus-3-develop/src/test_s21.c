#include <check.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

START_TEST(s_strstr) {
  ck_assert_ptr_eq(s21_strstr("hello world", "world"),
                   strstr("hello world", "world"));
  ck_assert_ptr_eq(s21_strstr("hello world", "planet"),
                   strstr("hello world", "planet"));
  ck_assert_ptr_eq(s21_strstr("hello", ""), strstr("hello", ""));
}
END_TEST

START_TEST(s_strrchr) {
  ck_assert_ptr_eq(s21_strrchr("hello world", 'o'),
                   strrchr("hello world", 'o'));
  ck_assert_ptr_eq(s21_strrchr("hello world", 'p'),
                   strrchr("hello world", 'p'));
  ck_assert_ptr_eq(s21_strrchr("hello world", '\0'),
                   strrchr("hello world", '\0'));
  ck_assert_ptr_eq(s21_strrchr("", 'p'), strrchr("", 'p'));
}
END_TEST

START_TEST(s_strcspn) {
  ck_assert_int_eq(s21_strcspn("hello world", "ow"),
                   strcspn("hello world", "ow"));
  ck_assert_int_eq(s21_strcspn("hello world", "xyz"),
                   strcspn("hello world", "xyz"));
  ck_assert_int_eq(s21_strcspn("", "a"), strcspn("", "a"));
  ck_assert_int_eq(s21_strcspn("hello world", ""), strcspn("hello world", ""));
  ck_assert_int_eq(s21_strcspn("", ""), strcspn("", ""));
}
END_TEST

START_TEST(s_memchr) {
  ck_assert_ptr_eq(s21_memchr("abcdef", 'c', 6), memchr("abcdef", 'c', 6));
  ck_assert_ptr_eq(s21_memchr("abcdef", 'z', 6), memchr("abcdef", 'z', 6));
  ck_assert_ptr_eq(s21_memchr("hello\0world", '\0', 6),
                   memchr("hello\0world", '\0', 6));
  ck_assert_ptr_eq(s21_memchr("abcdef", '\0', 6), memchr("abcdef", '\0', 6));
}
END_TEST

START_TEST(s_memset) {
  char buffer1[10] = {0};
  char buffer2[10] = {0};
  ck_assert_mem_eq(s21_memset(buffer1, 'A', 5), memset(buffer2, 'A', 5), 10);
  ck_assert_mem_eq(s21_memset(buffer1, 0, 10), memset(buffer2, 0, 10), 10);
}
END_TEST

START_TEST(s_strchr) {
  ck_assert_ptr_eq(s21_strchr("hello", 'e'), strchr("hello", 'e'));
  ck_assert_ptr_eq(s21_strchr("hello", 'z'), strchr("hello", 'z'));
  ck_assert_ptr_eq(s21_strchr("hello", '\0'), strchr("hello", '\0'));
}
END_TEST

START_TEST(s_memcpy) {
  char dest[20];
  ck_assert_ptr_eq(s21_memcpy(dest, "hello world", 12),
                   memcpy(dest, "hello world", 12));
  ck_assert_ptr_eq(s21_memcpy(dest, "hello world", 0),
                   memcpy(dest, "hello world", 0));
  char ddest[10];
  ck_assert_ptr_eq(s21_memcpy(ddest, "hello world", 5),
                   memcpy(ddest, "hello world", 5));
}
END_TEST

START_TEST(s_strncat) {
  char dest1[20] = "Hello, ";
  char src1[] = "World!";
  ck_assert_ptr_eq(s21_strncat(dest1, src1, 7), strncat(dest1, src1, 7));

  char dest2[20] = "Hello";
  char src2[] = " World";
  ck_assert_ptr_eq(s21_strncat(dest2, src2, 3), strncat(dest2, src2, 3));

  char dest3[20] = "Hello";
  char src3[] = "";
  ck_assert_ptr_eq(s21_strncat(dest3, src3, 3), strncat(dest3, src3, 3));

  char dest4[20] = "";
  char src4[] = "World";
  ck_assert_ptr_eq(s21_strncat(dest4, src4, 5), strncat(dest4, src4, 5));
}
END_TEST

START_TEST(s_strpbrk) {
  ck_assert_ptr_eq(s21_strpbrk("hello world", "hlow"),
                   strpbrk("hello world", "hlow"));
  ck_assert_ptr_eq(s21_strpbrk("hello world", ""), strpbrk("hello world", ""));
  ck_assert_ptr_eq(s21_strpbrk("", "hello world"), strpbrk("", "hello world"));
}
END_TEST

START_TEST(s_strlen) {
  ck_assert_int_eq(s21_strlen("hello world"), strlen("hello world"));
  ck_assert_int_eq(s21_strlen(""), strlen(""));
  ck_assert_int_eq(s21_strlen("\0"), strlen("\0"));
  ck_assert_int_eq(s21_strlen("fhHfS245G"), strlen("fhHfS245G"));
}
END_TEST

START_TEST(test_s21_memcmp_less) {
  const char str1[] = "abc";
  const char str2[] = "abd";

  int result = s21_memcmp(str1, str2, 3);
  int result1 = memcmp(str1, str2, 3);
  ck_assert_int_eq(result, result1);
}
END_TEST

START_TEST(s_strtok) {
  char str1[] = "hello world";
  char* token1 = s21_strtok(str1, " ");

  char str2[] = "hello world";
  char* token2 = strtok(str2, " ");

  ck_assert_str_eq(token1, token2);

  token1 = s21_strtok(NULL, " ");
  token2 = strtok(NULL, " ");

  ck_assert_str_eq(token1, token2);
}
END_TEST

START_TEST(test_s21_strtok_end_of_string) {
  char str[] = "hello";
  char str1[] = "hello";
  const char delim[] = " ";
  char* token = s21_strtok(str, delim);

  char* token1 = strtok(str1, delim);

  ck_assert_str_eq(token, token1);

  token = s21_strtok(NULL, delim);

  token1 = strtok(NULL, delim);
  ck_assert_ptr_eq(token, NULL);
}
END_TEST

START_TEST(test_s21_strtok_only_delimiters) {
  char str[] = "     ";
  char str1[] = "     ";
  const char delim[] = " ";
  char* token = s21_strtok(str, delim);

  char* token1 = strtok(str1, delim);

  ck_assert_ptr_eq(token, token1);
}
END_TEST

START_TEST(test_s21_strtok_delimiter_at_end) {
  char str[] = "hello ";
  char str1[] = "hello ";
  const char delim[] = " ";
  char* token = s21_strtok(str, delim);

  char* token1 = strtok(str1, delim);

  ck_assert_str_eq(token, token1);

  token = s21_strtok(NULL, delim);
  token1 = strtok(NULL, delim);
  ck_assert_ptr_eq(token, token1);
}
END_TEST

START_TEST(test_s21_strtok_empty_string) {
  char str[] = "";
  char str1[] = "";
  const char delim[] = " ";
  char* token = s21_strtok(str, delim);

  char* token1 = strtok(str1, delim);

  ck_assert_ptr_eq(token, token1);
}
END_TEST

START_TEST(s_memcmp) {
  ck_assert_int_eq(s21_memcmp("hello", "12345", 5),
                   memcmp("hello", "12345", 5));
  ck_assert_int_eq(s21_memcmp("15345", "13348", 5),
                   memcmp("15345", "13348", 5));
}
END_TEST

START_TEST(s_strncpy) {
  char dest1[20];
  ck_assert_ptr_eq(s21_strncpy(dest1, "hello", 6), strncpy(dest1, "hello", 6));
  char dest2[20];
  ck_assert_ptr_eq(s21_strncpy(dest2, "", 1), strncpy(dest2, "", 1));
  char dest3[20];
  ck_assert_ptr_eq(s21_strncpy(dest3, "\0", 1), strncpy(dest3, "\0", 1));
}
END_TEST

START_TEST(s_strncmp) {
  ck_assert_int_eq(s21_strncmp("hello world", "hello world", 12),
                   strncmp("hello world", "hello world", 12));
  ck_assert_int_eq(s21_strncmp("hello", "world", 5),
                   strncmp("hello", "world", 5));
  ck_assert_int_eq(s21_strncmp("hello", "", 5), strncmp("hello", "", 5));
}
END_TEST

START_TEST(s_strerror) {
  ck_assert_str_eq(s21_strerror(0), strerror(0));
  ck_assert_str_eq(s21_strerror(2), strerror(2));
  ck_assert_str_eq(s21_strerror(3), strerror(3));
  ck_assert_str_eq(s21_strerror(1479836), strerror(1479836));
  ck_assert_str_eq(s21_strerror(-1), strerror(-1));
}
END_TEST

//---------------------------------------------------------------------
START_TEST(s_to_upper) {
  char* result = (char*)s21_to_upper("hello, world!");
  ck_assert_str_eq(result, "HELLO, WORLD!");

  result = (char*)s21_to_upper("12345");
  ck_assert_str_eq(result, "12345");

  result = (char*)s21_to_upper("");
  ck_assert_str_eq(result, "");
}
END_TEST

START_TEST(s_to_lower) {
  char* result = (char*)s21_to_lower("Hello, WORLD!");
  ck_assert_str_eq(result, "hello, world!");

  result = (char*)s21_to_lower("12345");
  ck_assert_str_eq(result, "12345");

  result = (char*)s21_to_lower("");
  ck_assert_str_eq(result, "");
}
END_TEST

START_TEST(s_insert) {
  char* result = (char*)s21_insert("12345", "ABC", 0);
  ck_assert_str_eq(result, "ABC12345");

  result = (char*)s21_insert("12345", "ABC", 5);
  ck_assert_str_eq(result, "12345ABC");

  result = (char*)s21_insert("12345", "ABC", 10);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(s_trim) {
  char* result = (char*)s21_trim("   Hello, World!   ", " ");
  ck_assert_str_eq(result, "Hello, World!");

  result = (char*)s21_trim("--Hello, World!--", "-");
  ck_assert_str_eq(result, "Hello, World!");

  result = (char*)s21_trim("123Hello123", "123");
  ck_assert_str_eq(result, "Hello");

  result = (char*)s21_trim("Hello", "");
  ck_assert_str_eq(result, "Hello");

  result = (char*)s21_trim("", " ");
  ck_assert_str_eq(result, "");
}
END_TEST

//-------------------------------------------------------

START_TEST(s_sprintf) {
  char buffer[100];
  char buffer1[100];

  char* name = "Alice";
  s21_sprintf(buffer, "Name: %s", name);
  sprintf(buffer1, "Name: %s", name);

  ck_assert_str_eq(buffer, buffer1);

  int age = 30;
  s21_sprintf(buffer, "Age: %d", age);
  sprintf(buffer1, "Age: %d", age);

  ck_assert_str_eq(buffer, buffer1);

  unsigned int items = 42;
  s21_sprintf(buffer, "Items: %u", items);
  sprintf(buffer1, "Items: %u", items);

  ck_assert_str_eq(buffer, buffer1);

  long i = 42;
  s21_sprintf(buffer, "Items: %lu", i);
  sprintf(buffer1, "Items: %lu", i);

  ck_assert_str_eq(buffer, buffer1);

  short x = -42;
  s21_sprintf(buffer, "Items: %hu", x);
  sprintf(buffer1, "Items: %hu", x);

  ck_assert_str_eq(buffer, buffer1);

  short k = 34;
  s21_sprintf(buffer, "Items: |%-10u|", k);
  sprintf(buffer1, "Items: |%-10u|", k);

  ck_assert_str_eq(buffer, buffer1);

  double num = 12345.6789;
  s21_sprintf(buffer, "Shortest: %0.10g", num);
  sprintf(buffer1, "Shortest: %0.10g", num);

  ck_assert_str_eq(buffer, buffer1);

  num = 0.0123456;
  s21_sprintf(buffer, "Shortest scientific: %0.10g", num);
  sprintf(buffer1, "Shortest scientific: %0.10g", num);

  ck_assert_str_eq(buffer, buffer1);

  unsigned int hex = 255;
  s21_sprintf(buffer, "Hex: %x", hex);
  sprintf(buffer1, "Hex: %x", hex);

  ck_assert_str_eq(buffer, buffer1);

  long hex1 = 255;
  s21_sprintf(buffer, "Hex: %lx", hex1);
  sprintf(buffer1, "Hex: %lx", hex1);

  ck_assert_str_eq(buffer, buffer1);

  short hex2 = 255;
  s21_sprintf(buffer, "Hex: %hx", hex2);
  sprintf(buffer1, "Hex: %hx", hex2);

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "|%-10x|", 123);
  sprintf(buffer1, "|%-10x|", 123);

  ck_assert_str_eq(buffer, buffer1);

  double pi = 3.1;
  s21_sprintf(buffer, "Pi: %0.4f", pi);
  sprintf(buffer1, "Pi: %0.4f", pi);

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "Pi: %+f", pi);
  sprintf(buffer1, "Pi: %+f", pi);

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "Pi: %-f", pi);
  sprintf(buffer1, "Pi: %-f", pi);

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "Pi: % f", pi);
  sprintf(buffer1, "Pi: % f", pi);

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "Pi: |%-10f|", pi);
  sprintf(buffer1, "Pi: |%-10f|", pi);

  ck_assert_str_eq(buffer, buffer1);

  char grade = 'A';
  s21_sprintf(buffer, "Grade: %c", grade);
  sprintf(buffer1, "Grade: %c", grade);

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "Character: %c", 'A');
  sprintf(buffer1, "Character: %c", 'A');

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "String: %.5s", "Hello, world!");
  sprintf(buffer1, "String: %.5s", "Hello, world!");

  ck_assert_str_eq(buffer, buffer1);

  void* ptr = (void*)0xDEADBEEF;
  s21_sprintf(buffer, "Pointer: %p", ptr);
  sprintf(buffer1, "Pointer: %p", ptr);

  ck_assert_str_eq(buffer, buffer1);

  int n;
  s21_sprintf(buffer, "Count test%n", &n);
  sprintf(buffer1, "Count test%n", &n);

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "|%-10d|", 123);
  sprintf(buffer1, "|%-10d|", 123);

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "|%+d|", 123);
  sprintf(buffer1, "|%+d|", 123);

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "|% d|", 123);
  sprintf(buffer1, "|% d|", 123);

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "|%#o|", 123);
  sprintf(buffer1, "|%#o|", 123);

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "|%-10o|", 123);
  sprintf(buffer1, "|%-10o|", 123);

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "|%#x|", 123);
  sprintf(buffer1, "|%#x|", 123);

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "|%010d|", 123);
  sprintf(buffer1, "|%010d|", 123);

  ck_assert_str_eq(buffer, buffer1);

  short sh = -12345;
  s21_sprintf(buffer, "Short: %hd", sh);
  sprintf(buffer1, "Short: %hd", sh);

  ck_assert_str_eq(buffer, buffer1);

  long lg = 123456789L;
  s21_sprintf(buffer, "Long: %ld", lg);
  sprintf(buffer1, "Long: %ld", lg);

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(s_sprintf2) {
  char buffer[256];
  char buffer1[256];

  s21_sprintf(buffer, "%*d", 10, 123);
  sprintf(buffer1, "%*d", 10, 123);

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "%-*d", 10, 123);
  sprintf(buffer1, "%-*d", 10, 123);

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "%.*f", 3, 123.456789);
  sprintf(buffer1, "%.*f", 3, 123.456789);

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "%.*s", 5, "Hello, world!");
  sprintf(buffer1, "%.*s", 5, "Hello, world!");

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "%Lf", 123.456789L);
  sprintf(buffer1, "%Lf", 123.456789L);

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "%.10Lf", 123.456789L);
  sprintf(buffer1, "%.10Lf", 123.456789L);

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "%#g", 123.45678);
  sprintf(buffer1, "%#g", 123.45678);

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "%#G", 123.0);
  sprintf(buffer1, "%#G", 123.0);

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "%#.5e", 123.456);
  sprintf(buffer1, "%#.5e", 123.456);

  ck_assert_str_eq(buffer, buffer1);

  long double r = 123.456;
  s21_sprintf(buffer, "%Le", r);
  sprintf(buffer1, "%Le", r);

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "%#.5E", 123.456);
  sprintf(buffer1, "%#.5E", 123.456);

  ck_assert_str_eq(buffer, buffer1);

  s21_sprintf(buffer, "%%");
  sprintf(buffer1, "%%");

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

//---------------------------------------------------------------

START_TEST(s_sscanf) {
  char str[100];
  int i, i1;
  unsigned int u, u1;
  char c, c1;
  char s[100], s1[100];
  float f, f1;
  double e, e1;
  double g, g1;
  void *p, *p1;
  int n, n1;

  strcpy(str, "A");
  s21_sscanf(str, "%c", &c);
  sscanf(str, "%c", &c1);
  ck_assert_int_eq(c, c1);

  strcpy(str, "Hello World");
  s21_sscanf(str, "%s", s);
  sscanf(str, "%s", s1);
  ck_assert_str_eq(s, s1);

  strcpy(str, "Hello World");
  s21_sscanf(str, "%10s", s);
  sscanf(str, "%10s", s1);
  ck_assert_str_eq(s, "Hello     ");

  strcpy(str, "-123");
  s21_sscanf(str, "%d", &i);
  sscanf(str, "%d", &i1);
  ck_assert_int_eq(i, i1);

  strcpy(str, "-123");
  s21_sscanf(str, "%*d");
  sscanf(str, "%*d");
  ck_assert_int_eq(i, i1);

  char str1[100];
  float float_val;
  float float_val1;

  strcpy(str, "456 3.14");
  strcpy(str1, "456 3.14");

  s21_sscanf(str, "%*d %f", &float_val);
  s21_sscanf(str1, "%*d %f", &float_val1);
  ck_assert_float_eq(float_val, float_val1);

  s21_sscanf(str, "%%");
  s21_sscanf(str1, "%%");

  strcpy(str, "+123");
  s21_sscanf(str, "%i", &i);
  sscanf(str, "%i", &i1);
  ck_assert_int_eq(i, i1);

  strcpy(str, "-123");
  s21_sscanf(str, "%i", &i);
  sscanf(str, "%i", &i1);
  ck_assert_int_eq(i, i1);

  short short_i = 0;
  short short_i1 = 0;

  strcpy(str, "123");
  s21_sscanf(str, "%hi", &short_i);
  sscanf(str, "%hi", &short_i1);
  ck_assert_int_eq(short_i, short_i1);

  long long_i = 0;
  long long_i1 = 0;

  strcpy(str, "-123");
  s21_sscanf(str, "%li", &long_i);
  sscanf(str, "%li", &long_i1);
  ck_assert_int_eq(long_i, long_i1);

  strcpy(str, "0X123");
  s21_sscanf(str, "%i", &i);
  sscanf(str, "%i", &i1);
  ck_assert_int_eq(i, i1);

  strcpy(str, "-0X123");
  s21_sscanf(str, "%i", &i);
  sscanf(str, "%i", &i1);
  ck_assert_int_eq(i, i1);

  strcpy(str, "0123");
  s21_sscanf(str, "%i", &i);
  sscanf(str, "%i", &i1);
  ck_assert_int_eq(i, i1);

  strcpy(str, "-0123");
  s21_sscanf(str, "%i", &i);
  sscanf(str, "%i", &i1);
  ck_assert_int_eq(i, i1);

  strcpy(str, "123");
  s21_sscanf(str, "%u", &u);
  sscanf(str, "%u", &u1);
  ck_assert_int_eq(u, u1);

  short short_u = 0;
  short short_u1 = 0;
  strcpy(str, "123");
  s21_sscanf(str, "%hu", &short_u);
  sscanf(str, "%hu", &short_u1);
  ck_assert_int_eq(short_u, short_u1);

  long long_u = 0;
  long long_u1 = 0;
  strcpy(str, "123");
  s21_sscanf(str, "%lu", &long_u);
  sscanf(str, "%lu", &long_u1);
  ck_assert_int_eq(long_u, long_u1);

  strcpy(str, "-3.14");
  s21_sscanf(str, "%f", &f);
  sscanf(str, "%f", &f1);
  ck_assert_float_eq(f, f1);

  strcpy(str, "+1.23e+4");
  s21_sscanf(str, "%f", &f);
  sscanf(str, "%f", &f1);
  ck_assert_float_eq(f, f1);

  strcpy(str, "1.23e-4");
  s21_sscanf(str, "%f", &f);
  sscanf(str, "%f", &f1);
  ck_assert_float_eq(f, f1);

  strcpy(str, "1.23E-4");
  s21_sscanf(str, "%f", &f);
  sscanf(str, "%f", &f1);
  ck_assert_float_eq(f, f1);

  strcpy(str, "+1.23E");
  s21_sscanf(str, "%f", &f);
  sscanf(str, "%f", &f1);
  ck_assert_float_eq(f, f1);

  strcpy(str, "1.23e+4");
  s21_sscanf(str, "%le", &e);
  sscanf(str, "%le", &e1);
  ck_assert_float_eq(e, e1);

  strcpy(str, "+1.23E-4");
  s21_sscanf(str, "%lE", &e);
  sscanf(str, "%lE", &e1);
  ck_assert_float_eq(e, e1);

  strcpy(str, "+1.23");
  s21_sscanf(str, "%lE", &e);
  sscanf(str, "%lE", &e1);
  ck_assert_float_eq(e, e1);

  strcpy(str, "-1.23e+4");
  s21_sscanf(str, "%le", &e);
  sscanf(str, "%le", &e1);
  ck_assert_float_eq(e, e1);

  strcpy(str, "-1.23E-4");
  s21_sscanf(str, "%lE", &e);
  sscanf(str, "%lE", &e1);
  ck_assert_float_eq(e, e1);

  long double long_e = 0;
  long double long_e1 = 0;

  strcpy(str, "1.23e-4L");
  s21_sscanf(str, "%Le", &long_e);
  sscanf(str, "%Le", &long_e1);
  ck_assert_float_eq(long_e, long_e1);

  strcpy(str, "1.23e+4L");
  s21_sscanf(str, "%Le", &long_e);
  sscanf(str, "%Le", &long_e1);
  ck_assert_float_eq(long_e, long_e1);

  strcpy(str, "1.23E+4L");
  s21_sscanf(str, "%LE", &long_e);
  sscanf(str, "%LE", &long_e1);
  ck_assert_float_eq(long_e, long_e1);

  strcpy(str, "1.234");
  s21_sscanf(str, "%le", &e);
  sscanf(str, "%le", &e1);
  ck_assert_float_eq(e, e1);

  strcpy(str, "+123.45");
  s21_sscanf(str, "%lg", &g);
  sscanf(str, "%lg", &g1);
  ck_assert_float_eq(g, g1);

  strcpy(str, "123");
  s21_sscanf(str, "%10lg", &g);
  sscanf(str, "%10lg", &g1);
  ck_assert_float_eq(g, g1);

  strcpy(str, "123.4");
  s21_sscanf(str, "%2lg", &g);
  sscanf(str, "%2lg", &g1);
  ck_assert_float_eq(g, 123);

  strcpy(str, "-123.45");
  s21_sscanf(str, "%lg", &g);
  sscanf(str, "%lg", &g1);
  ck_assert_float_eq(g, g1);

  strcpy(str, "+1.2E3");
  s21_sscanf(str, "%lG", &g);
  sscanf(str, "%lG", &g1);
  ck_assert_float_eq(g, g1);

  strcpy(str, "123.4");
  s21_sscanf(str, "%2lG", &g);
  sscanf(str, "%2lG", &g1);
  ck_assert_float_eq(g, 123.4);

  strcpy(str, "-1.2E3");
  s21_sscanf(str, "%lG", &g);
  sscanf(str, "%lG", &g1);
  ck_assert_float_eq(g, g1);

  long double long_g = 0;
  long double long_g1 = 0;

  strcpy(str, "1.23e-4L");
  s21_sscanf(str, "%Lg", &long_g);
  sscanf(str, "%Lg", &long_g1);
  ck_assert_float_eq(long_g, long_g1);

  strcpy(str, "1.23e+4L");
  s21_sscanf(str, "%Lg", &long_g);
  sscanf(str, "%Lg", &long_g1);
  ck_assert_float_eq(long_g, long_g1);

  strcpy(str, "1.23E-4L");
  s21_sscanf(str, "%LG", &long_g);
  sscanf(str, "%LG", &long_g1);
  ck_assert_float_eq(long_g, long_g1);

  strcpy(str, "1.23E+4L");
  s21_sscanf(str, "%LG", &long_g);
  sscanf(str, "%LG", &long_g1);
  ck_assert_float_eq(long_g, long_g1);

  int hex = 0, hex1 = 0;

  strcpy(str, "+0x1A3");
  s21_sscanf(str, "%x", &hex);
  sscanf(str, "%x", &hex1);
  ck_assert_int_eq(hex, hex1);

  strcpy(str, "+0X1A3");
  s21_sscanf(str, "%X", &hex);
  sscanf(str, "%X", &hex1);
  ck_assert_int_eq(hex, hex1);

  strcpy(str, "-0x1A3");
  s21_sscanf(str, "%x", &hex);
  sscanf(str, "%x", &hex1);
  ck_assert_int_eq(hex, hex1);

  short short_hex = 0;
  short short_hex1 = 0;

  strcpy(str, "0x1A3");
  s21_sscanf(str, "%hx", &short_hex);
  sscanf(str, "%hx", &short_hex1);
  ck_assert_int_eq(short_hex, short_hex1);

  long long_hex = 0;
  long long_hex1 = 0;

  strcpy(str, "0X1A3");
  s21_sscanf(str, "%lX", &long_hex);
  sscanf(str, "%lX", &long_hex1);
  ck_assert_int_eq(long_hex, long_hex1);

  int oct = 0, oct1 = 0;

  strcpy(str, "+075");
  s21_sscanf(str, "%o", &oct);
  sscanf(str, "%o", &oct1);
  ck_assert_int_eq(oct, oct1);

  strcpy(str, "-075");
  s21_sscanf(str, "%o", &oct);
  sscanf(str, "%o", &oct1);
  ck_assert_int_eq(oct, oct1);

  short short_oct = 0;
  short short_oct1 = 0;

  strcpy(str, "075");
  s21_sscanf(str, "%ho", &short_oct);
  sscanf(str, "%ho", &short_oct1);
  ck_assert_int_eq(short_oct, short_oct1);

  long long_oct = 0;
  long long_oct1 = 0;
  strcpy(str, "075");
  s21_sscanf(str, "%lo", &long_oct);
  sscanf(str, "%lo", &long_oct1);
  ck_assert_int_eq(long_oct, long_oct1);

  strcpy(str, "0x1234abcd");
  s21_sscanf(str, "%p", &p);
  sscanf(str, "%p", &p1);
  ck_assert_ptr_eq(p, p1);

  strcpy(str, "0X1234abcd");
  s21_sscanf(str, "%p", &p);
  sscanf(str, "%p", &p1);
  ck_assert_ptr_eq(p, p1);

  strcpy(str, "Hello123");
  s21_sscanf(str, "Hello%n", &n);
  sscanf(str, "Hello%n", &n1);
  ck_assert_int_eq(n, n1);
}
END_TEST

START_TEST(test_sscanf_width_number) {
  char str[] = "12345";
  int num = 0, num_expected = 0;

  s21_sscanf(str, "%2d", &num);
  sscanf(str, "%2d", &num_expected);

  ck_assert_int_eq(num, num_expected);
}
END_TEST

START_TEST(test_sscanf_length_h) {
  char str[] = "327";
  short num = 0, num_expected = 0;

  s21_sscanf(str, "%hd", &num);
  sscanf(str, "%hd", &num_expected);

  ck_assert_int_eq(num, num_expected);
}
END_TEST

START_TEST(test_sscanf_length_l) {
  char str[] = "2147483647";
  long num = 0, num_expected = 0;

  s21_sscanf(str, "%ld", &num);
  sscanf(str, "%ld", &num_expected);

  ck_assert_int_eq(num, num_expected);
}
END_TEST

START_TEST(test_sscanf_length_L) {
  char str[] = "21474.83647";
  long double num = 0, num_expected = 0;

  s21_sscanf(str, "%Lf", &num);
  sscanf(str, "%Lf", &num_expected);

  ck_assert_double_eq(num, num_expected);
}
END_TEST

Suite* my_string_suite(void) {
  Suite* suite = suite_create("S21_String");
  TCase* tcase = tcase_create("Core");

  tcase_add_test(tcase, s_strstr);
  tcase_add_test(tcase, s_strrchr);
  tcase_add_test(tcase, s_strcspn);
  tcase_add_test(tcase, s_memchr);
  tcase_add_test(tcase, s_memset);
  tcase_add_test(tcase, s_strchr);
  tcase_add_test(tcase, s_memcpy);
  tcase_add_test(tcase, s_strncat);
  tcase_add_test(tcase, s_strpbrk);
  tcase_add_test(tcase, s_strlen);
  tcase_add_test(tcase, s_strtok);
  tcase_add_test(tcase, s_memcmp);
  tcase_add_test(tcase, s_strncpy);
  tcase_add_test(tcase, s_strncmp);
  tcase_add_test(tcase, s_strerror);
  tcase_add_test(tcase, s_to_upper);
  tcase_add_test(tcase, s_to_lower);
  tcase_add_test(tcase, s_insert);
  tcase_add_test(tcase, s_trim);

  tcase_add_test(tcase, s_sprintf);

  tcase_add_test(tcase, s_sprintf2);

  tcase_add_test(tcase, s_sscanf);

  tcase_add_test(tcase, test_sscanf_width_number);
  tcase_add_test(tcase, test_sscanf_length_h);
  tcase_add_test(tcase, test_sscanf_length_l);
  tcase_add_test(tcase, test_sscanf_length_L);
  tcase_add_test(tcase, test_s21_strtok_end_of_string);
  tcase_add_test(tcase, test_s21_strtok_only_delimiters);
  tcase_add_test(tcase, test_s21_strtok_delimiter_at_end);
  tcase_add_test(tcase, test_s21_strtok_empty_string);
  tcase_add_test(tcase, test_s21_memcmp_less);

  suite_add_tcase(suite, tcase);
  return suite;
}
