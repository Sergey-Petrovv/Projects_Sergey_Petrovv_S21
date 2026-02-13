
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
SOURCES = s21_string.c test_s21.c

# Определяем платформу
UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
    CHECK_LIBS = -lcheck
    LCOV_FLAGS = --ignore-errors inconsistent,corrupt
else
    CHECK_LIBS = -lcheck -lm -lsubunit
    LCOV_FLAGS =
endif

all: s21_string.a

s21_string.o: s21_string.c s21_string.h
	$(CC) $(CFLAGS) -c s21_string.c -o s21_string.o 

test_s21.o: test_s21.c
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c test_s21.c -o test_s21.o

s21_string.a: s21_string.o 
	@ar rc s21_string.a s21_string.o 
	@ranlib s21_string.a

s21_string_test.o: s21_string.c s21_string.h
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c s21_string.c -o s21_string_test.o 

s21_string_test.a: s21_string_test.o 
	@ar rc s21_string_test.a s21_string_test.o 
	@ranlib s21_string_test.a

s21_tests : test_s21.o s21_string_test.a
	$(CC) $(CFLAGS) $(GCOV_FLAGS) main.c test_s21.o ./s21_string_test.a -o s21_tests $(CHECK_LIBS)

test: s21_tests
	@./s21_tests

gcov_report: s21_string.a test
	@./s21_tests
	
	gcov -b -l -p -c *.gcno
	gcovr --html --html-details -o gcov_report.html 

clean:
	rm -rf s21_tests
	rm -rf *.gcda *.gcno *.info *.o *.a report coverage_report *.gcov *.html *.css

clang: $(SOURCES)
	clang-format --style=Google -i *.c
