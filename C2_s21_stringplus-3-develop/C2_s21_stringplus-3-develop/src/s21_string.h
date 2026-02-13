#ifndef S21_STRING_H
#define S21_STRING_H

#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#define MAX_LEN 4096




char *s21_strpbrk(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, size_t n);
size_t s21_strlen(const char *str);
char *s21_strchr(const char *str, int c);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strncpy(char *dest, const char *src, size_t n);
char *s21_strncat(char *dest, const char *src, size_t n);
int s21_strcmp(const char *str1, const char *str2);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memset(void *str, int c, size_t n);
void *s21_memchr(const void *str, int c, size_t n);
size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
char *s21_strtok(char *str, const char *delim);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
int strncmp(const char *str1, const char *str2, size_t n);

int s21_sprintf(char *buffer, const char *format, ...) ;
void shortest_to_str(double value, char *buffer, int precision, char specifier);
void float_to_str(double value, char *buffer, int precision);
void uint_to_str(unsigned int value, char *buffer, int base, int uppercase);
void int_to_str(int value, char *buffer, int base, int uppercase);


typedef struct format_flags
{
    int width;
    int no_reg;
    char specifier;
    char length;

}Format_symb;



int s21_sscanf(const char *str, const char *format, ...);
void pars_format(Format_symb *ss_format, const char **c, int* current_format);
void update_ss_symb(Format_symb *ss_symbols);
void logic_specifier(Format_symb *ss_format, int *current_char, const char* str, va_list *factor, int *res);
void update_current_char(int *current_char, const char *str);
void d_flag(Format_symb *ss_format, int *current_char, const char *str, va_list *factor, int *res);
void c_flag(Format_symb *ss_format, int *current_char, const char *str, va_list *factor, int *res);
void n_flag(Format_symb *ss_format, int *current_char, va_list *factor, int *res);
void u_flag(Format_symb *ss_format, int *current_char, const char *str, va_list *factor, int *res);
void s_flag(Format_symb *ss_format, int *current_char, const char *str, va_list *factor, int *res);
void f_flag(Format_symb *ss_format, int *current_char, const char *str, va_list *factor, int *res);
void o_flag(Format_symb *ss_format, int *current_char, const char *str, va_list *factor, int *res);
void x_X_flags(Format_symb *ss_format, int *current_char, const char *str, va_list *factor, int *res);
void p_flag(Format_symb *ss_format, int *current_char, const char *str, va_list *factor, int *res);
void i_flag(Format_symb *ss_format, int *current_char, const char *str, va_list *factor, int *res);
void e_flag(Format_symb *ss_format, int *current_char, const char *str, va_list *factor, int *res);
void E_flag(Format_symb *ss_format, int *current_char, const char *str, va_list *factor, int *res);
void hex_num(Format_symb *ss_format, long long *num, const char *str, int *current_char, ...);
void g_flag(Format_symb *ss_format, int *current_char, const char *str, va_list *factor, int *res);
void G_flag(Format_symb *ss_format, int *current_char, const char *str, va_list *factor, int *res);
void oct_num(Format_symb *ss_format, long long *num, const char *str, int *current_char, ...);

void scientific_to_str(double value, char *buffer, int precision,
                       char specifier);


#endif // S21_STRING_H




