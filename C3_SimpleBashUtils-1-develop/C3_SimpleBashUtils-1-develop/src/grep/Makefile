GCC_CFLAGS = gcc -Wall -Werror -Wextra

all: s21_grep

s21_grep: s21_grep.o 
	$(GCC_CFLAGS) s21_grep.o -o s21_grep

grep.o: s21_grep.c
	$(GCC_CFLAGS) -c s21_grep.c

test: test.sh
	chmod 777 test.sh
	./test.sh


clean:
	rm -f s21_grep.o s21_grep