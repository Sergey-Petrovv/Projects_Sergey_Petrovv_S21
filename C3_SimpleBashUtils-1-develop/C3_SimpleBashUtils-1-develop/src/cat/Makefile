GCC_CFLAGS = gcc -Wall -Werror -Wextra

all: s21_cat

s21_cat: s21_cat.o 
	$(GCC_CFLAGS) s21_cat.o -o s21_cat

cat.o: s21_cat.c
	$(GCC_CFLAGS) -c s21_cat.c

test: test_mac.sh
	chmod 777 test_mac.sh
	./test_mac.sh

clean:
	rm -f s21_cat.o s21_cat